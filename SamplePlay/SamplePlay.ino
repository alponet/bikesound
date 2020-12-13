/*  Example of playing a sampled sound,
    using Mozzi sonification library.

    Demonstrates one-shot samples scheduled
    with EventDelay.

    Circuit: Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.1, or
    check the README or http://sensorium.github.com/Mozzi/

		Mozzi documentation/API
		https://sensorium.github.io/Mozzi/doc/html/index.html

		Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users

    Tim Barrass 2012, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <Sample.h> // Sample template
#include <EventDelay.h>
#include "bike_beat.h"

const auto sampleRate = beat_SAMPLERATE;
const auto tableSize = beat_NUM_CELLS;
const auto audioData = beat_DATA;

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <tableSize, AUDIO_RATE> aSample(audioData);

const char INPUT_PIN = 0; // set the input for the knob to analog pin 0

float baseFreq;
float sampleLength;

void setup(){
  startMozzi();
  
  baseFreq = (float) sampleRate / (float) tableSize;
  sampleLength = (float) tableSize / (float) sampleRate * 1000;
  
  aSample.setFreq(baseFreq); // play at the speed it was recorded
  aSample.setLoopingOn();
}


void updateControl(){
  int sensor_value = mozziAnalogRead(INPUT_PIN); // value is 0-1023

  float speed = (((float)sensor_value / 682) + 0.5);
  float currentFreq = speed * baseFreq;

  aSample.setFreq(currentFreq);
}


int updateAudio(){
  return (int) aSample.next();
}


void loop(){
  audioHook();
}
