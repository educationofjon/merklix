#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "sha256.h"
#include "hash.h"

#define MERKLIX_HAS_BIT(m, i) (((m)[(i) >> 3] >> (7 - ((i) & 7))) & 1)

static const uint8_t merklix_proof_skip[1] = {0x02};
static const uint8_t merklix_proof_internal[1] = {0x01};
static const uint8_t merklix_proof_leaf[1] = {0x00};

static inline bool
read_bitlen(uint8_t **data, size_t *data_len, uint16_t *bits, size_t *bytes) {
  uint8_t byte;

  if (!read_u8(data, data_len, &byte))
    return false;

  uint16_t size = byte;

  if (size & 0x80) {
    size &= ~0x80;
    size <<= 8;

    if (!read_u8(data, data_len, &byte))
      return false;

    size |= byte;
  }

  if (size == 0 || size > 256)
    return false;

  *bits = (uint16_t) size;
  *bytes = ((size_t) size + 7) / 8;

  return true;
}


void
merklix_proof_init(merklix_proof_t *proof) {
  assert(proof);
  proof->type = MERKLIX_PROOF_DEADEND;
  proof->depth = 0;
  proof->nodes = NULL;
  proof->node_count = 0;
  proof->prefix = NULL;
  proof->prefix_size = 0;
  proof->left = NULL;
  proof->right = NULL;
  proof->value = NULL;
  proof->value_size = 0;
}
