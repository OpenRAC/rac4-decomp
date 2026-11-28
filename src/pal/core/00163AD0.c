#include "common.h"

typedef struct {
    s32 index;
    u32 *result;
} StreamRequest;

typedef struct {
    s32 offset;
    s32 size;
} StreamAsset;

typedef struct {
    u8 pad0[0xCBB4];
    s32 origin;
    u8 padCBB8[0x858];
    StreamAsset assets[0];
} StreamTable;

typedef void (*StreamCallback)(s32, u64);

extern void func_001582B8(s32, s32, StreamCallback, u64);
extern void func_001585A8(s32);
extern void func_001596E8(void);
extern void func_00163A08(s32, u64);
extern StreamTable D_001C20C0[];
extern u32 D_001D2280[];

s32 func_00163AD0(StreamRequest *request) {
    StreamTable *table;
    s32 index;
    s32 origin;

    func_001585A8(D_001D2280[0x27]);
    func_001596E8();
    request->result = &D_001D2280[0x27];
    D_001D2280[0x27] = 0xFFFFFFFF;
    table = D_001C20C0;
    index = request->index;
    origin = table->origin;
    func_001582B8(table->assets[index].offset + origin, 0, func_00163A08, (u32)request);
    return 1;
}
