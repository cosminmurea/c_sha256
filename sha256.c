#include "sha256.h"

void print_endian(uint32_t value) {
    uint8_t* value_ptr = (uint8_t*)&value;
    for (size_t i = 0; i < sizeof value; i++) {
        printf("%02X", (uint8_t)value_ptr[i]);
    }
    printf("\n");
}

uint32_t convert_endianness(uint32_t little_endian) {
    uint32_t big_endian = 0;
    big_endian |= (little_endian & 0xFF000000) >> 24;
    big_endian |= (little_endian & 0x00FF0000) >> 8;
    big_endian |= (little_endian & 0x0000FF00) << 8;
    big_endian |= (little_endian & 0x000000FF) << 24;
    return big_endian;
}

void print_bits(uint8_t byte) {  
    for (size_t i = 8; i > 0; i--) {
        printf("%u", (byte >> (i - 1)) & 0x01);
    }
    printf(" ");
}

void print_string_bits(const char* string, size_t length) {
    for (size_t i = 0; i < length; i++) {
        print_bits((const uint8_t)string[i]);
    }
    printf("\n");
}

int main() {
    char string[5] = "aaa";
    print_string_bits(string, strlen(string));
    uint32_t hex = 0xAABBCCDD;
    printf("Saved in memory as : ");
    print_endian(hex);
    printf("Converted : ");
    print_endian(convert_endianness(hex));
    return 0;
}
