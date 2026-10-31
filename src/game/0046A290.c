#include "common.h"

extern void func_0046B4C0(void);
extern s32 D_0021DE10;
extern s32 D_241B00_[];
#define D_241B00 (D_241B00_[0])

void *D_0021F194 = 0;
s32 D_0021F198 = 0;
u8 D_0021F1B0 = 0;

/* Calls func_0046B4C0, sets a flag and the state word from arg0, then calls the callback at D_0021F194 + 4. */
void func_0046A290(s32 arg0) {
    void (*fn)(s32);
    func_0046B4C0();
    if (D_0021DE10 == 1 || D_0021DE10 == 0x15) {
        if (D_0021F198 < 8 && D_241B00 == 0) {
            D_0021F1B0 = 1;
        }
    }
    D_0021F198 = arg0;
    fn = *(void (**)(s32))((u8 *)D_0021F194 + 4);
    fn(arg0);
}
