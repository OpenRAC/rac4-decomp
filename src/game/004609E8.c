#include "common.h"
extern int func_0012C438(void);
extern void func_00460018(void);
extern void (*func_00460498(int))(void *);
typedef struct { char pad0[8]; int source; int elapsed; int remaining; char pad1[0x144]; unsigned char enabled; char pad2[0xb]; int key; } Entry;
static __inline__ unsigned int address_add(unsigned int offset, unsigned int base) { return offset + base; }
/* Executes registered callbacks and measures their elapsed time. */
void func_004609E8(int *arg0) {
    int i = *arg0 - 1;
    if (i >= 0) {
        int offset = i * 0x168;
        unsigned int interior = address_add(offset + 0x20, (unsigned int)arg0);
        unsigned int base = address_add(offset + 0x10, (unsigned int)arg0);
        do {
            int start = func_0012C438();
            void (*callback)(void *) = func_00460498(((Entry *)(interior - 0x10))->key);
            if (((Entry *)(interior - 0x10))->enabled && callback) {
                callback((void *)base);
                func_00460018();
            }
            base -= 0x168;
            ((Entry *)(interior - 0x10))->elapsed = func_0012C438() - start;
            i--;
            ((Entry *)(interior - 0x10))->remaining = ((Entry *)(interior - 0x10))->source - ((Entry *)(interior - 0x10))->elapsed;
            interior -= 0x168;
        } while (i >= 0);
    }
}
