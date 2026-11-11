#include "common.h"

typedef struct Descriptor {
    u32 unknown0;
    s32 limit;
} Descriptor;
extern u32 D_00206DD8[];
extern const char D_0021EF38[];
extern const char D_003D0738[];
extern const char D_0021EF40[];
extern const char D_0021EF48[];
extern const char D_0021EF50[];
extern const char D_003D0750[];
extern const char D_0021EF58[];
extern const char D_0021EF68[];
extern const char D_003D0768[];
extern void func_00460558(u32 *registry, s32 count);
extern void func_004605A8(u32 *registry, const char *name, void *owner,
                          Descriptor *descriptor, u32 cost, u32 bytes,
                          const void *data, s32 id);
extern void func_004608E8(u32 *registry, s32 count, const char *label);

void func_00460B00(u8 *owner)
{
    u32 *registry = D_00206DD8;

    func_00460558(registry, 1);
    func_004605A8(registry, D_0021EF38, owner, (Descriptor *)(owner + 8),
                  0x1A00, 0, 0, 1);
    func_004605A8(registry, D_003D0738, owner, (Descriptor *)(owner + 0x28),
                  0x3100, 0, 0, 2);
    func_004605A8(registry, D_0021EF40, owner, (Descriptor *)(owner + 0x10),
                  0x27500, 0, 0, 3);
    func_004605A8(registry, D_0021EF48, owner, (Descriptor *)(owner + 0x18),
                  0x4800, 0, 0, 4);
    func_004605A8(registry, D_0021EF50, owner, (Descriptor *)(owner + 0x20),
                  0x1C200, 0, 0, 5);
    func_004605A8(registry, D_003D0750, owner, (Descriptor *)(owner + 0x30),
                  0x5E00, 0, 0, 6);
    func_004605A8(registry, D_0021EF58, owner, (Descriptor *)(owner + 0x38),
                  0x2B200, 0, 0, 7);
    func_004605A8(registry, D_0021EF68, owner, (Descriptor *)(owner + 0xC0),
                  0x1400, 0, 0, 9);
    func_004608E8(registry, 1, D_003D0768);
}
