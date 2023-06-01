#include "mem_util.h"

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Unable to allocate enough memory!!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}