/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 29.6.0 Sat Dec  1 09:19:46 2018.
 */

#include <string.h>

#include "signed.h"

#define UNUSED(x) (void)(x)

ssize_t signed_message32big_encode(
    uint8_t *dst_p,
    const struct signed_message32big_t *src_p,
    size_t size)
{
    uint32_t s32big;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    s32big = (uint32_t)src_p->s32big;
    dst_p[0] |= ((s32big >> 24) & 0xffu);
    dst_p[1] |= ((s32big >> 16) & 0xffu);
    dst_p[2] |= ((s32big >> 8) & 0xffu);
    dst_p[3] |= ((s32big << 0) & 0xffu);

    return (8);
}

int signed_message32big_decode(
    struct signed_message32big_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t s32big;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    s32big = 0u;
    s32big |= ((uint32_t)(src_p[0] & 0xffu) << 24);
    s32big |= ((uint32_t)(src_p[1] & 0xffu) << 16);
    s32big |= ((uint32_t)(src_p[2] & 0xffu) << 8);
    s32big |= ((uint32_t)(src_p[3] & 0xffu) >> 0);
    dst_p->s32big = (int32_t)s32big;

    return (0);
}

bool signed_message32big_s32big_is_in_range(int32_t value)
{
    UNUSED(value);

    return (true);
}

ssize_t signed_message33big_encode(
    uint8_t *dst_p,
    const struct signed_message33big_t *src_p,
    size_t size)
{
    uint64_t s33big;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    s33big = (uint64_t)src_p->s33big;
    dst_p[0] |= ((s33big >> 25) & 0xffu);
    dst_p[1] |= ((s33big >> 17) & 0xffu);
    dst_p[2] |= ((s33big >> 9) & 0xffu);
    dst_p[3] |= ((s33big >> 1) & 0xffu);
    dst_p[4] |= ((s33big << 7) & 0x80u);

    return (8);
}

int signed_message33big_decode(
    struct signed_message33big_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint64_t s33big;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    s33big = 0ull;
    s33big |= ((uint64_t)(src_p[0] & 0xffu) << 25);
    s33big |= ((uint64_t)(src_p[1] & 0xffu) << 17);
    s33big |= ((uint64_t)(src_p[2] & 0xffu) << 9);
    s33big |= ((uint64_t)(src_p[3] & 0xffu) << 1);
    s33big |= ((uint64_t)(src_p[4] & 0x80u) >> 7);

    if ((s33big & (1ull << 32)) != 0ull) {
        s33big |= 0xfffffffe00000000ull;
    }

    dst_p->s33big = (int64_t)s33big;

    return (0);
}

bool signed_message33big_s33big_is_in_range(int64_t value)
{
    UNUSED(value);

    return (true);
}

ssize_t signed_message64big_encode(
    uint8_t *dst_p,
    const struct signed_message64big_t *src_p,
    size_t size)
{
    uint64_t s64big;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    s64big = (uint64_t)src_p->s64big;
    dst_p[0] |= ((s64big >> 56) & 0xffu);
    dst_p[1] |= ((s64big >> 48) & 0xffu);
    dst_p[2] |= ((s64big >> 40) & 0xffu);
    dst_p[3] |= ((s64big >> 32) & 0xffu);
    dst_p[4] |= ((s64big >> 24) & 0xffu);
    dst_p[5] |= ((s64big >> 16) & 0xffu);
    dst_p[6] |= ((s64big >> 8) & 0xffu);
    dst_p[7] |= ((s64big << 0) & 0xffu);

    return (8);
}

int signed_message64big_decode(
    struct signed_message64big_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint64_t s64big;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    s64big = 0ull;
    s64big |= ((uint64_t)(src_p[0] & 0xffu) << 56);
    s64big |= ((uint64_t)(src_p[1] & 0xffu) << 48);
    s64big |= ((uint64_t)(src_p[2] & 0xffu) << 40);
    s64big |= ((uint64_t)(src_p[3] & 0xffu) << 32);
    s64big |= ((uint64_t)(src_p[4] & 0xffu) << 24);
    s64big |= ((uint64_t)(src_p[5] & 0xffu) << 16);
    s64big |= ((uint64_t)(src_p[6] & 0xffu) << 8);
    s64big |= ((uint64_t)(src_p[7] & 0xffu) >> 0);
    dst_p->s64big = (int64_t)s64big;

    return (0);
}

