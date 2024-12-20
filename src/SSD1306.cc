#include <SSD1306.h>

I2CIP_DEVICE_INIT_STATIC_ID(SSD1306);
// I2CIP_DEVICES_INIT_PROGMEM_ID(SSD1306);

SSD1306::SSD1306(i2cip_fqa_t fqa, const i2cip_id_t& id) : I2CIP::Device(fqa, id), I2CIP::OutputInterface<uint8_t*, size_t>((I2CIP::Device*)this) { }

i2cip_errorlevel_t SSD1306::set(uint8_t* const& buf, const size_t& len) {
  // i2cip_errorlevel_t errlev = setDisplayOff();
  // I2CIP_ERR_BREAK(errlev);

  // errlev = write(buf, len, false);
  // I2CIP_ERR_BREAK(errlev);

  // return setDisplayOn(false);
  // i2cip_errorlevel_t errlev = writeByte(0x00, false);
  // I2CIP_ERR_BREAK(errlev);
  uint8_t temp[5] = {SSD1306_PAGEADDR, 0, 0xFF, SSD1306_COLUMNADDR, 0}; size_t templen = 5;
  i2cip_errorlevel_t errlev = writeRegister((uint8_t)(0x00), temp, templen, true);
  I2CIP_ERR_BREAK(errlev);
  if(templen != 5) return I2CIP::I2CIP_ERR_SOFT;
  errlev = writeRegister((uint8_t)(0x00), (uint8_t)(I2CIP_SSD1306_WIDTH - 1), false);
  I2CIP_ERR_BREAK(errlev);
  size_t pos = 0;
  while(pos < len) {
    uint8_t reg = 0x40 + pos;
    uint8_t page[I2CIP_MAXBUFFER-2] = {0}; size_t pagelen = 0;
    for(size_t i = 0; i < I2CIP_MAXBUFFER-2; i++) {
      if(pos >= len) break;
      page[i] = buf[pos++];
      pagelen++;
    }
    errlev = writeRegister(reg, page, pagelen, false);
    I2CIP_ERR_BREAK(errlev);
  }
  return I2CIP::I2CIP_ERR_NONE;
}