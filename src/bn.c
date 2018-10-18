#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "bn.h"

static void _lshift_one_bit(merklix_bn_t *a);
static void _rshift_one_bit(merklix_bn_t *a);
static void _lshift_word(merklix_bn_t *a, int nwords);
static void _rshift_word(merklix_bn_t *a, int nwords);

void
merklix_bn_init(merklix_bn_t *n) {
  assert(n && "n is null");

  int i;
  for (i = 0; i < MERKLIX_BN_SIZE; i++)
    n->array[i] = 0;
}

void
merklix_bn_from_int(merklix_bn_t *n, uint64_t i) {}