bool signed_message64big_s64big_is_in_range(int64_t value)
{
    UNUSED(value);

    return (true);
}

ssize_t signed_message64_encode(
    uint8_t *dst_p,
    const struct signed_message64_t *src_p,
    size_t size)
{
    uint64_t s64;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    s64 = (uint64_t)src_p->s64;
    dst_p[0] |= ((s64 << 0) & 0xffu);
    dst_p[1] |= ((s64 >> 8) & 0xffu);
    dst_p[2] |= ((s64 >> 16) & 0xffu);
    dst_p[3] |= ((s64 >> 24) & 0xffu);
    dst_p[4] |= ((s64 >> 32) & 0xffu);
    dst_p[5] |= ((s64 >> 40) & 0xffu);
    dst_p[6] |= ((s64 >> 48) & 0xffu);
    dst_p[7] |= ((s64 >> 56) & 0xffu);

    return (8);
}

int signed_message64_decode(
    struct signed_message64_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint64_t s64;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    s64 = 0ull;
    s64 |= ((uint64_t)(src_p[0] & 0xffu) >> 0);
    s64 |= ((uint64_t)(src_p[1] & 0xffu) << 8);
    s64 |= ((uint64_t)(src_p[2] & 0xffu) << 16);
    s64 |= ((uint64_t)(src_p[3] & 0xffu) << 24);
    s64 |= ((uint64_t)(src_p[4] & 0xffu) << 32);
    s64 |= ((uint64_t)(src_p[5] & 0xffu) << 40);
    s64 |= ((uint64_t)(src_p[6] & 0xffu) << 48);
    s64 |= ((uint64_t)(src_p[7] & 0xffu) << 56);
    dst_p->s64 = (int64_t)s64;

    return (0);
}

bool signed_message64_s64_is_in_range(int64_t value)
{
    UNUSED(value);

    return (true);
}

ssize_t signed_message33_encode(
    uint8_t *dst_p,
    const struct signed_message33_t *src_p,
    size_t size)
{
    uint64_t s33;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    s33 = (uint64_t)src_p->s33;
    dst_p[0] |= ((s33 << 0) & 0xffu);
    dst_p[1] |= ((s33 >> 8) & 0xffu);
    dst_p[2] |= ((s33 >> 16) & 0xffu);
    dst_p[3] |= ((s33 >> 24) & 0xffu);
    dst_p[4] |= ((s33 >> 32) & 0x01u);

    return (8);
}

int signed_message33_decode(
    struct signed_message33_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint64_t s33;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    s33 = 0ull;
    s33 |= ((uint64_t)(src_p[0] & 0xffu) >> 0);
    s33 |= ((uint64_t)(src_p[1] & 0xffu) << 8);
    s33 |= ((uint64_t)(src_p[2] & 0xffu) << 16);
    s33 |= ((uint64_t)(src_p[3] & 0xffu) << 24);
    s33 |= ((uint64_t)(src_p[4] & 0x01u) << 32);

    if ((s33 & (1ull << 32)) != 0ull) {
        s33 |= 0xfffffffe00000000ull;
    }

    dst_p->s33 = (int64_t)s33;

    return (0);
}

bool signed_message33_s33_is_in_range(int64_t value)
{
    return ((value >= -4294967296ll) && (value <= 4294967295ll));
}

ssize_t signed_message32_encode(
    uint8_t *dst_p,
    const struct signed_message32_t *src_p,
    size_t size)
{
    uint32_t s32;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    s32 = (uint32_t)src_p->s32;
    dst_p[0] |= ((s32 << 0) & 0xffu);
    dst_p[1] |= ((s32 >> 8) & 0xffu);
    dst_p[2] |= ((s32 >> 16) & 0xffu);
    dst_p[3] |= ((s32 >> 24) & 0xffu);

    return (8);
}

int signed_message32_decode(
    struct signed_message32_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t s32;

    if (size < 8) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    s32 = 0u;
    s32 |= ((uint32_t)(src_p[0] & 0xffu) >> 0);
    s32 |= ((uint32_t)(src_p[1] & 0xffu) << 8);
    s32 |= ((uint32_t)(src_p[2] & 0xffu) << 16);
    s32 |= ((uint32_t)(src_p[3] & 0xffu) << 24);
    dst_p->s32 = (int32_t)s32;

    return (0);
}

bool signed_message32_s32_is_in_range(int32_t value)
{
    UNUSED(value);

    return (true);
}
