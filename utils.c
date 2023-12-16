#include "utils.h"

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    errno = 0;
    if (ptr == NULL) {
        if (errno) {
            perror("Error in malloc()");
        } else {
            fputs("Unable to allocate enough memory!!\n", stderr);
        }
        exit(EXIT_FAILURE);
    }
    return ptr;
}

FILE* safe_fopen(const char* file_path, const char* mode) {
    FILE* file_ptr = fopen(file_path, mode);
    errno = 0;
    if (file_ptr == NULL) {
        if (errno) {
            perror("Error in fopen()");
        } else {
            fputs("Unable to open the file!!\n", stderr);
        }
        exit(EXIT_FAILURE);
    }
    return file_ptr;
}

uint8_t* hex_string_to_byte_array(char* hex_string, size_t length) {
    const char* ptr = hex_string;
    uint8_t* byte_array = safe_malloc((length * sizeof *byte_array) / 2);

    // WARNING: no sanitization or error-checking whatsoever
    // Two string characters form one byte => "CA7B" = {0xCA, 0x7B} => the length is halved.
    for (size_t count = 0; count < length / 2; count++) {
        sscanf(ptr, "%2hhx", &byte_array[count]);
        ptr += 2;
    }

    return byte_array;
}

static size_t file_size(const char* file_path) {
    struct stat file_info;
    errno = 0;
    if (stat(file_path, &file_info) < 0) {
        if (errno) {
            perror("Error in stat()");
        } else {
            fputs("Could not get file details!!\n", stderr);
        }
        exit(EXIT_FAILURE);
    }
    return file_info.st_size;
}

// Reads a file into a byte array passed by reference.
// Freeing the buffer is the callers responsibility.
void read_file_bytes(const char* file_path, uint8_t** buffer, size_t* file_length) {
    FILE* file_ptr = safe_fopen(file_path, "rb");
    size_t bytes_read = 0;

    *file_length = file_size(file_path);
    *buffer = safe_malloc(*file_length * sizeof **buffer);

    bytes_read = fread(*buffer, 1, *file_length, file_ptr);
    if (bytes_read != *file_length) {
        printf("An error occurred while trying to read from the file!!\n");
        exit(EXIT_FAILURE);
    }

    fclose(file_ptr);
}