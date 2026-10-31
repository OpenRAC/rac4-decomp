/* Not matching yet: BYTES 7/84 (tools/try_func.py func_01EE918C --diff). Not part of the build. */
/* Calls the method at +0x2C of each object in the null-terminated list that starts at +4 of the object func_01EF2CC4 returns. */
extern void *func_01EF2CC4(void);
void func_01EE918C(void) {
    void **base = (void **)func_01EF2CC4();
    void **e;
    if (base[1] != 0) {
        e = base + 1;
        do {
            void *obj = *e;
            void (*f)(void *);
            f = *(void (**)(void *))((u8 *)*(void **)obj + 0x2C);
            e++;
            f(obj);
        } while (*e != 0);
    }
}
