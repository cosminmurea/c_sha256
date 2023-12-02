#ifndef SHA256_H
#define SHA256_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAX_TEST_MSG_LENGTH 13000

void sha256(uint8_t* message, size_t message_length);
void sha256_testing(const char* test_file_path);

#endif