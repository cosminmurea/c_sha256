#include "sha256.h"

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
    free(message);
    free(padded_message);
    return 0;
}