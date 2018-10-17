/**
 * Parts of this software are based on RHash:
 * https://github.com/rhash/RHash
 *
 * Copyright: 2010-2012 Aleksey Kravchenko <rhash.admin@gmail.com>
 *
 * Permission is hereby granted,  free of charge,  to any person  obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction,  including without limitation
 * the rights to  use, copy, modify,  merge, publish, distribute, sublicense,
 * and/or sell copies  of  the Software,  and to permit  persons  to whom the
 * Software is furnished to do so.
 *
 * This program  is  distributed  in  the  hope  that it will be useful,  but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  Use this program  at  your own risk!
 */

#ifndef _MERKLIX_SHA_256_H
#define _MERKLIX_SHA_256_H

#include <stdint.h>
#include <stdlib.h>

#define merklix_sha256_block_size 64
#define merklix_sha256_hash_size 32

typedef struct merklix_sha256_ctx {
  unsigned int message[16];
  uint64_t length;
  unsigned int hash[8];
  unsigned int digest_length;
} merklix_sha256_ctx;

void
merklix_sha256_init(merklix_sha256_ctx *ctx);

void
merklix_sha256_update(merklix_sha256_ctx *ctx, const unsigned char *msg, size_t size);

void
merklix_sha256_final(merklix_sha256_ctx *ctx, unsigned char *result);

#endif
