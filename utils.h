#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void* safe_malloc(size_t size);
FILE* safe_fopen(const char* file_path, const char* mode);
uint8_t* hex_string_to_byte_array(char* hex_string, size_t length);

#endif