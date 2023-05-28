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
        print_bits(string[i]);
    }
    printf("\n");
}

uint8_t* read_file_bytes(const char* file_path) {
    FILE* file_ptr = fopen(file_path, "rb");
    size_t file_length = 0;
    uint8_t* file_bytes = NULL;

    if (file_ptr == NULL) {
        printf("The provided file path is invalid!!\n");
        exit(EXIT_FAILURE);
    }
    fseek(file_ptr, 0, SEEK_END);
    file_length = ftell(file_ptr);
    rewind(file_ptr);
    file_bytes = malloc(file_length * sizeof *file_bytes);
    if (file_bytes == NULL) {
        printf("Unable to allocate enough memory for the byte array!!");
        exit(EXIT_FAILURE);
    }
    fread(file_bytes, 1, file_length, file_ptr);
    file_bytes[file_length] = '\0';
    fclose(file_ptr);
    return file_bytes;
}

int main(int argc, char* argv[]) {
    char* file_path = NULL;
    uint8_t* message = NULL;

    file_path = argv[1];
    message = read_file_bytes(file_path);
    printf("File Contents : %s\n", message);
    print_string_bits(message, strlen((const char*)message));
    return 0;
}
