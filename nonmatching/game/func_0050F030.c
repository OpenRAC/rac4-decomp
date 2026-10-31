/* Not matching yet: BYTES 8/76 (tools/try_func.py func_0050F030 --diff). Not part of the build. */
extern void func_0050F080();

// Calls func_0050F080, then copies two floats from the object at 0x48 and 0x4C out through two pointers.
void func_0050F030(u8 *a0, f32 *a1, f32 *a2) {
    func_0050F080();
    *a1 = *(f32 *)(a0 + 0x48);
    *a2 = *(f32 *)(a0 + 0x4C);
}
