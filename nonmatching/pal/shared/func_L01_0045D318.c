/* Not matched: PAL SCES_532.85.
 * BYTES 10/44 (4 words differ). 12 actual placement(s).
 * 34/44 bytes agree positionally at every placement; this is not correctness certification.
 * Object/state pointer contract and conditional sentinel reads are supported by actual callers and matched sources. A common-result copy versus dual returns still differs. Fresh public PR167 comparison is retained; no original-type uniqueness or runtime invocation is claimed.
 * Reproduce: python3 tools/check_func.py --version pal func_L01_0045D318 nonmatching/pal/shared/func_L01_0045D318.c --diff
 */
#include "common.h"

static inline s32 has_no_sentinel(const u8 *state)
{
    return *(const s32 *)(state + 0x600) != -1;
}

s32 func_L01_0045D318(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    s32 result;
    if (state[0x618] == 1) {
        result = has_no_sentinel(state);
    } else {
        result = 0;
    }
    return result;
}
