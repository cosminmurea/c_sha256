#ifndef MEM_UTIL_H
#define MEM_UTIL_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief           Wrapper for malloc(size_t size). Exits with status 1 if malloc() returned NULL.
 *                  It is the callers duty to free() the memory allocated by this function.
 * @param size      Memory to allocate = number of elements * size of one element.
 * @return void*    The pointer returned by malloc() if it is != NULL.
 */
void* safe_malloc(size_t size);

#endif