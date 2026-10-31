/* Not matching yet: BYTES 14/116 (tools/try_func.py func_004E55C0 --diff). Not part of the build. */
extern void *D_22140C;

/* Walks 0x100-byte records from D_22140C up to a 0xFF tag; sets or clears bit 0x80 of the u16 at 0x34 for records with flag bit 0x80 clear and type 0x183A or 0x183C. */
void func_004E55C0(s32 arg0) {
    u8 *p;
    u8 tag;
    s16 type;
    u16 v;

    p = D_22140C;
    tag = p[0x20];
    if (tag != 0xFF) {
        do {
            if ((tag & 0x80) == 0) {
                type = *(s16 *)(p + 0xBC);
                if (type == 0x183A || type == 0x183C) {
                    v = *(u16 *)(p + 0x34);
                    if (arg0 != 0) {
                        v = v | 0x80;
                    } else {
                        v = v & 0xFF7F;
                    }
                    *(u16 *)(p + 0x34) = v;
                }
            }
            p += 0x100;
            tag = p[0x20];
        } while (tag != 0xFF);
    }
}
