/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA9850(void *, u16 *);
extern s32 func_01EB6428(void *, void *);
extern u16 func_01EBD5C8(u8 *a0);
extern s32 func_01EC1FD0(void *, void *);

/* Walks the entry list at arg0+0x20 for the entry matching the id at arg1, updating the state word at arg0. */
s32 func_01EC14B8(void *arg0, u8 *arg1, u32 arg2, u16 *arg3) {
    u16 cnt;
    u16 id;
    u32 i;
    s32 res;
    s32 *node;
    u8 *hdr;
    s32 key;
    s32 r;

    res = 0;
    if (arg0 == NULL) {
        return 0xD2F3;
    }
    func_01EA9850(arg1, &cnt);
    arg1 += 2;
    *arg3 = cnt * 2 + 2;
    if (arg2 < (u16)(cnt * 2 + 2)) {
        return 0xD2F5;
    }
    i = 0;
    if (cnt != 0) {
        do {
            node = NULL;
            func_01EA9850(arg1, &id);
            arg1 += 2;
            if ((s32)arg0 != -0x14) {
                node = *(s32 **)((u8 *)arg0 + 0x20);
            }
            while (node != NULL) {
                if (node[0] != 0 && (key = node ? (s32)node + 0x18 : 0x10, hdr = node ? (u8 *)node + 8 : NULL, key != 0) && func_01EBD5C8((u8 *)key) == id) {
                    if (*hdr == 2) {
                        res = func_01EC1FD0(arg0, hdr + 4);
                    }
                    r = func_01EB6428((u8 *)arg0 + 0x14, node);
                    if (r != 0) {
                        res = r;
                    }
                    if ((*(u32 *)(hdr + 0xC) & 0x8800) == 0x8800 && (u32)(*(s32 *)arg0 - 9) < 2U) {
                        *(s32 *)arg0 = 0xC;
                    } else if (*(u16 *)(hdr + 0xC) & 0x2000) {
                        *(s32 *)arg0 = 5;
                    }
                    node = NULL;
                } else {
                    node = (s32 *)node[1];
                }
            }
            i++;
        } while (i < cnt);
    }
    return res;
}
