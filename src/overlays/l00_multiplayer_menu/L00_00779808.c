#include "common.h"
typedef struct { char data[48]; } Payload;
typedef struct { char pad[0x121]; u8 f121; char pad2[2]; Payload f124; } Target;
typedef struct { char pad[0x1d]; u8 f1d; char pad2[0x46]; Target *f64; } Context;
extern Context *D_002233A4;
/* Update the selected payload when the context is enabled. */
void func_L00_00779808(Payload *arg0) {
    Context *ctx = D_002233A4;
    Target *target = ctx->f64;
    if (!ctx->f1d) {
        target->f121 = 0;
        target->f124 = *arg0;
    }
}
