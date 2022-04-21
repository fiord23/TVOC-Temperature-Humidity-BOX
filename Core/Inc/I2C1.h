// init I2C1
#ifndef __I2C1_H
#define __I2C1_H

void i2c1_init();
uint8_t i2c1_read(uint8_t , uint8_t);
void i2c1_write (uint8_t, uint8_t, uint8_t);
#endif //I2C1