/* Not matching yet: BYTES 4/112 (tools/try_func.py func_0012E3F0 --diff). Not part of the build. */
/* Pops the head node off the list at D_00165D28, tags it, and returns the node index or 0x80008005 when the list is empty. */
extern u8 D_00165D28[];

s32 func_0012E3F0(void) {
    volatile s32 *g = (volatile s32 *)D_00165D28;
    volatile s32 *n;
    s32 temp_a1;
    s32 cnt;
    s32 head;
    s32 c4;
    s32 c3;

    n = (volatile s32 *)g[5];
    if (n != 0) {
        cnt = g[4];
        temp_a1 = (s32)n * 0x10;
        head = n[0];
        c4 = cnt + 1;
        g[4] = c4;
        n[10] = 0;
        n[3] = 0;
        g[5] = head;
        c3 = g[3];
        *(volatile u64 *)(n + 6) = 0;
        g[3] = c3 + 1;
        n[2] = ((g[3] * 2) & 0x3FE) | 1;
        return temp_a1 | n[2];
    }
    return 0x80008005;
}
