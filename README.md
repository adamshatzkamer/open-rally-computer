# Open Rally Computer

An open source tripmaster for navigation rallies

![Open Rally Computer](img/orc.png?raw=true "Open Rally Computer")

## Description

The Open Rally Computer (previously known as [Baja Pro](https://baja.matto.io/)) is a complete tripmaster for navigation rallies.

Some of its features are:

- Based on GPS technology
- Adjustable partial distance odometer
- Total distance odometer
- Speedometer
- Average speed
- Max speed
- Trip time
- Compass (CAP heading)
- Multiple languages and unit systems
- Firmware updates over-the-air

The main goal of this project is to achieve a widely used open-source device that can be improved over time by ourselves, the pilots behind the roadbook.

You can read a detailed writeup of the project here:

- [English version](https://matto.io/open-sourcing-the-baja-pro/)
- [Spanish version](https://matto.io/liberando-el-codigo-del-baja-pro/)

## Schematics and PCB

You can find all the necessary information for fabricating your own copy of the Open Rally Computer PCB in the [pcb](docs/pcb) and [schematics](docs/schematics) folders of this repository.

> **HELP NEEDED**: My knowledge in electronics is self-taught, so I'm sure there are quite a few improvements to be done in this department. If you know electronics and spot something that can be improved, please let me know by opening an issue.

- Previous models of this device have been fabricated at [JLCPCB](https://jlcpcb.com/) with great results and very good prices.
- The system I used to create the PCB was [EasyEDA](https://easyeda.com/). You can find files for the schematics and the PCB in their relative folders. There are also versions for Altium Designer.

> **HELP NEEDED**: I'd like to port these schematics and PCB to KiCad, so we continue with the open source spirit :)
>
> If you know your way around KiCad, I'd really appreciate some help porting this board.

The bill of materials is located in a CSV file in the [bom](docs/pcb/bom) folder. If you find a missing component, please report it by opening an issue.

## User manual

You can find a PDF version of the User Manual in the [manual](docs/manual) folder.

> **HELP NEEDED**: The user manual is currently only in Spanish and it still has a lot of Baja Pro branding that has to be changed to "Open Rally Computer". I'd really appreciate some help transcribing it to Markdown and translating it into other languages, being english the top priority right now.

## Getting Started

These instructions will allow you to compile the project in you local computer. In order to run it you will need an actual device.

### Prerequisites

This project has been developed using VSCode with the PlatformIO plugin, which is is the recommended setup.

- Install [VSCode](https://code.visualstudio.com/)
- Install the [PlatformIO plugin](https://platformio.org/install/ide?install=vscode)
- Clone this repository

```bash
git clone https://github.com/mattogodoy/open-rally-computer.git
```

### Building

To build this project you can open the directory of the repository you just downloaded in VSCode.

Once open, go to the sidebar at the left, PlatformIO -> esp32dev -> General -> Build

The required libraries are already bundled in the `lib` directory of this repo. PlatformIO will automatically try to use them.
If for some reason you are getting compilation errors because of missing libraries, you can always install them manually going to PlatformIO -> PIO Home -> Libraries.

You can find the list of necessary libraries in the file [platformio.ini](platformio.ini).

## Flashing into device

Once the project compiles correctly in your computer, you are ready to flash it into the rally computer.

1. Connect your ESP32 (DevKit or programmer) to your computer via USB.
2. Go to PlatformIO -> esp32dev -> General -> Upload
3. PlatformIO should automatically detect the serial port where your ESP32 is connected, buld the project and flash it for you.

## Feather and FeatherWing Compatibility

This version of the Open Rally Computer has been updated to support Adafruit Feather boards and FeatherWings, making it easier to assemble with off-the-shelf components. The recommended hardware includes:

### Required Hardware

1. **Adafruit HUZZAH32 (ESP32 Feather Board)**
   - [Product Link](https://www.adafruit.com/product/3405)
   - A powerful microcontroller with WiFi and Bluetooth capabilities.

2. **Adafruit TFT FeatherWing - 3.5" 480x320 Touchscreen (V2 with TSC2007)**
   - [Product Link](https://www.adafruit.com/product/3651)
   - A plug-and-play FeatherWing with a vibrant touchscreen display.

3. **Adafruit Ultimate GPS FeatherWing**
   - [Product Link](https://www.adafruit.com/product/3133)
   - Provides GPS functionality for accurate navigation.

4. **External GPS Antenna (Recommended)**
   - [Product Link](https://www.adafruit.com/product/960)
   - Improves GPS signal reception, especially when the Feather stack blocks the internal antenna.

5. **Buttons and LEDs**
   - Three tactile buttons for navigation (Previous, Select, Next).
   - Three LEDs for Power, GPS Lock, and Status/Activity indicators.

### Wiring Instructions

- The FeatherWing display and GPS FeatherWing stack directly onto the HUZZAH32.
- Buttons and LEDs connect to the following GPIO pins:
  - **Buttons**: GPIO 32 (Previous), GPIO 33 (Select), GPIO 34 (Next)
  - **LEDs**: GPIO 2 (Power), GPIO 4 (GPS Lock), GPIO 19 (Status/Activity)
- External GPS antenna connects to the GPS FeatherWing's SMA connector.

### Assembly Notes

- Ensure all FeatherWings are securely stacked and aligned.
- Use short jumper wires for buttons and LEDs to minimize clutter.
- Power the system via USB or a LiPo battery connected to the HUZZAH32.

### Software Setup

- Install the required libraries for the TFT FeatherWing and GPS FeatherWing:
  - Adafruit_GFX
  - Adafruit_HX8357
  - TinyGPS++
- Follow the instructions in the `platformio.ini` file to configure the project for the HUZZAH32.

This setup provides a beginner-friendly way to build the Open Rally Computer with minimal soldering and wiring. Let us know if you have any questions or suggestions by opening an issue!

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on the process for submitting pull requests.

Also read [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) for details on the code of conduct for this project.

## Versioning

We use [SemVer](http://semver.org/) for versioning.

For a list of available versions, see the [tags on this repository](https://github.com/mattogodoy/open-rally-computer/tags).

## Authors

- **Matías Godoy** - [matto.io](https://matto.io/)

See also the list of [contributors](https://github.com/mattogodoy/open-rally-computer/graphs/contributors) who participated in this project.

## TO-DO

There are a few things I'd like to do in order to improve this project and its repository:

- [x] Build, upload and tag Version 1.0.0 binary as a release
- [x] Translate user manual to english
- [ ] Port the PCB files to KiCad
- [ ] Create proper documentation in GitHub Wiki
- [ ] Create Continuous Integration using GitHub Actions

## License

This project is licensed under the GPL v3 License - see the [LICENSE](LICENSE) file for details.

This is what this means:

1. Anyone can copy, modify and distribute this software.
2. If you do, you have to include the license and copyright notice with each and every distribution.
3. You can use this software privately.
4. You can use this software for commercial purposes.
5. If you build your business based on this code, you have to open-source your whole code base.
6. Any modifications of this code base MUST be distributed with the same license (GPL v3).
7. Any changes made to this code MUST be indicated on distribution.
8. This software is provided without warranty.
9. The software author or license can not be held liable for any damages inflicted by the software.

## Changelog

- **1.0.0**: Initial version
  - The complete project was open sourced, including source code, bill of materials, PCB desings and user manual.

## Contributors

- [turtle3333](https://github.com/turtle3333): User manual translation
