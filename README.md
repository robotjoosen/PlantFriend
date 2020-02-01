# Plant Friend
Plant Friend is your plant companion to keep your plants from dying.

## Parts
All parts i have are bought from AliExpress. The LDR and Pushbutton came with a 37 in 1 sensor kit. Although i have to say that the labelling is totally messed up on the breakout boards (S = 3.3V, - = Signal, + = Ground). So if you buy one double check the board.

- [ESP32](https://nl.aliexpress.com/item/32835521420.html)
- [Soil Moisture Sensor](https://nl.aliexpress.com/item/1830729489.html)
- [LDR Breakout Board](https://nl.aliexpress.com/item/32826716396.html)
- [Push Button Breakout Board](https://nl.aliexpress.com/item/32826716396.html)
- [OLED SSD1306](https://nl.aliexpress.com/item/32697467585.html)

## Hooking everything up
| Part | Name | Label | Port |
| --- | --- | --- | -- |
| SSD1306 | Input Voltage | 3.3V | 3.3V |
| | Ground | GND | GND |
| | Clock | SCL | 22 |
| | Serial Data | SDA |  21 |
| LDR | Input Voltage | + | 3.3V |
| | Output Voltage | S | 34 |
| | Ground | - | GND |
| Push button | Input Voltage | + | 3.3V |
| | Output Voltage | S | 13 |
| | Ground | - | GND |
| Soil moisture sensor | Input Voltage | + | 3.3V |
| | Output Voltage | S | 15 |
| | Ground | - | GND |

* keep in mind the labelling is messed up on my sensors, so if you use the same don't look at the labels.

## Libraries
- [ThingPulse SSD1306 Library](https://github.com/ThingPulse/esp8266-oled-ssd1306)

## ESP32 Upload settings
These settings are what i currently use for uploading. I'm not sure if this is the best, but works.

| Setting | Value |
| --- | --- |
| Board | ESP32 Dev Module |
| Upload | 921600 |
| CPU Frequency | 240MHz (WiFi/BT) |
| Flash Frequency | 80MHz |
| Flash Mode | QIO |
| Flash Size | 4MB (32Mb) |
| Partition Scheme | Default 4MB with spiffs (1.2 MB APP/1.5MB SPIFFS) |
| Core Debug Level | None |
| PSRAM | Disabled |

## Generate XBM files from BMP
If you want to add different sprites you can easily convert you BMPs to XBM files. Generating XBM files from BPMs can be done with the use of Imagick. With the following script that it can be done in bulk.

```zsh
→ magick mogrify -format xbm *.bmp
```

If you don't have [Image Magick](https://formulae.brew.sh/formula/imagemagick) you can install this with [Homebrew](https://brew.sh). I have no idea how to do this with Windows...
