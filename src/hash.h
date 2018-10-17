#ifndef _MERKLIX_HASH_H
#define _MERKLIX_HASH_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void
merklix_hash_name(const char *name, uint8_t *hash);

void
merklix_hash_sha256(const uint8_t *data, size_t data_len, uint8_t *hash);

void
merklix_hash_hash256(const uint8_t *data, size_t data_len, uint8_t *hash);

void
merklix_hash_sha256_hmac(
  const uint8_t *data,
  size_t data_len,
  const uint8_t *key,
  size_t key_len,
  uint8_t *mac
);

#endif
