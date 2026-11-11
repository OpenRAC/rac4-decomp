/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C8950 (src/levels/39_multiplayer_menu/L39_004C8568.c, GPL-3.0), the same code in both games. */

extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
typedef struct {
    void *x509;
    void *privatekey;
} PK_004C8950;
typedef struct {
    s32 peer_cert_type;
    u8 pad4[0x1C];
    void *rsa_a;
    void *rsa_b;
    void *rsa_c;
    void *dh_a;
    void *dh_b;
    u8 pad34[0xC];
    PK_004C8950 peer_pkeys[1];
} SC_004C8950;
typedef struct {
    u8 pad0[0x90];
    SC_004C8950 *sess_cert;
} SESS_004C8950;
typedef struct {
    u8 pad0[0x10];
    long algorithms;
    long algo_strength;
} CIPH_004C8950;
typedef struct {
    u8 pad0[0x15C];
    CIPH_004C8950 *new_cipher;
} S3_004C8950;
typedef struct {
    u8 pad0[0x54];
    S3_004C8950 *s3;
    u8 pad58[0x58];
    SESS_004C8950 *session;
} SSL_004C8950;
extern void *func_L00_004F7B08(void *);
extern void *func_L00_004F7BE0(void *);
extern s32 func_L00_00507EB0(void *, void *);
extern u32 func_L00_005263A8(void *);
extern u32 func_L00_005190D8(void *);
extern void func_L00_00505D50(SSL_004C8950 *, s32, s32);
s32 func_L00_00504750(SSL_004C8950 *s) {
    s32 i;
    s32 idx;
    long algs;
    long strength;
    SC_004C8950 *sc;
    void *rsa = 0;
    void *dh;
    sc = s->session->sess_cert;
    if (sc == 0) {
        func_L00_004F84C8(0x14, 0x82, 0x9D, 0, 0);
        return 0;
    }
    algs = s->s3->new_cipher->algorithms;
    strength = s->s3->new_cipher->algo_strength;
    if (algs & 0x300) {
        return 1;
    }
    if (algs & 0x100000) {
        if ((s32)(strength & 0xFF00) == 0x400) {
            rsa = sc->rsa_c;
        }
        if (rsa == 0) {
            rsa = sc->rsa_b;
        }
        dh = sc->dh_b;
    } else {
        rsa = sc->rsa_a;
        dh = sc->dh_a;
    }
    idx = sc->peer_cert_type;
    i = func_L00_00507EB0(func_L00_004F7B08(sc->peer_pkeys[idx].x509),
                          func_L00_004F7BE0(sc->peer_pkeys[idx].x509));
    if ((algs & 0x20) && (i & 0x11) != 0x11) {
        func_L00_004F84C8(0x14, 0x82, 0xAA, 0, 0);
        goto f_err;
    } else if ((algs & 0x40) && (i & 0x12) != 0x12) {
        func_L00_004F84C8(0x14, 0x82, 0xA5, 0, 0);
        goto f_err;
    }
    if ((algs & 0x1) && !((i & 0x21) == 0x21 || rsa != 0)) {
        func_L00_004F84C8(0x14, 0x82, 0xA9, 0, 0);
        goto f_err;
    }
    if ((algs & 0x10) && !((i & 0x44) == 0x44 || dh != 0)) {
        func_L00_004F84C8(0x14, 0x82, 0xA3, 0, 0);
        goto f_err;
    } else if ((algs & 0x2) && (i & 0x104) != 0x104) {
        func_L00_004F84C8(0x14, 0x82, 0xA4, 0, 0);
        goto f_err;
    } else if ((algs & 0x4) && (i & 0x204) != 0x204) {
        func_L00_004F84C8(0x14, 0x82, 0xA2, 0, 0);
        goto f_err;
    }
    if ((algs & 0x100000) && !(i & 0x1000)) {
        if (algs & 0x1) {
            if (rsa == 0 || func_L00_005263A8(rsa) > (s32)(strength & 0xFF00)) {
                func_L00_004F84C8(0x14, 0x82, 0xA7, 0, 0);
                goto f_err;
            }
        } else if (algs & 0x16) {
            if (dh == 0 || func_L00_005190D8(dh) > (s32)(strength & 0xFF00)) {
                func_L00_004F84C8(0x14, 0x82, 0xA6, 0, 0);
                goto f_err;
            }
        } else {
            func_L00_004F84C8(0x14, 0x82, 0xFA, 0, 0);
            goto f_err;
        }
    }
    return 1;
f_err:
    func_L00_00505D50(s, 2, 0x28);
    return 0;
}
