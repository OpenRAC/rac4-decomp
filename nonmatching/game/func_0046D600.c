/* Not matching yet: BYTES 53/100 (tools/try_func.py func_0046D600 --diff). Not part of the build. */
extern int D_2480E0[];

void func_0046D600(void) {
    int i;
    for (i = 0; i < 0x1000; i++) {
        int v = D_2480E0[i];
        if (v != 0) {
            int c = (v >> 16) & 0xFF;
            if (c != 0) {
                do {
                    c--;
                } while (c != 0);
            }
        }
    }
}
