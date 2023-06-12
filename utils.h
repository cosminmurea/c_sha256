#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void* safe_malloc(size_t size);
void read_file_bytes(const char* file_path, uint8_t** buffer, size_t* file_length);
void write_file_bytes(const char* file_path, uint32_t* buffer, size_t buffer_length);

#endif