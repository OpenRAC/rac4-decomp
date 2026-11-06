#include "common.h"

typedef struct Descriptor {
    u32 unknown0;
    s32 limit;
} Descriptor;
extern u32 D_00206E58[];
extern const char D_0021EFB8[];
extern const char D_003D07A0[];
extern const char D_0021EFC0[];
extern const char D_0021EFC8[];
extern const char D_0021EFD0[];
extern const char D_003D07B8[];
extern const char D_0021EFD8[];
extern const char D_0021EFE8[];
extern const char D_003D07D0[];
extern void func_00460D98(u32 *registry, s32 count);
extern void func_00460DE8(u32 *registry, const char *name, void *owner,
                          Descriptor *descriptor, u32 cost, u32 bytes,
                          const void *data, s32 id);
extern void func_00461128(u32 *registry, s32 count, const char *label);

void func_00461340(u8 *owner)
{
    u32 *registry = D_00206E58;

    func_00460D98(registry, 1);
    func_00460DE8(registry, D_0021EFB8, owner, (Descriptor *)(owner + 8),
                  0x1A00, 0, 0, 1);
    func_00460DE8(registry, D_003D07A0, owner, (Descriptor *)(owner + 0x28),
                  0x3100, 0, 0, 2);
    func_00460DE8(registry, D_0021EFC0, owner, (Descriptor *)(owner + 0x10),
                  0x27500, 0, 0, 3);
    func_00460DE8(registry, D_0021EFC8, owner, (Descriptor *)(owner + 0x18),
                  0x4800, 0, 0, 4);
    func_00460DE8(registry, D_0021EFD0, owner, (Descriptor *)(owner + 0x20),
                  0x1C200, 0, 0, 5);
    func_00460DE8(registry, D_003D07B8, owner, (Descriptor *)(owner + 0x30),
                  0x5E00, 0, 0, 6);
    func_00460DE8(registry, D_0021EFD8, owner, (Descriptor *)(owner + 0x38),
                  0x2B200, 0, 0, 7);
    func_00460DE8(registry, D_0021EFE8, owner, (Descriptor *)(owner + 0xC0),
                  0x1400, 0, 0, 9);
    func_00461128(registry, 1, D_003D07D0);
}
