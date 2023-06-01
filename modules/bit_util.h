#ifndef BIT_UTIL_H
#define BIT_UTIL_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief               Converts little-endian values to big-endian and vice-versa. Only works for 32 bit values.
 * @param value         The 32 bit value to be converted. A little-endian value will generate a big-endian return value and vice-versa.
 * @return uint32_t     The 32 bit converted value.
 */
uint32_t convert_endianness(uint32_t value);

/**
 * @brief               Prints a 32 bit value byte by byte, according to where it is stored in memory.
 *                      Starting from the lowest memory address up to the highest.
 * @param value         The 32 bit value to be printed.
 */
void print_endian(uint32_t value);

/**
 * @brief               Prints individual bytes as bits. The bits are grouped together but each byte is separated by a space.
 * @param byte          The byte to be printed.
 */
void print_bits(uint8_t byte);

/**
 * @brief               Prints entire array of bytes as sequences of 8 bit groups.
 *                      The bytes are separated by spaces and there are only 10 bytes per line.
 * @param string        The array of bytes to be printed. No null-terminator is needed.
 * @param length        The length of the array.
 */
void print_string_bits(const uint8_t* string, size_t length);

#endif