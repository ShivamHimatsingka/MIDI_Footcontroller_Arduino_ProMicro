# MIDI_Footcontroller_Arduino_ProMicro
This is the code for making a MIDI controller which sends PC messages via USB on Arduino Pro Micro. The code can be used on any Arduino board with native USB compatibility (eg: Pro Micro, Leonardo).

How to use:
1) Connect 8 MOMENTARY switches to Digital Pins 2-9 on the Arduino.
2) Download MidiFootcontroller.ino and install Arduino IDE.
3) Connect the Arduino board to your computer.
4) Open MidiFootcontroller.ino in Arduino IDE.
5) Change the board in Arduino IDE to whichever board you have.
6) Upload the code.
7) When you press a switch, a PC MIDI message will be sent to your computer. In your DAW/application, click MIDI Learn, and press a switch to assign the control.

Debugging:
Incase the program doesn't work as expected, go through the following-
1) Check whether your Arduino board has Native USB compatibility. Boards like Uno and Mega will not work. Suggested board is the Pro Micro.
2) Go through the code and change the MIDI channel if requiered.
3) Install MIDI Monitor to check if the computer is reveiving a MIDI signal when the button is pressed.
