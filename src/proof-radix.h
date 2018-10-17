#ifndef _MERKLIX_PROOF_H
#define _MERKLIX_PROOF_H

#include <stdint.h>
#include <stdbool.h>

#define MERKLIX_PROOF_DEADEND 0
#define MERKLIX_PROOF_SHORT 1
#define MERKLIX_PROOF_COLLISION 2
#define MERKLIX_PROOF_EXISTS 3
#define MERKLIX_PROOF_UNKNOWN 4

typedef struct merklix_proof_node_s {
  uint8_t prefix[32];
  uint16_t prefix_size;
  uint8_t node[32];
} merklix_proof_node_t;

typedef struct merklix_proof_s {
  uint8_t type;
  uint16_t depth;
} merklix_proof_t;

int
merklix_proof_verify(
  const uint8_t *root
  const uint8_t *key
);
#endif

