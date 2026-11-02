#include "common.h"
typedef struct { int value; char rest[12]; } SourceEntry;
typedef struct { char pad[0x18]; SourceEntry entries[9]; unsigned char a; char pad2[11]; unsigned char b; } Source;
typedef struct { int values[8]; } DestEntry;
typedef struct { DestEntry entries[9]; unsigned char a[8]; unsigned char b[8]; int fields[4]; } Dest;
extern Source D_00171D38[];
extern Dest D_001DFAB0[];
void func_L00_005C89B0(void) {
    int i;
    for (i = 0; i < 8; i++) {
        D_001DFAB0[0].entries[0].values[i] = D_00171D38[0].entries[0].value;
        D_001DFAB0[0].entries[1].values[i] = D_00171D38[0].entries[1].value;
        D_001DFAB0[0].entries[2].values[i] = D_00171D38[0].entries[2].value;
        D_001DFAB0[0].entries[3].values[i] = D_00171D38[0].entries[3].value;
        D_001DFAB0[0].entries[4].values[i] = D_00171D38[0].entries[4].value;
        D_001DFAB0[0].entries[5].values[i] = D_00171D38[0].entries[5].value;
        D_001DFAB0[0].entries[6].values[i] = D_00171D38[0].entries[6].value;
        D_001DFAB0[0].entries[7].values[i] = D_00171D38[0].entries[7].value;
        D_001DFAB0[0].entries[8].values[i] = D_00171D38[0].entries[8].value;
        D_001DFAB0[0].a[i] = D_00171D38[0].a;
        D_001DFAB0[0].b[i] = D_00171D38[0].b;
    }
    D_001DFAB0[0].fields[0] = -1;
    D_001DFAB0[0].fields[1] = -1;
    D_001DFAB0[0].fields[2] = -1;
    D_001DFAB0[0].fields[3] = -1;
}
