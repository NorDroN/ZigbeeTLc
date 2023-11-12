#pragma once

/* Universal I2C/SMBUS read-write transaction struct */
typedef struct _i2c_utr_t {
	unsigned char mode;  // bit0..6: The byte number of the record for the new START (bit7: =1 - generate STOP/START)
	unsigned char rdlen; // bit0..6: Number of bytes read (bit7: =0 - the last byte read generates NACK, =1 - ACK)
	unsigned char wrdata[1]; // Array, the first byte is the address, then the bytes to write to the bus: i2c_addr_wr, wr_byte1, wr_byte2, wr_byte3, ... wr_byte126
} i2c_utr_t;

void init_i2c(void);
unsigned char test_i2c_device(unsigned char address);
int send_i2c(unsigned char i2c_addr, unsigned char * dataBuf, size_t dataLen);
int send_i2c_byte(unsigned char i2c_addr, unsigned char cmd);
int I2CBusUtr(void * outdata, i2c_utr_t *tr, unsigned int wrlen);