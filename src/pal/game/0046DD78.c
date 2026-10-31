/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division -IC:/Users/shaar/Documents/Dev/rac4-decomp/include -IC:/Users/shaar/Documents/Dev/rac4-decomp/tools/ext/rac3-decomp -IC:/Users/shaar/Documents/Dev/rac4-decomp/tools/ext/rac3-decomp/include -IC:/Users/shaar/Documents/Dev/rac4-decomp/tools/ext/rac3-decomp/src/levels/shared */
#include "common.h"

extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 func_L01_0043B568(s32 a0, s32 a1);
typedef s32 (*Fn438488)(s32, s32, void *);
extern u8 *func_L01_0045E420(s32);
extern s32 D_00221540;
extern s32 D_001E0058;
extern s32 D_002642A0[];
extern s32 D_001E00C8;
extern s32 D_002642A0[];
typedef struct { s16 v[24]; } Ent_00438670;
extern Ent_00438670 D_002646E0[];
extern s32 D_00221540;
extern u8 *D_002214F4;


/* localdecomp:start func_0046DD78 */
extern s32 D_002642A0[];
extern Ent_00438670 D_002646E0[];
typedef struct { s16 v[24]; } Ent_00438760;
extern s32 D_00221540;
extern u8 *D_002214F4;
s32 func_0046DD78(s32 idx, u8 *obj) {
    Ent_00438760 *e;
    s32 key;
    s32 i;
    if (*(Ent_00438760 **)((u8 *)((Ent_00438760 * *)&D_002642A0) + idx * 4) == 0) {
        return 0;
    }
    e = (Ent_00438760 *)((u8 *)((Ent_00438760 *)&D_002646E0) + (idx - D_00221540) * 48);
    key = (obj - D_002214F4) >> 8;
    for (i = 0; i < 24; i++) {
        if ((e->v[i] & 0x7FFF) == key) {
            obj[33] = 0xFF;
            if (e->v[i] & 0x8000) {
                if (i == 0) {
                    *(Ent_00438760 **)((u8 *)((Ent_00438760 * *)&D_002642A0) + idx * 4) = 0;
                } else {
                    e->v[i - 1] |= 0x8000;
                }
            } else {
                for (; i < 23; i++) {
                    e->v[i] = e->v[i + 1];
                }
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_0046DD78 */
