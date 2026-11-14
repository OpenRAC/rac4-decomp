#include "common.h"

extern void *func_0047C510(void *);
extern void *func_00476F70(void *);

void func_L01_005A7088(void *arg0) {
    u8 *cfg;
    u8 *data;
    void *object;
    void **slot;
    s32 offset;
    s32 i;

    cfg = func_0047C510(arg0);
    if (cfg != NULL) {
        object = *(void **)(cfg + 0x10);
        if (object != NULL && *(s16 *)(cfg + 0x16) != 2) {
            *(s16 *)(cfg + 0x16) = 2;
            data = func_00476F70(object);
            if (data != NULL) {
                for (i = 0; i < 8; i++) {
                    offset = i * 4;
                    slot = (void **)(data + 0x50);
                    if (*(void **)((u8 *)slot + offset) == NULL) {
                        *(void **)((u8 *)slot + offset) = arg0;
                        break;
                    }
                }
                *(s32 *)(data + 0x4C) += *(s32 *)(cfg + 0x40);
            }
        }
    }
}
