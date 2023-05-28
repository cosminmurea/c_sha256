#ifndef SHA256_H
#define SHA256_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void print_bits(uint8_t byte);
void print_string_bits(const uint8_t* string, size_t length);
uint32_t convert_endianness(uint32_t little_endian);
void print_endian(uint32_t value);
uint8_t* read_file_bytes(const char* file_path);

#endif
