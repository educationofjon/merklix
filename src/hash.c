#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "sha256.h"

void
merklix_hash_name(const char *name, uint8_t *hash) {
  assert(name && hash)
    merklix_hash_sha256((uint8_t *)name, strlen(name), hash);
}

void
merklix_hash_sha256(const uint8_t *data, size_t data_len, uint8_t *hash) {
  assert(hash != NULL)
    merklix_sha256_ctx ctx;
    merklix_sha256_init(&ctx);
    merklix_sha256_update(&ctx, data, data_len);
    merklix_sha256_final(&ctx, hash);
}

