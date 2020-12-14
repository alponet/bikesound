# bikesound

a sample player for Arduino/MozziByte, the analog input modulates the playback speed

### Convert Audio to Mozzi-Header
- install mozzi-library via arduino IDE
- locate Arduino/libraries/Mozzi/extras/python/ (inside $HOME for Debian Linux)
- for use with audio2huff.py consult the readme provided by mozzi-library (note that the compressed audio won't be manipulatable in pitch etc. anymore)


#### For use with char2mozzi.py script for manipulatable audio
- choose a (very small/short) Sample (it shouldn't exceed 0.5s for a standard wav-file)
- Low-pass it at around 4kHz to get rid of aliasing as we gonna convert it to 8000 Hz samplerate
- to get longer samples working: play back the audio twice as fast or faster inside any DAW and export it (& slow it down again on the mozzi-board later)
- Convert it to RAW-Format via Audacity
  - open file in audacity
  - set project-samplerate to 8000 Hz (prevents ugly noise when playing back on mozzi-board)
  - file &rarr; export &rarr; export wav
  -  choose "other uncompressed data" 
  -  choose "RAW (header-less)" & "signed 8-bit PCM"
  -  export it 

- copy .RAW-file into python-folder of your arduino IDE

`char2mozzi.py <infile outfile tablename samplerate>`
