/* cflags: @ee29 -O2 -G8 */
#include "common.h"
extern void func_004FAD28(void *);
extern void func_L00_005205F8(void *);
void func_L00_0051EB68(void *object) {
    u8 *p = object;
    u8 *first = *(u8 **)p;
    void (*callback)(void);
    if (first != 0) {
        callback = *(void (**)(void))(first + 4);
        callback();
    }
    if (*(void **)(p + 4) != 0) func_L00_005205F8(*(void **)(p + 4));
    if ((*(s32 *)(p + 0xC) & 1) == 0) return;
    func_004FAD28(object);
}
