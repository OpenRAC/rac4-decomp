#include "common.h"
typedef struct { unsigned char bytes[40]; } __attribute__((packed)) Type1;
extern void *D_002233A4;
/* Clear the flag and copy the record. */
void func_L00_0077C7B0(Type1 *arg0) {
    unsigned char *state = *(unsigned char **)((unsigned char *)D_002233A4 + 0x68);
    state[0x2F5D] = 0;
    *(Type1 *)(state + 0x2F60) = *arg0;
}
