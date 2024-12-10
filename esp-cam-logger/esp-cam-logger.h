#include "esphome.h"

#include "FS.h"
#include "SPI.h"
#include "SD.h"

// esp-cam:
#define SS      13
#define SCK     14
#define MOSI    15
#define MISO    2

const uint8_t SD_SCK_PIN  = 14;
const uint8_t SD_MISO_PIN = 2;
const uint8_t SD_MOSI_PIN = 15;
const uint8_t SD_CS_PIN = 13;

SPIClass *SPI2=NULL;
File myFile;

void chksd(){
  SPI2 = new SPIClass(HSPI);
  SPI2->begin(SD_SCK_PIN, SD_MISO_PIN, SD_MOSI_PIN, SD_CS_PIN);
  if (!SD.begin(SD_CS_PIN, *SPI2)){
      ESP_LOGW("sd","SD Initialization failed!"); 
  } else {
      ESP_LOGW("sd","SD Init _OK_"); 
  }

  ESP_LOGW("sd","Append to /example.txt...");
  myFile = SD.open("/example.txt", FILE_APPEND);
  myFile.seek(0,SeekEnd);
  myFile.write((const uint8_t*)"file contents test\r\n",12);
  myFile.flush();
  myFile.close();
}
