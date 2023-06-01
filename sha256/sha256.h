#ifndef SHA256_H
#define SHA256_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../modules/bit_util.h"
#include "../modules/file_util.h"
#include "../modules/mem_util.h"

/**
 * @brief                   Applies FIPS 180-4 compliant padding for the message.
 *                          The caller is responsible for freeing the memory allocated for the resulting padded message.
 * @param message           The initial message without padding.
 * @param buffer            The buffer to hold the padded message - passed by reference.
 * @param message_length    The length of the initial message in bytes.
 * @param buffer_length     The length of the padded message in bytes - passed by reference.
 */
void sha256_padding(uint8_t* message, uint8_t** buffer, size_t message_length, size_t* buffer_length);

#endif