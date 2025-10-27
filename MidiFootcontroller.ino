    #include <MIDIUSB.h> // For USB MIDI communication
    const int buttonPin1 = 2; // Example: Connect footswitch 1 to digital pin 2
    const int buttonPin2 = 3; // Example: Connect footswitch 2 to digital pin 3
    const int buttonPin3 = 4;
    const int buttonPin4 = 5;
    const int buttonPin5 = 6;
    const int buttonPin6 = 7;
    const int buttonPin7 = 8;
    const int buttonPin8 = 9;
    // ... define more pins for additional footswitches

    const byte midiChannel = 1; // MIDI channel (1-16)
    const byte programChange1 = 0; // Program Change number for footswitch 1 (0-127)
    const byte programChange2 = 1; // Program Change number for footswitch 2
    const byte programChange3 = 2;
    const byte programChange4 = 3;
    const byte programChange5 = 4;
    const byte programChange6 = 5;
    const byte programChange7 = 6;
    const byte programChange8 = 7;
    // ... define more program change numbers or control change numbers
    void setup() {
      pinMode(buttonPin1, INPUT_PULLUP); // Configure button pins with internal pull-up resistors
      pinMode(buttonPin2, INPUT_PULLUP);
      pinMode(buttonPin3, INPUT_PULLUP);
      pinMode(buttonPin4, INPUT_PULLUP);
      pinMode(buttonPin5, INPUT_PULLUP);
      pinMode(buttonPin6, INPUT_PULLUP);
      pinMode(buttonPin7, INPUT_PULLUP);
      pinMode(buttonPin8, INPUT_PULLUP);
      // ... setup more button pins
      Serial.begin(9600); // Optional: for debugging
    }
    void loop() {

      // Read the state of each button
      if (digitalRead(buttonPin1) == LOW) { // Button is pressed (LOW when using INPUT_PULLUP)
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange1}; // Program Change message
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush(); // Send the MIDI message
        delay(400); // Debounce delay
        while (digitalRead(buttonPin1) == LOW); // Wait for button release
      }

      if (digitalRead(buttonPin2) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange2};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin2) == LOW);
      }

      if (digitalRead(buttonPin3) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange3};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin3) == LOW);
      }

      if (digitalRead(buttonPin4) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange4};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin4) == LOW);
      }

      if (digitalRead(buttonPin5) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange5};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin5) == LOW);
      }

      if (digitalRead(buttonPin6) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange6};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin6) == LOW);
      }

      if (digitalRead(buttonPin7) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange7};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin7) == LOW);
      }

      if (digitalRead(buttonPin8) == LOW) {
        midiEventPacket_t programChangeMessage = {0x0C, 0xC0 | midiChannel, programChange8};
        MidiUSB.sendMIDI(programChangeMessage);
        MidiUSB.flush();
        delay(400);
        while (digitalRead(buttonPin8) == LOW);
      }
      // ... add similar logic for other footswitches
    }
    void sendControlChange(byte control, byte value, byte channel) {
      midiEventPacket_t event = {0x0B, 0xB0 | (channel - 1), control, value};
      MidiUSB.sendMIDI(event);
      MidiUSB.flush();
    }
