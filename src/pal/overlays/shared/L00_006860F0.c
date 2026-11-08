#include "common.h"

extern void *func_0011A370(void *, const void *, unsigned int);

/* PAL: from rac2-decomp's func_00350460 */
int func_L00_006860F0(char *dst1, int pos, char *dst2, int size, char *src1, int len1, char *src2, int len2)
{
    int rest;
    if (pos + size < len1 + len2)
        return 0;
    if (len1 >= pos) {
        func_0011A370(dst1, src1, pos);
        func_0011A370(dst2, src1 + pos, len1 - pos);
        func_0011A370(dst2 + len1 - pos, src2, len2);
    } else {
        rest = pos - len1;
        if (len2 >= rest) {
            func_0011A370(dst1, src1, len1);
            func_0011A370(dst1 + len1, src2, rest);
            func_0011A370(dst2, src2 + pos - len1, len2 - rest);
        } else {
            func_0011A370(dst1, src1, len1);
            func_0011A370(dst1 + len1, src2, len2);
        }
    }
    return len1 + len2;
}
