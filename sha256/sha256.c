#include "sha256.h"

void sha256_padding(uint8_t* message, uint8_t** buffer, size_t message_length, size_t* buffer_length) {
    size_t total_zeros = 0;
    uint64_t bit_length = 0;

    *buffer_length = ((message_length + 9 + 64) / 64) * 64;
    *buffer = safe_malloc((*buffer_length * sizeof **buffer));

    memcpy((*buffer), message, message_length);

    (*buffer)[message_length] = 0x80;
    // Total number of zeros = total buffer length - the 64 bit (8 byte) message length.
    total_zeros = *buffer_length - 8;
    memset((*buffer + message_length + 1), 0x00, total_zeros - 1);

    bit_length = (uint64_t)message_length * 8;
    for (size_t i = 0; i < 8; i++) {
        (*buffer)[total_zeros + i] = (uint8_t)(bit_length >> (56 - i * 8));
    }
}