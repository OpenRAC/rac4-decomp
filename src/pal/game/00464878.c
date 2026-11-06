#include "common.h"
typedef struct {
    char pad[0xA8];
    char *fA8;
    char padAC[0x34];
} State;
extern State D_00237100[];
extern char *D_0023AC10[];
extern int D_00221F28;
extern void func_00464648(void);
void func_00464878(int index)
{
    D_00237100[0].fA8 = ((char **)((char *)D_00237100 + 0xE0))[index];
    func_00464648();
    D_00237100[0].fA8 = D_0023AC10[0] + D_00221F28;
}
