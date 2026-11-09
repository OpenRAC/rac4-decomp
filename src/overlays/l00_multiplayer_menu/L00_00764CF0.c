/* cflags: -G0 */
#include "common.h"

void func_L00_00764C68(void);
extern s32 D_00221748[];
extern void *D_004EE658[];
void *func_L00_00764CF0(s32 arg0) {
    void *r;
    if (D_004EE658[0] == NULL) {
        func_L00_00764C68();
    }
    if (arg0 < 8) {
        r = D_004EE658[arg0];
    } else {
        r = D_00221748;
    }
    return r;
}
