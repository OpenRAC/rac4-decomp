/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_01EE3A18(s32, void *);
extern void **func_01EFF990(void);
extern void func_01F0C090(const char *, s32);
extern s32 D_0019DA98[];
extern s32 D_0019DB68[];

// Searches the list arg2 for an entry that matches arg1 through the table from func_01EFF990; returns the entry or NULL.
void *func_01EFFF40(s32 arg0, s32 arg1, void **arg2) {
    void **temp_v0;
    void **var_s1;
    void *temp_v0_3;
    s32 temp_v0_2;
    s32 temp_v0_4;
    void *temp_v0_6;
    s32 var_s2;

    var_s1 = arg2;
    if (arg1 == 0) {
        func_01F0C090((const char *)D_0019DA98, 0xA9);
    }
    if (var_s1 == NULL) {
        func_01F0C090((const char *)D_0019DA98, 0xAA);
    }
    temp_v0 = func_01EFF990();
    if (((s32 (*)(void **, s32))((s32 *)*temp_v0)[6])(temp_v0, arg1) == 0) {
        func_01F0C090((const char *)D_0019DA98, 0xB2);
    }
    temp_v0_2 = func_01EE3A18(arg1, D_0019DB68);
    if (temp_v0_2 == 0) {
        func_01F0C090((const char *)D_0019DA98, 0xB8);
    }
    var_s2 = 0;
    do {
        temp_v0_3 = *var_s1;
        if (temp_v0_3 != NULL) {
            temp_v0_6 = *(void **)((u8 *)temp_v0_3 + 0xB0);
            temp_v0_6 = *(void **)((u8 *)temp_v0_6 + 0x3C);
            temp_v0_4 = ((s32 (*)(void *))temp_v0_6)(temp_v0_3);
            if (temp_v0_4 == 0) {
                func_01F0C090((const char *)D_0019DA98, 0xBF);
            }
            if (func_0011A8A0((void *)temp_v0_4, (const u8 *)temp_v0_2) == 0) {
                return *var_s1;
            }
        }
        var_s2 += 1;
        var_s1++;
    } while (var_s2 < 0x100);
    return NULL;
}
