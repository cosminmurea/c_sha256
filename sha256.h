#ifndef SHA256_H
#define SHA256_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_bits(uint8_t byte);
void print_string_bits(const char* string, size_t length);
uint32_t convert_endianness(uint32_t little_endian);
void print_endian(uint32_t value);

#endif
