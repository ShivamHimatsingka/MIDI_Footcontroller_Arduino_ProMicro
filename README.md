# MIDI Footcontroller (Arduino Pro Micro)

![Arduino](https://img.shields.io/badge/Arduino-00878F?logo=arduino&logoColor=white)
![Board](https://img.shields.io/badge/board-Pro%20Micro%20%7C%20Leonardo-blue)
![MIDI](https://img.shields.io/badge/MIDI-USB%20class--compliant-orange)
![License](https://img.shields.io/badge/license-MIT-green)

A simple, driver-free **8-button USB MIDI foot controller** built on an Arduino Pro Micro.
Each footswitch sends a **MIDI Program Change (PC)** message over USB, so you can switch
presets, scenes or patches in your DAW, amp sim or plugin host.

The board shows up as a class-compliant USB MIDI device. You don't need any drivers or a
serial-to-MIDI bridge on macOS, Windows or Linux.

---

## Features

- 8 momentary footswitches → 8 Program Change messages (PC 0–7)
- Native USB MIDI via the [MIDIUSB](https://github.com/arduino-libraries/MIDIUSB) library
- Uses the internal pull-up resistors, so you don't need extra resistors
- One message per press, with debounce and wait-for-release
- Includes a `sendControlChange()` helper if you want CC messages instead

## Hardware

| Part | Qty | Notes |
| --- | --- | --- |
| Arduino Pro Micro (ATmega32U4) | 1 | Arduino Leonardo / Micro also work |
| Momentary footswitch (SPST, normally open) | 8 | Use **momentary** switches, not latching |
| Enclosure, wire, USB cable | – | Any sturdy box will do |

> ⚠️ The board **must have native USB** (ATmega32U4 or similar). Boards like the
> Arduino **Uno** and **Mega** will **not** work with this sketch.

### Wiring

Wire one leg of each switch to its digital pin and the other leg to **GND**.

| Footswitch | Pin | Program Change sent |
| :---: | :---: | :---: |
| 1 | D2 | 0 |
| 2 | D3 | 1 |
| 3 | D4 | 2 |
| 4 | D5 | 3 |
| 5 | D6 | 4 |
| 6 | D7 | 5 |
| 7 | D8 | 6 |
| 8 | D9 | 7 |

```
  Pro Micro                Footswitch
  ┌────────┐
  │   D2 ──┼───────────────o  o──┐
  │        │                     │
  │  GND ──┼─────────────────────┘
  └────────┘
  (repeat for D3–D9; all switches can share one GND wire)
```

## Installation

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the **MIDIUSB** library: *Sketch → Include Library → Manage Libraries…*, search for
   `MIDIUSB` and install it.
3. Clone or download this repo and open `MidiFootcontroller.ino`. If the IDE asks to move the
   sketch into a folder named `MidiFootcontroller`, click **OK**.
4. Connect your board via USB and select it under *Tools → Board*
   (e.g. **Arduino Leonardo** for a Pro Micro, or the SparkFun Pro Micro board package).
5. Pick the correct port under *Tools → Port* and click **Upload**.

## Usage

1. Plug the controller into your computer. It appears as a USB MIDI input device.
2. In your DAW or application, enable the device as a MIDI input.
3. Use **MIDI Learn** (or the app's PC mapping) and press a footswitch to assign it.

Works with Logic Pro, Ableton Live, Reaper, Cubase, Neural DSP plugins, Guitar Rig,
Gig Performer, MainStage and most other software that accepts Program Change messages.

## Configuration

All settings are at the top of `MidiFootcontroller.ino`:

```cpp
const int  buttonPin1     = 2;  // pin for footswitch 1
const byte midiChannel    = 1;  // MIDI channel value
const byte programChange1 = 0;  // PC number for footswitch 1 (0–127)
```

- **Program numbers.** Change `programChange1` … `programChange8` to any value from 0 to 127.
- **MIDI channel.** The status byte is built as `0xC0 | midiChannel`, so the value is
  *zero-based*: `0` = channel 1, `1` = channel 2, … `15` = channel 16.
  The default (`1`) sends on **MIDI channel 2**.
- **Debounce.** Each press is followed by a `delay(400)`. Lower it for faster switching,
  or raise it if you see double triggers.
- **Control Change.** To send CC instead of PC, call
  `sendControlChange(control, value, channel)` in place of the Program Change block.
  This helper takes a 1-based channel (1–16).

## Troubleshooting

| Problem | Fix |
| --- | --- |
| Board isn't detected as MIDI | Make sure it's a native-USB board (Pro Micro / Leonardo / Micro), not an Uno or Mega. |
| Compile error `MIDIUSB.h: No such file` | Install the **MIDIUSB** library (see Installation). |
| Nothing happens in the DAW | Check the device is enabled as a MIDI input and listening on the right channel (see *MIDI channel* above). |
| Not sure if messages are sent | Use a MIDI monitor ([MIDI Monitor](https://www.snoize.com/midimonitor/) on macOS, [MIDI-OX](http://www.midiox.com/) on Windows) to watch incoming messages. |
| Switch triggers twice | Increase the debounce `delay()` value. |
| Switch always "pressed" | You probably used a latching or normally-closed switch. Use momentary, normally-open switches. |

## License

Released under the [MIT License](LICENSE).
