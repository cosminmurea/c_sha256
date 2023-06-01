#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mem_util.h"

/**
 * @brief               Computes the size in bytes of a file. Does not handle the opening / closing of the file.
 * @param file_ptr      A pointer to an open file.
 * @return size_t       The size in bytes of the given file.
 */
size_t file_size(FILE* file_ptr);

/**
 * @brief               Read the contents of a file byte by byte into an array. After reading the file is closed.
 *                      It is the callers responsability to free the memory allocated for the byte array.
 *                      Exits with status 1 if the file could not be opened or if there was an error while reading from it.
 * @param file_path     The path to the file as a string.
 * @param buffer        The byte array - passed by reference.
 * @param file_length   The length of the file in bytes - passed by reference.
 */
void read_file_bytes(const char* file_path, uint8_t** buffer, size_t* file_length);

#endif