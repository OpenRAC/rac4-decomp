/* Not matching yet: PAL WIP; level_00 .text 0x004F9350, 292B. Not part of the build. */
/*
 * Resize-wrapper source ABI remains inconsistent with actual consumed buffer/new-size contract.
 * Retained source is WIP, not helper-interface consistency approval.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 0ffce324017b9c3931e1289b36f0a3c9dfcf8d27c6623b085a8cddb5f0791b0c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_004F9350 nonmatching/pal/l00_multiplayer_menu/func_L00_004F9350.c --diff
 */
#include "common.h"

void *func_L00_004FAD00(void *oldBuffer, u32 newBytes);

void func_L00_004F9350(void *object)
{
    u8 *state = object;
    u8 *end;
    u8 *removed;
    u8 *oldBuffer;
    u8 *newBuffer;
    u8 *buffer;
    u8 *node;
    u8 *next;
    u8 **slot;
    u32 index;
    u32 words;
    u32 half;
    u32 count;
    u64 counter;

    index = *(u32 *)(state + 0x14);
    words = *(u32 *)(state + 0x18);
    buffer = *(u8 **)(state + 0x00);
    end = buffer + ((index + words) << 2);
    removed = *(u8 **)(end - 4);
    *(u8 **)(end - 4) = NULL;

    index = *(u32 *)(state + 0x14);
    if (index == 0) {
        words = *(u32 *)(state + 0x10);
        oldBuffer = *(u8 **)(state + 0x00);
        newBuffer = func_L00_004FAD00(oldBuffer, (words >> 1) << 2);
        if (newBuffer == NULL) {
            *(u32 *)(state + 0xA0) = *(u32 *)(state + 0xA0) + 1U;
            return;
        }
        half = *(u32 *)(state + 0x18) >> 1;
        counter = *(u64 *)(state + 0x50);
        words = *(u32 *)(state + 0x10);
        *(u64 *)(state + 0x50) = counter + 1ULL;
        *(u32 *)(state + 0x10) = words >> 1;
        *(u32 *)(state + 0x14) = half - 1U;
        *(u8 **)(state + 0x00) = newBuffer;
        *(u32 *)(state + 0x18) = half;
    } else {
        *(u32 *)(state + 0x14) = index - 1U;
    }

    count = *(u32 *)(state + 0x0C);
    counter = *(u64 *)(state + 0x48);
    index = *(u32 *)(state + 0x14);
    buffer = *(u8 **)(state + 0x00);
    *(u32 *)(state + 0x0C) = count - 1U;
    *(u64 *)(state + 0x48) = counter + 1ULL;
    slot = (u8 **)(buffer + (index << 2));
    node = *slot;
    if (node != NULL) {
        next = *(u8 **)(node + 4);
        if (next != NULL) {
            do {
                node = next;
                next = *(u8 **)(node + 4);
            } while (next != NULL);
        }
        *(u8 **)(node + 4) = removed;
    } else {
        *slot = removed;
    }
}
