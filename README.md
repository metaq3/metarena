# Metarena

#### CPM + Freeze OSP-like mod

This is an attempt to create an open-source server mod for freeze-tag with variety of physics and support for OSP and OSP2 clients.

Based on:

- baseq3a from Cyrax: https://github.com/ec-/baseq3a
- Unlagged mod by Nail Toronto ( included in baseq3a )
- Open Source Defrag: https://github.com/OpenQuake3/defrag
- Freeze Tag: https://github.com/dbircsak/freeze-tag

Also huge thanks to OSP2 contributors, especially snems. You can check out their work: https://github.com/snems/OSP2

## What have been done

- Support for OSP clients
- Full OSP2-BE support
- Support for vanilla, CPM, Q1 and CQ3 physics
- Freeze tag with common OSP features

## Configuration

Docs available:

- [Commands](./docs/commands.md)
- [Quick setup](./docs/quick-setup.md)

## Build

Currently build is only available for linux, with QVM and \*.so the only
supported targets.

### QVM

Go into `build/linux-qvm` folder and run in the terminal:

```bash
make
```

Soon, `pak8a.pk3` will appear in the same folder. This is
your mod.

### Native libraries

Go to `build/linux` and run in the terminal:

```bash
make
```

Result will appear in the build directory.
