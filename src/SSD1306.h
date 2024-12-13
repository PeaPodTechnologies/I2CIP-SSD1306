#ifndef I2CIP_SSD1306_H_
#define I2CIP_SSD1306_H_

#include <Arduino.h>
#include <I2CIP.h>

// MACROS

#define SSD1306_MEMORYMODE 0x20          ///< See datasheet
#define SSD1306_COLUMNADDR 0x21          ///< See datasheet
#define SSD1306_PAGEADDR 0x22            ///< See datasheet
#define SSD1306_SETCONTRAST 0x81         ///< See datasheet
#define SSD1306_CHARGEPUMP 0x8D          ///< See datasheet
#define SSD1306_SEGREMAP 0xA0            ///< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SSD1306_DISPLAYALLON 0xA5        ///< Not currently used
#define SSD1306_NORMALDISPLAY 0xA6       ///< See datasheet
#define SSD1306_INVERTDISPLAY 0xA7       ///< See datasheet
#define SSD1306_SETMULTIPLEX 0xA8        ///< See datasheet
#define SSD1306_DISPLAYOFF 0xAE          ///< See datasheet
#define SSD1306_DISPLAYON 0xAF           ///< See datasheet
#define SSD1306_COMSCANINC 0xC0          ///< Not currently used
#define SSD1306_COMSCANDEC 0xC8          ///< See datasheet
#define SSD1306_SETDISPLAYOFFSET 0xD3    ///< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5  ///< See datasheet
#define SSD1306_SETPRECHARGE 0xD9        ///< See datasheet
#define SSD1306_SETCOMPINS 0xDA          ///< See datasheet
#define SSD1306_SETVCOMDETECT 0xDB       ///< See datasheet

#define SSD1306_SETLOWCOLUMN 0x00  ///< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE 0x40  ///< See datasheet

#define SSD1306_EXTERNALVCC 0x01  ///< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             ///< Set scroll range

#define I2CIP_SSD1306_ADDRESS 0x3C // Default
// #define I2CIP_SSD1306_DELAY 10 // Write/Read Sensing Delay
#define I2CIP_SSD1306_WIDTH 128
#define I2CIP_SSD1306_HEIGHT 64

const size_t _i2cip_ssd1306_size_default_bytes = (I2CIP_SSD1306_WIDTH * I2CIP_SSD1306_HEIGHT) / 8;

class SSD1306 : public I2CIP::Device, public OutputInterface<uint8_t*, size_t> {
public:
  SSD1306(const i2cip_fqa_t& fqa, const i2cip_id_t& id);
  SSD1306(const i2cip_fqa_t& fqa);

  static Device* ssd1306Factory(const i2cip_fqa_t& fqa, const i2cip_id_t& id);

  static Device* ssd1306Factory(const i2cip_fqa_t& fqa);

  // i2cip_errorlevel_t clear(bool setbus = true) {
  //   return writeRegister((uint8_t)0x00, (uint8_t)0x00, setbus);
  // }

  // i2cip_errorlevel_t display(bool setbus = true) {
  //   return writeRegister((uint8_t)0x00, (uint8_t)0x01, setbus);
  // }

  // i2cip_errorlevel_t setContrast(uint8_t contrast, bool setbus = true) {
  //   return writeRegister((uint8_t)0x81, contrast, setbus);
  // }

  // i2cip_errorlevel_t setDisplayOn(bool setbus = true) {
  //   return writeRegister((uint8_t)0xAF, (uint8_t)0x00, setbus);
  // }

  // i2cip_errorlevel_t setDisplayOff(bool setbus = true) {
  //   return writeRegister((uint8_t)0xAE, (uint8_t)0x00, setbus);
  // }

  i2cip_errorlevel_t set(uint8_t* const& buf, const size_t& len);

  const size_t& getDefaultB(void) const override;

  static const char* getStaticIDBuffer();
};

#endif