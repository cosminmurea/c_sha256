#include "bit_util.h"

uint32_t convert_endianness(uint32_t value) {
    uint32_t converted = 0;
    converted |= (value & 0xFF000000) >> 24;
    converted |= (value & 0x00FF0000) >> 8;
    converted |= (value & 0x0000FF00) << 8;
    converted |= (value & 0x000000FF) << 24;
    return converted;
}

void print_endian(uint32_t value) {
    uint8_t* value_ptr = (uint8_t*)&value;
    for (size_t i = 0; i < sizeof value; i++) {
        printf("%02X", (uint8_t)value_ptr[i]);
    }
    printf("\n");
}

void print_bits(uint8_t byte) {  
    for (size_t i = 8; i > 0; i--) {
        printf("%u", (byte >> (i - 1)) & 0x01);
    }
    printf(" ");
}

void print_string_bits(const uint8_t* string, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        print_bits(string[i]);
    }
    printf("\n");
}