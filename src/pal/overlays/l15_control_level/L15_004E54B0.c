/* cflags:  */
typedef struct { char pad[0x108]; void *child; } Inner;
typedef struct { char pad0[0x54]; unsigned char state; char pad1[0x14]; unsigned char kind; char pad2[0x42]; Inner *inner; } Actor;
extern void func_00474148(Actor *, int, int, float);
/* Select an animation for the actor or its child. */
void func_L15_004E54B0(Actor *a, int b, int c, int d)
{
    Inner *inner = a->inner;
    if (a->kind == 3) {
        switch (b) { case 0: b = 13; break; case 1: b = 16; break; default: break; }
        if (a->state != 11) func_00474148(a, 11, 0, 0.0f);
        func_00474148(inner->child, b - 13, d, (float)c);
    } else if (a->state != b) {
        func_00474148(a, b, d, (float)c);
    }
}
