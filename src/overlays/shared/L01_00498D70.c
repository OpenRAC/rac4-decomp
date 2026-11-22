#include "common.h"
typedef struct Blob { u8 b[0x2A0]; } Blob;
extern Blob D_0039DC08;
extern Blob D_0039DEA8;
void func_L01_00498D70(Blob *a, Blob *b) {
    D_0039DC08 = *a;
    D_0039DEA8 = *b;
}
