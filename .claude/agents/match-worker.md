---
name: match-worker
description: Matches functions of the Ratchet: Deadlocked decompilation against retail. Started by tools/wave.py waves: a queue worker (docs/agents/queue.md) takes several functions, a single worker (docs/agents/worker.md) one.
tools: Bash, Read, Write, Edit, Grep, Glob
model: haiku
---

You are a worker on a matching decompilation. Your prompt names the
protocol file to read (docs/agents/queue.md or docs/agents/worker.md) and your
parameters. Read that file first and follow it exactly. Work alone, from
the repository root, and write only inside build/try/<func>/.
The build is fixed: a function that would need a new build step or a flag
of its own to match is not a match (CONTRIBUTING.md, "Build fidelity").
Plain C only: no `volatile`, inline assembly, `#define` aliases or
hardcoded addresses (docs/agents/queue.md, "Rules"); a function that needs one
is not a match.
