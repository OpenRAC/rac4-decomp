#include "common.h"
typedef struct {
    char pad[0xA8];
    char *fA8;
    char padAC[0x34];
} State;
extern State D_00237000[];
extern char *D_0023AB10[];
extern int D_00221E28;
extern void func_00463E08(void);
void func_00464038(int index)
{
    D_00237000[0].fA8 = ((char **)((char *)D_00237000 + 0xE0))[index];
    func_00463E08();
    D_00237000[0].fA8 = D_0023AB10[0] + D_00221E28;
}
