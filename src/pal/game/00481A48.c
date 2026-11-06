#include "common.h"

typedef void (*Callback)(void *, s32);
extern void *func_00476ED0(void *);

typedef struct Descriptor {
    u8 unknown0[5];
    u8 inherit;
    u8 unknown6[2];
    u32 flags;
} Descriptor;

static inline Descriptor *getDescriptor(void *object)
{
    u32 address = (u32)object;
    u32 index = *(u8 *)(address + 0x54);
    u32 table = *(u32 *)(address + 0x24);
    u32 asset = *(u32 *)(table + (index << 2) + 0x48);
    u32 metadata = *(u32 *)(asset + 0x18);
    return *(Descriptor **)(metadata + 4);
}

/* A missing state fails; an already stopped or different mode succeeds. */
s32 func_00481A48(void *object, s32 mode, s32 temporary)
{
    u32 stateAddress;
    Callback callback;
    Descriptor *descriptor;
    u32 value;

    stateAddress = (u32)func_00476ED0(object);
    if (stateAddress == 0) {
        return 0;
    }
    if (*(u8 *)(stateAddress + 0x33) != mode) {
        return 1;
    }
    if (mode <= 0) {
        return 1;
    }
    *(s32 *)(stateAddress + 0x4) &= -0x81;
    *(s32 *)(stateAddress + 0x4) &= 0xFFFDFFFF;
    *(s32 *)(stateAddress + 0x4) &= -0x1001;
    callback = *(Callback *)(stateAddress + 0x6C);
    *(s32 *)(stateAddress + 0xC) = 1;
    *(u8 *)(stateAddress + 0x33) = 0;
    *(Callback *)(stateAddress + 0x6C) = 0;
    descriptor = getDescriptor(object);
    if (descriptor->inherit == 0 || *(void **)(stateAddress + 0x5C) == 0) {
        value = descriptor->flags;
    } else {
        descriptor = getDescriptor(*(void **)(stateAddress + 0x5C));
        value = descriptor->flags;
    }
    if ((value & 2) != 0) {
        *(s32 *)(stateAddress + 0x4) |= 0x800;
    }
    if (temporary != 0) {
        *(s32 *)(stateAddress + 0x4) |= 0x80;
    }
    if (callback != 0) {
        callback(object, 4);
    }
    if (temporary != 0) {
        *(s32 *)(stateAddress + 0x4) &= -0x81;
    }
    return 1;
}
