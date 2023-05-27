#include "sha256.h"

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

    return 0;
}
