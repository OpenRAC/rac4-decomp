/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern void func_0011A518(void *, int, int);

/* Initialize the state and clear its 64-byte buffer. */
void func_L00_0051B938(unsigned int *state)
{
    state[0] = 0x67452301;
    state[1] = 0xEFCDAB89;
    state[2] = 0x98BADCFE;
    state[3] = 0x10325476;
    state[4] = 0;
    state[5] = 0;
    state[22] = 0;
    func_0011A518(state + 6, 0, 0x40);
}
