# Timer System with Audio Playback

This project is an Arduino-based timer system designed to help users set timers using button inputs and play audio feedback using the DFPlayer Mini module. The timer is customizable using two buttons, one for adding 60 seconds and another for adding 30 seconds. After setting the desired time, pressing the start button initiates the timer, and an audio track from the SD card starts playing. The audio stops when the timer finishes. **This project does not use Bluetooth; audio files are stored on an SD card.**

## Features
- **Customizable Timer**: Set the timer by pressing buttons. Each press of the 60-second button adds 60 seconds, and each press of the 30-second button adds 30 seconds. For example, to set a timer for 2 minutes and 30 seconds, press the 60-second button twice and the 30-second button once.
- **Audio Playback**: When the timer starts, audio plays from the SD card using the DFPlayer Mini module. The audio stops automatically when the timer ends.
- **Simple Operation**: The system uses physical buttons for timer input and serial output for monitoring the timer progress during debugging.
- **No Bluetooth Required**: Audio files are stored on an SD card and played via the DFPlayer Mini, removing the need for any Bluetooth functionality.

## Components
- **Arduino**: Microcontroller responsible for managing the button inputs, timer, and controlling the audio playback.
- **DFPlayer Mini Module**: A small MP3 player module used to play audio files stored on an SD card.
- **Buttons**: Two buttons are used to set the timer duration (one adds 60 seconds, the other adds 30 seconds), and another button is used to start the timer.
- **Speaker**: Connects to the DFPlayer Mini to output audio.

## How It Works
1. **Setting the Timer**: Use the two buttons to set the timer by adding increments of 60 seconds and 30 seconds. For example, if you want to set a timer for 2 minutes and 30 seconds, press the 60-second button twice and the 30-second button once.
2. **Starting the Timer**: Press the start button after setting the timer. The timer will begin counting down, and the audio file will start playing.
3. **Timer Completion**: When the timer finishes, the audio playback will stop automatically.

## How to Use
1. **Upload the Code**: Flash the Arduino code onto your microcontroller.
2. **Connect the Components**: Wire the DFPlayer Mini, buttons, and speaker to the Arduino as specified in the code.
3. **Prepare Audio Files**: Load MP3 files onto an SD card and insert it into the DFPlayer Mini module. The files should be named in numerical order (e.g., 0001.mp3).
4. **Test the System**: Set the desired time using the buttons, then press the start button to begin the timer and hear the audio play.

## Future Improvements
- Add additional buttons or input methods for more precise time adjustments.
- Include a display or LED to show the remaining time.

## License
This project is open-source and can be used or modified under [license details].
