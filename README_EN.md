# PathToBot

> **Project archived.** Development is paused but may be resumed in the future.

[Русская версия](README.md)

---

Game bot written in Rust, loaded as a DLL into the game process.

## Features

- **AOB scanning** — pattern (signature) search in process memory with wildcard byte support (`??`)
- **Mid-function hooks** — hooks placed directly inside functions via inline ASM; extracts addresses straight from registers (rcx, rax, rdi, etc.) instead of pointer chains
- **MinHook** — function interception and argument replacement
- **Relay Cave** — memory allocation within ±2 GB range to work around x64 JMP limitations

## Structure

```
src/
├── lib.rs            # Entry point (DllMain)
├── memory.rs         # AOB scanner, mid-function hook installation, RIP resolution
├── config.rs         # Patterns (signatures)
├── game/
│   ├── client.rs     # Initialization, hook setup, coordinate reading
│   ├── hooks.rs      # Naked functions for mid-function hooks (inline ASM)
│   └── player.rs     # Player structure
├── bot/
│   └── actions.rs    # Automation logic
└── ui/
    └── mod.rs        # Interface (has not realized)
```

## Building

```bash
cargo build --release
```

Output: `target/release/PathToBot.dll`
