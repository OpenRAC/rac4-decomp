/* Not matching yet on PAL: SIZE ours 472 / disc 488 (tools/check_func.py --version pal func_004F2078 --diff). Not part of the build. */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"
extern u32 D_1000B400;
extern u32 D_1000B410;
/* Control-flow reference: OpenRAC RAC3 func_003AC3F8, 3ABA48.c,
 * commit 73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde (GPL-3.0).
 * PAL targets, semaphore/pointer ABI and wrapping arithmetic are independently recovered. */
typedef struct {
    void *buffer;
    void *descriptors;
    s32 capacity;
    s32 head;
    s32 used;
    s32 bytes;
    u8 unknown18[0x28];
    s32 semaphore;
    s32 active;
} Stream;
extern const char D_003D3258[];
extern s32 func_00126BE0(s32 semaphore);
extern s32 func_00126BC0(s32 semaphore);
extern void func_004F0708(const char *message);
extern void func_004F1CC0(u32 control);
extern s32 func_004F1C08(Stream *stream, u32 address);
extern void func_004F1D30(void *descriptor, void *data, u32 flags, u32 size);
s32 func_004F2078(Stream *stream)
{
    s32 changed = 0;
    u32 control;
    s32 position, advance, count, tail, i, index;
    func_00126BE0(stream->semaphore);
    if (stream->active == 0) {
        func_004F0708(D_003D3258);
        return 0;
    }
    func_004F1CC0(5);
    control = D_1000B400;
    position = func_004F1C08(stream, D_1000B410);
    advance = (s32)((u32)position + (u32)stream->capacity - (u32)stream->head) % stream->capacity;
    count = stream->bytes / 0x800;
    stream->bytes = (s32)((u32)stream->bytes - ((u32)count << 11));
    stream->head = (s32)((u32)stream->head + (u32)advance) % stream->capacity;
    stream->used = (s32)((u32)stream->used - (u32)advance);
    tail = (s32)((u32)stream->head + (u32)stream->used) % stream->capacity;
    if (count > 0) {
        s32 last = stream->capacity - 1;
        s32 slot = (s32)((u32)stream->head + (u32)stream->used + (u32)last) % stream->capacity;
        func_004F1D30((void *)((u32)stream->descriptors + ((u32)slot << 4)),
                      (void *)((u32)stream->buffer + ((u32)slot << 11)), 3, 0x80);
        changed = 1;
    }
    index = tail;
    for (i = 0; i < count; i++) {
        s32 flags = i != count - 1 ? 3 : 0;
        func_004F1D30((void *)((u32)stream->descriptors + ((u32)index << 4)),
                      (void *)((u32)stream->buffer + ((u32)index << 11)), flags, 0x80);
        index = (index + 1) % stream->capacity;
    }
    stream->used = (s32)((u32)stream->used + (u32)count);
    if (stream->used != 0) {
        if (changed) {
            control = (control & 0x0FFFFFFF) | 0x30000000;
        }
        func_004F1CC0(control | 0x100);
    }
    func_00126BC0(stream->semaphore);
    return 1;
}
