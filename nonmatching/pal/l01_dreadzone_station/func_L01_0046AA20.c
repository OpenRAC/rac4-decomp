/* Not matching yet: 12/15 (80.00%) relocation-masked positional words; 60/60 candidate/target bytes. Constant load scheduling differs; caller return contract remains unproved. Reproduce: python tools/check_func.py --version pal func_L01_0046AA20 nonmatching/pal/l01_dreadzone_station/func_L01_0046AA20.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* Refresh the flag from the six byte-sized entries. */
unsigned int func_L01_0046AA20(void *arg)
{
    unsigned char *base = *(unsigned char **)((unsigned char *)arg + 0xac);
    unsigned char *entry = base + 0x47c;
    int remaining = 5;
    unsigned int value;
    base[0x501] = 0;
    do {
        value = *entry;
        --remaining;
        if (*entry) {
            if (value == 9)
                base[0x501] = 1;
        }
        ++entry;
    } while (remaining >= 0);
    return value;
}
