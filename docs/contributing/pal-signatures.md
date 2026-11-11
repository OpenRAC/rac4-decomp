# Reviewed PAL call contracts

[`config/pal/function_signatures.json`](../../config/pal/function_signatures.json)
records reusable interfaces checked against RAC4 PAL main-image code. Consult it
before reconstructing a caller. It is evidence metadata, not a shared C header:
opaque structure views and address-named globals still need local declarations.

`confirmed_contract` means the listed interface is supported by implementation
and caller behavior. `confirmed_abi` records a physical calling requirement when
the exact original C type is not established. Neither status claims to recover a
unique original declaration. Several C declarations can compile identically.

For each addition, record the PAL catalogue address, return behavior, argument
locations and widths, pointer/output requirements, evidence addresses or source
paths, and remaining uncertainty. A saved 64-bit register does not by itself
prove a 64-bit value. A register left populated at return does not prove a return
value. Reconstruct real uses and consumers.

Include outgoing stack arguments. For example, `func_00507270` consumes eight
GPR arguments plus a ninth stack argument. A local variable that happens to
occupy the same stack slot does not express that C calling contract.

Use unsigned arithmetic for target bit masks and inspect shift ranges. Verify
that callees initialize every consumed output on every relevant path. Do not
invent object extents, array bounds or initializers to obtain a byte match.

When an existing declaration conflicts with this ledger, inspect the evidence
before changing either. Mark unresolved interfaces explicitly; never promote a
guess solely because the masked instruction comparison reports `MATCH`.

The original binaries and generated instruction listings remain local. Evidence
addresses and public source references suffice for this ledger; do not commit
disc data, extracted binaries, toolchains or proprietary SDK material.
