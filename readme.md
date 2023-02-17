
## Setup

To load all paths use
```bash
source setup.sh
```

## CMake

Building:
```bash
cmake -B build
cmake --build build
```

Very verbose log:
```bash
cmake --build build -- -vvv -DEXTRA_FLAGS="-save-temps" > build.log 2>&1
```

Building in parallel with `cmake`:
```bash
cmake --build build -- -j 10
```

## West

Can still be used for building after creating the `build` configuration, but don't use `west build` before since it needs a `BOARD` definition, which is already specified in the [CMakeLists.txt](CMakeLists.txt).
