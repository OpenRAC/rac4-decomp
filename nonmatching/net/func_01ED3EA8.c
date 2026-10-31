/* Not matching yet: BYTES 8/120 (tools/try_func.py func_01ED3EA8 --diff). Not part of the build. */
extern void func_01EA9550(void *, s32);

/* Allocates a block through func_01EA9550 and zeroes its header words and 64 records of 512 bytes; returns the block or NULL. */
void *func_01ED3EA8(void) {
    void *blk;
    u32 i;

    blk = NULL;
    func_01EA9550(&blk, 0x800C);
    if (blk != NULL) {
        *(s32 *)blk = 0;
        *(s32 *)((u8 *)blk + 4) = 0;
        *(s32 *)((u8 *)blk + 8) = 0;
        i = 0;
        do {
            *(s32 *)((u8 *)blk + (i << 9) + 0xC) = 0;
            *(s32 *)((u8 *)blk + (i << 9) + 0x10) = 0;
            i++;
        } while (i < 0x40);
    }
    return blk;
}
