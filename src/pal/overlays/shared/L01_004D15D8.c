/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern void func_L01_004D14E8(void *, s32);
#include "pal/l01_0046DD08.h"
extern void func_L01_004D10B0(void *, s32);

// When the linked object's +0x2DD flag is set run func_L01_004D10B0 and stop.
// Otherwise, if +0x2FC is zero, call the callback registered under id 0x277E (if
// any); finish with func_L01_004D14E8(object, 0x64).
void func_L01_004D15D8(u8 *object) {
    u8 *linked = *(u8 **)(object + 0xAC);
    void **table;
    void (*callback)(void *);
    if (linked[0x2DD] != 0) {
        func_L01_004D10B0(object, 1);
        return;
    }
    if (*(s32 *)(linked + 0x2FC) == 0) {
        table = func_0046DD08(0x277E, 0, 4);
        if (table != 0 && *table != 0) {
            callback = (void (*)(void *))*table;
            callback(object);
        }
    }
    func_L01_004D14E8(object, 0x64);
}
