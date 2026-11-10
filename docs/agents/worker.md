# Worker guide

For an agent working on one function. Your prompt gives FUNC and BUDGET;
`tools/wave.py plan` wrote `build/try/<FUNC>/CONTEXT.md` (the function's
packet) and claimed the function for you. The rules, the candidate format,
reading the assembly, codegen and walls are those of
[queue.md](queue.md): read it, then follow this file instead of its "Loop".

## Matching

1. Read `CONTEXT.md`: the function's size and the file it lands in, the
   declarations of what it calls and uses, its assembly, an m2c draft and
   matched C nearby. If there were earlier attempts, read
   `build/try/<FUNC>/NOTES.md` and start from the best candidate
   (`best.c` when the packet shows one); don't repeat what failed.
2. List every global and how retail reaches it (`$gp` or `lui`); that
   decides the declarations. Compare the assembly with the walls in
   queue.md. If it hits one, say which in NOTES.md and stop.
3. Write each candidate as `build/try/<FUNC>/pN.c`, starting at the number
   the packet header gives, a new file each time.
4. Test with
   `venv/bin/python tools/try_func.py <FUNC> build/try/<FUNC>/pN.c --diff`.
   Every run counts against your budget; try_func prints `run k of N` and
   refuses once it is spent. Change one thing at a time and keep only what
   improves the verdict.
5. When the instructions are right and only the `lui` temporary differs, or
   a `lui` retail repeats, spend one run on a
   `/* cflags: -mno-split-addresses */` first line.
6. Stop at `EXACT`, when the budget runs out, or when three variants in a
   row compile to the same bytes. Then add a section to `NOTES.md` (below
   any earlier ones, never deleting them): what the function does, what
   you tried, what mattered, where any remaining difference is.
7. End with a one-line reply: `<best verdict> | <best candidate path> | <runs used>`.

The lead reads the verdicts from `build/try/<FUNC>/runs.log` (try_func
writes it), lands what is EXACT and stages what came close.
