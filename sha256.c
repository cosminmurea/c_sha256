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

void print_string_bits(const uint8_t* string, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        print_bits(string[i]);
    }
    printf("\n");
}

size_t file_size(FILE* file_ptr) {
    size_t file_length = 0;
    fseek(file_ptr, 0, SEEK_END);
    file_length = ftell(file_ptr);
    rewind(file_ptr);
    return file_length;
}

void read_file_bytes(const char* file_path, uint8_t** buffer, size_t* file_length) {
    FILE* file_ptr = fopen(file_path, "rb");
    size_t bytes_read = 0;

    if (file_ptr == NULL) {
        printf("The provided file path is invalid!!\n");
        exit(EXIT_FAILURE);
    }

    *file_length = file_size(file_ptr);
    *buffer = malloc(*file_length * sizeof **buffer);
    if ((*buffer) == NULL) {
        printf("Unable to allocate enough memory for the byte array!!\n");
        exit(EXIT_FAILURE);
    }

    bytes_read = fread(*buffer, 1, *file_length, file_ptr);
    if (bytes_read != *file_length) {
        printf("An error occurred while trying to read from file %s!!\n", file_path);
        exit(EXIT_FAILURE);
    }

    (*buffer)[*file_length] = '\0';
    fclose(file_ptr);
}

void sha256_padding(uint8_t* message, uint8_t** buffer, size_t message_length, size_t* buffer_length) {
    size_t total_zeros = 0;
    uint64_t bit_length = 0;

    *buffer_length = ((message_length + 9 + 64) / 64) * 64;
    *buffer = malloc((*buffer_length * sizeof **buffer));
    if ((*buffer) == NULL) {
        printf("Unable to allocate enough memory for the padded byte array!!\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < message_length; i++) {
        (*buffer)[i] = message[i];
    }

    (*buffer)[message_length] = 0x80;
    total_zeros = *buffer_length - 8;
    memset((*buffer + message_length + 1), 0x00, total_zeros - 1);

    bit_length = (uint64_t)message_length * 8;
    (*buffer)[total_zeros] = (uint8_t)(bit_length >> 56);
    (*buffer)[total_zeros + 1] = (uint8_t)(bit_length >> 48);
    (*buffer)[total_zeros + 2] = (uint8_t)(bit_length >> 40);
    (*buffer)[total_zeros + 3] = (uint8_t)(bit_length >> 32);
    (*buffer)[total_zeros + 4] = (uint8_t)(bit_length >> 24);
    (*buffer)[total_zeros + 5] = (uint8_t)(bit_length >> 16);
    (*buffer)[total_zeros + 6] = (uint8_t)(bit_length >> 8);
    (*buffer)[total_zeros + 7] = (uint8_t)bit_length;
}

int main(int argc, char* argv[]) {
    char* file_path = NULL;
    uint8_t* message = NULL;
    uint8_t* padded_message = NULL;
    size_t padded_length = 0;
    size_t message_length = 0;

    file_path = argv[1];
    read_file_bytes(file_path, &message, &message_length);
    printf("File Contents : %s\n", message);
    print_string_bits(message, message_length);
    sha256_padding(message, &padded_message, message_length, &padded_length);
    print_string_bits(padded_message, padded_length);
    return 0;
}
