This is my attempt to use SD Card with ESP-CAM module under control of recent ESPHome.
ESPHome officially does not support reading nor wrinting to SD card. It is very annoying as it could be used in many occasions.
This code example is using SPI bus to access SD card slot.

So proper pinout for sdcard on this module is:

|SD Card pin (MMC naming)| GPIO number|
|--|--|
|MISO(DATA0)|GPIO2|
|CLK/SCK|GPIO14|
|MOSI(CMD)|GPIO15|
|SS/CS(DATA3)|GPIO13|
|(DATA1)|GPIO4|
|(DATA2)|GPIO12|
