/**
 * Parts of this software are based on tony-bignum-c:
 * https://github.com/kokke/tiny-bignum-c
 *
 * tiny-bignum-c resides in the public domain.
 */

#ifndef _MERKLIX_BN_H
#define _MERKLIX_BN_H

#include <assert.h>
#include <stdint.h>

#define MERKLIX_BN_SIZE (64 / 4)
#define MERKLIX_BN_MSB ((uint64_t)0x80000000)
#define MERKLIX_BN_MAX ((uint64_t)0xffffffff)

typedef struct merklix_bn_s {
  uint32_t array[MERKLIX_BN_SIZE];
} merklix_bn_t;

/*
 * Initialization functions
 */

void
merklix_bn_init(merklix_bn_t *n);

void
merklix_bn_from_int(merklix_bn_t *n, uint64_t i);

uint64_t
merklix_bn_to_int(const merklix_bn_t *n);

void
merklix_bn_from_string(merklix_bn_t *n, const char *str, int nbytes);

void
merklix_bn_to_string(const merklix_bn_t *n, char *str, int maxsize);

void
merklix_bn_from_array(merklix_bn_t *n, const uint8_t *array, size_t size);

void
merklix_bn_to_array(const merklix_bn_t *n, uint8_t *array, size_t size);

/*
 * Basic arithmetic operations
 */


#endif
