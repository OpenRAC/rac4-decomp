/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern void func_L05_0048A078(u8 *);
extern void func_L05_004932A0(u8 *);
extern void func_L01_0056F988(u8 *);
extern void func_L01_005713D8(u8 *);
extern void func_0046C6B0(void *);
extern void func_L01_0058CDE8(u8 *);
extern void func_00474368(u8 *, unsigned char, int);
extern void func_L01_005ACCA0(u8 *);
extern void func_004E29B8(u8 *, int);

/* Remove the linked members and finish the object. */
void func_L05_00492668(u8 *moby, int arg1)
{
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 *member;
    u8 *next;

    func_L05_004932A0(moby);
    func_004E29B8(moby, 0);
    member = *(u8 **)(vars + 0x244);
    while (member) {
        next = *(u8 **)(*(u8 **)(member + 0xAC) + 0x2A4);
        func_L05_0048A078(member);
        member = next;
    }
    *(u8 **)(vars + 0x244) = 0;
    func_L01_0056F988(moby);
    func_L01_005713D8(moby);
    func_L01_005ACCA0(moby);
    func_L01_0058CDE8(moby);
    func_00474368(moby, 7, 2);
    if (!vars[0x1A8]) {
        func_L01_0058CDE8(moby);
    } else if (!arg1) {
        func_0046C6B0(moby);
    }
}
