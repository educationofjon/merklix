#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"

#define MERKLIX_HAS_BIT(m, i) (((m)[(i) >> 3] >> (7 - ((i) & 7))) & 1)

static const uint8_t merklix_proof_skip[1] = {0x02};
static const uint8_t merklix_proof_internal[1] = {0x01};
static const uint8_t merklix_proof_leaf[1] = {0x00};

static inline bool


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
