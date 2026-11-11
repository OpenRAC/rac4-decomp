/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#define FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
void *func_0046B930(s32, s32);
void func_0047B9B8(void *, s32);
void func_L01_003C9930(void *);
void func_L01_003C9CF0(void *);
extern s32 D_0021DE10;
extern s16 D_003BAB60[];

void *func_L01_003C9A68(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5) {
    s32 index;
    void *actor;
    void *data;
    void *second;
    if (arg0 == -1)
        goto failed;
    index = D_0021DE10 % 20;
    if (arg0 >= 26) {
        if (arg0 < D_003BAB60[index])
            return 0;
        if (arg0 > D_003BAB60[index + 1])
            return 0;
    }
    actor = func_0046B930(3950, 144);
    if (!actor) {
    failed:
        return 0;
    }
    data = FIELD(actor, void *, 0xAC);
    func_0047B9B8(actor, 0);
    FIELD(data, s32, 0x6C) = arg0;
    FIELD(data, u8, 0x71) = arg1;
    FIELD(data, u8, 0x72) = arg2;
    FIELD(data, u8, 0x7C) = arg3;
    FIELD(data, u8, 0x7D) = arg4;
    FIELD(data, u8, 0x70) = 1;
    FIELD(data, s32, 0x74) = -1;
    FIELD(data, u8, 0x7F) = 0;
    FIELD(data, u8, 0x7E) = 0;
    FIELD(data, u8, 0x80) = 0;
    FIELD(data, s8, 0x73) = -1;
    FIELD(data, s32, 0x88) = -1;
    FIELD(data, s32, 0x78) = -1;
    FIELD(data, void *, 0x84) = 0;
    if (arg5 != -1) {
        second = func_0046B930(3950, 144);
        FIELD(data, void *, 0x84) = second;
        if (second) {
            data = FIELD(second, void *, 0xAC);
            func_0047B9B8(second, 0);
            FIELD(data, u8, 0x70) = 1;
            FIELD(data, void *, 0x84) = 0;
            FIELD(data, u8, 0x7F) = 0;
            FIELD(data, u8, 0x7E) = 0;
            FIELD(data, u8, 0x80) = 0;
            FIELD(data, s32, 0x78) = FIELD(data, s32, 0x88) = FIELD(data, s8, 0x73) = -1;
            FIELD(data, s32, 0x6C) = arg5;
        }
    }
    func_L01_003C9930(actor);
    func_L01_003C9CF0(actor);
    return actor;
}
