#include "common.h"

extern s32 D_0021DE10;

// Walks a chain of records, copying each payload to its destination when that lies below the bound; stops at the first record whose count changes.
s32 func_00157738(u8 *arg0, u32 arg1) {
    u8 *rec;
    s32 t2 = 0;
    u8 *dst;
    u8 *end;
    u8 *end2;
    u8 *p;
    u8 *s;
    s32 size;

    while (rec = arg0, arg0 = rec + 0x10, dst = *(u8 **)rec, s = arg0,
           t2 == 0 ? (t2 = *(s32 *)(rec + 0xC), 1) : t2 == *(s32 *)(rec + 0xC)) {
        size = *(s32 *)(rec + 4);
        if ((u32)(D_0021DE10 - 1) >= 0x27 || ((u32)dst < arg1 && (u32)(dst + size) < arg1)) {
            if (size != 0) {
                if ((size & 7) == 0 && ((u32)arg0 & 7) == 0 && ((u32)dst & 7) == 0) {
                    end = dst + size;
                    p = dst;
                    s = arg0;
                    while (p != end) {
                        *(u64 *)p = *(u64 *)s;
                        p += 8;
                        s += 8;
                    }
                } else if ((size & 3) == 0 && ((u32)arg0 & 3) == 0 && ((u32)dst & 3) == 0) {
                    end2 = dst + size;
                    while (dst != end2) {
                        *(s32 *)dst = *(s32 *)s;
                        dst += 4;
                        s += 4;
                    }
                } else {
                    end = dst + size;
                    p = dst;
                    s = arg0;
                    while (p != end) {
                        *p = *s;
                        p++;
                        s++;
                    }
                }
            }
        }
        arg0 += (*(s32 *)(rec + 4) + 3) & ~3;
    }
    return t2;
}
