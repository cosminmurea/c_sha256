#include "utils.h"

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Unable to allocate enough memory!!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

FILE* safe_fopen(const char* file_path, const char* mode) {
    FILE* file_ptr = fopen(file_path, mode);
    if (file_ptr == NULL) {
        printf("Unable to open the file!!\n");
        exit(EXIT_FAILURE);
    }

    return file_ptr;
}

size_t file_size(FILE* file_ptr) {
    size_t file_length = 0;
    fseek(file_ptr, 0, SEEK_END);
    file_length = ftell(file_ptr);
    rewind(file_ptr);
    return file_length;
}

void read_file_bytes(const char* file_path, uint8_t** buffer, size_t* file_length) {
    FILE* file_ptr = safe_fopen(file_path, "rb");
    size_t bytes_read = 0;

    *file_length = file_size(file_ptr);
    *buffer = safe_malloc(*file_length * sizeof **buffer);

    bytes_read = fread(*buffer, 1, *file_length, file_ptr);
    if (bytes_read != *file_length) {
        printf("An error occurred while trying to read from the file!!\n");
        exit(EXIT_FAILURE);
    }

    fclose(file_ptr);
}

uint8_t* hex_string_to_byte_array(char* hex_string, size_t length) {
    const char* ptr = hex_string;
    uint8_t* byte_array = safe_malloc((length * sizeof *byte_array) / 2);

    // WARNING: no sanitization or error-checking whatsoever
    for (size_t count = 0; count < length / 2; count++) {
        sscanf(ptr, "%2hhx", &byte_array[count]);
        ptr += 2;
    }

    return byte_array;
}

/* void print_bits(uint8_t byte) {  
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

void write_file_bytes(const char* file_path, uint32_t* buffer, size_t buffer_length) {
    FILE* file_ptr = fopen(file_path, "wb");
    size_t elements_written = 0;

    if (file_ptr == NULL) {
        printf("Unable to open the file!!\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < buffer_length; i++) {
        buffer[i] = convert_endianness(buffer[i]);
    }

    elements_written = fwrite(buffer, sizeof(uint32_t), buffer_length, file_ptr);
    if (elements_written != buffer_length) {
        printf("An error occurred while trying to write to the file!!\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < buffer_length; i++) {
        buffer[i] = convert_endianness(buffer[i]);
    }

    fclose(file_ptr);
} */