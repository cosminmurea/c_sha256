#include "file_util.h"

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
        printf("Unable to open the file!!\n");
        exit(EXIT_FAILURE);
    }

    *file_length = file_size(file_ptr);
    *buffer = safe_malloc(*file_length * sizeof **buffer);

    bytes_read = fread(*buffer, 1, *file_length, file_ptr);
    if (bytes_read != *file_length) {
        printf("An error occurred while trying to read from the file!!\n");
        exit(EXIT_FAILURE);
    }

    (*buffer)[*file_length] = '\0';
    fclose(file_ptr);
}