# teensy-dual-joysticks

Gameport joystick USB adapter project.

A Teensy LC is used to read gameport joystick inputs. 

Default USB interface code is modified so that the Teensy is detected as two separate joysticks.

Usage:
- Back up Teensyduino install hardware folder.
- Copy the hardware directory into the Teensyduino install folder, replacing the existing files.
- Open DualJoysticks.ino in the Arduino IDE.
- Select the new USB Type "Dual Joysticks".

---
Wiring diagram:

![Wiring diagram](https://raw.githubusercontent.com/psaikko/teensy-dual-joysticks/master/img/wiring.png)

Additional analog and digital inputs can be connected to the Teensy as needed (simple gameport devices support 4 buttons and 4 axes each).
