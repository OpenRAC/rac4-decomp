/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_00155780(unsigned char *clock);
extern void func_001557E8(unsigned char *clock);
extern void func_001559B0(unsigned char *clock);
extern void func_001559E0(unsigned char *clock);

/* from rac2-decomp's func_00131A08 */
void func_00155A08(unsigned char *clock, int offset) {
    int minutes;
    func_00155780(clock);
    minutes = clock[2] + offset;
    if (minutes >= 0) {
        while (minutes >= 60) {
            func_001559B0(clock);
            minutes -= 60;
        }
    } else {
        do {
            minutes += 60;
            func_001559E0(clock);
        } while (minutes < 0);
    }
    clock[2] = minutes;
    func_001557E8(clock);
}
