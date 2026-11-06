/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Record {
    u32 words[4];
} Record;

extern s32 D_001647B0[];
extern Record D_001A90C0[];
extern void func_0012A970(void);
extern s32 func_00126BE0(s32 semaphore);
extern s32 func_00126BC0(s32 semaphore);

Record *func_0012AB60(s32 index)
{
    Record *record;

    func_0012A970();
    func_00126BE0(D_001647B0[0]);
    if ((u32)index >= 32) {
        func_00126BC0(D_001647B0[0]);
        return 0;
    }
    record = &D_001A90C0[index];
    func_00126BC0(D_001647B0[0]);
    return record;
}
