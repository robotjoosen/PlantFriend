# Plant Friend

## Parts list
- ESP32
- LDR Breakout Board
- Soil Moisture Sensor
- Push Button Breakout Board
- OLED SSD1306

## Libraries
- (ThingPulse SSD1306 Library)[https://github.com/ThingPulse/esp8266-oled-ssd1306]

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
Generating XBM files from BPMs can be done with the use of Imagick. With the following script that it can be done in bulk.

```zsh
→ magick mogrify -format xbm *.bmp
```

If you don't have (Image Magick)[https://formulae.brew.sh/formula/imagemagick] you can install this with (Homebrew)[https://brew.sh]. I have no idea how to do this with Windows...
