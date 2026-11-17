#include "common.h"

extern u8 *func_0046B930(s32 classId, s32 flags);
extern void func_0047B9B8(void *arg0, void *arg1);
extern void *func_00488C98(s32);
extern void *func_005111D0(s32 arg0, s32 arg1);
extern void func_00511310(s32 arg0, void *arg1);

/* Allocates a record for arg2, fills in its fields from the class lookup, and returns it (NULL if none). */
void *func_0053FCA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *temp_v0;
    u8 *temp_v0_2;
    char *temp_a0;
    void *temp_v0_3;

    temp_v0 = func_005111D0(arg2, -1);
    if (temp_v0 != NULL) {
        temp_v0_2 = func_0046B930(arg0, arg1);
        *(u8 **)(temp_v0 + 0x18) = temp_v0_2;
        func_0047B9B8(temp_v0_2, (void *)arg3);
        temp_a0 = *(char **)(temp_v0 + 0x18);
        *(u16 *)(temp_v0 + 0x1C) = *(u16 *)(temp_a0 + 0x34);
        temp_v0_3 = func_00488C98((s32)temp_a0);
        *(s32 *)(temp_v0 + 0x20) = *(s32 *)((char *)temp_v0_3 + 8);
        func_00511310((s32)temp_v0, *(void **)(temp_v0 + 0x18));
        *(s8 *)(temp_v0 + 0x2C) = (s8)arg4;
    }
    return temp_v0;
}
