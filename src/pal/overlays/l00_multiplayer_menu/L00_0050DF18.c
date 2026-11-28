/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Request Request;

typedef s32 (*PrepareRequest)(u32 source, Request **request);
typedef s32 (*PrepareRequestWithOptions)(u32 source, u32 options, Request **request);
typedef s32 (*TransferRequest)(Request *request, void *buffer, u32 position, u32 count);
typedef s32 (*FinishRequest)(Request *request);

extern s32 func_L00_0050D1F8(u32 source, Request **request);
extern s32 func_L00_0050D2E8(u32 source, u32 options, Request **request);
extern s32 func_L00_0050D6F8(Request *request, void *buffer, u32 position, u32 count);
extern s32 func_L00_0050D780(Request *request);

extern s32 func_L00_0050D930(u32 source, Request **request);
extern s32 func_L00_0050DA20(u32 source, u32 options, Request **request);
extern s32 func_L00_0050DE30(Request *request, void *buffer, u32 position, u32 count);
extern s32 func_L00_0050DEB8(Request *request);

extern s32 func_L00_0055A770(u32 source, Request **request);
extern s32 func_L00_0055AC70(Request *request, void *buffer, u32 position, u32 count);
extern s32 func_L00_0055ACF8(Request *request);

extern s32 func_003F66F0(u32 source, u32 options, Request **request);
extern s32 func_003F6978(Request *request, void *buffer, u32 position, u32 count);
extern s32 func_003F69F0(Request *request);

static inline s32 transfer_and_finish(s32 status, Request **request, void *buffer,
                                      u32 position, u32 count, TransferRequest transfer,
                                      FinishRequest finish)
{
    if (status != 0 || transfer(*request, buffer, position, count) != 0)
        return -1;
    return finish(*request) == 0 ? 0 : -1;
}

static inline s32 run_transfer(void *buffer, u32 source, u32 position, u32 count,
                               PrepareRequest prepare, TransferRequest transfer,
                               FinishRequest finish)
{
    Request *request;
    return transfer_and_finish(prepare(source, &request), &request, buffer,
                               position, count, transfer, finish);
}

static inline s32 run_transfer_with_options(void *buffer, u32 source, u32 position,
                                            u32 options, u32 count,
                                            PrepareRequestWithOptions prepare,
                                            TransferRequest transfer, FinishRequest finish)
{
    Request *request;
    return transfer_and_finish(prepare(source, options, &request), &request, buffer,
                               position, count, transfer, finish);
}

s32 func_L00_0050DF18(void *buffer, u32 source, u32 position, u32 count)
{
    return run_transfer(buffer, source, position, count, func_L00_0050D1F8,
                        func_L00_0050D6F8, func_L00_0050D780);
}

s32 func_L00_0050DFA0(void *buffer, u32 source, u32 position, u32 count)
{
    return run_transfer(buffer, source, position, count, func_L00_0050D930,
                        func_L00_0050DE30, func_L00_0050DEB8);
}

s32 func_L00_0055AD60(void *buffer, u32 source, u32 position, u32 count)
{
    return run_transfer(buffer, source, position, count, func_L00_0055A770,
                        func_L00_0055AC70, func_L00_0055ACF8);
}

s32 func_L00_0050E028(void *buffer, u32 source, u32 position, u32 options, u32 count)
{
    return run_transfer_with_options(buffer, source, position, options, count,
                                     func_L00_0050D2E8, func_L00_0050D6F8, func_L00_0050D780);
}

s32 func_L00_0050E230(void *buffer, u32 source, u32 position, u32 options, u32 count)
{
    return run_transfer_with_options(buffer, source, position, options, count,
                                     func_L00_0050DA20, func_L00_0050DE30, func_L00_0050DEB8);
}

s32 func_L00_0055ADE8(void *buffer, u32 source, u32 position, u32 options, u32 count)
{
    return run_transfer_with_options(buffer, source, position, options, count,
                                     func_003F66F0, func_003F6978, func_003F69F0);
}
