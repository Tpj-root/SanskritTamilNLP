cmake_minimum_required(VERSION 3.10)
project(SanskritTamilNLP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------
# Collect source files
# ----------------------------------
file(GLOB_RECURSE ENGINE_SRC
    src/engine/*.cpp
    src/core/*.cpp
    src/grammar/*.cpp
    src/phoneme/*.cpp
)

# ----------------------------------
# Main application
# ----------------------------------
add_executable(SanskritTamilNLP
    src/main.cpp
    ${ENGINE_SRC}
)

target_include_directories(SanskritTamilNLP PRIVATE src)

# ----------------------------------
# Unit test executable
# ----------------------------------
add_executable(SanskritTamilNLP_Test
    src/test.cpp
    ${ENGINE_SRC}
)

target_include_directories(SanskritTamilNLP_Test PRIVATE src)



Good catch 👌 — this is **expected behavior**, not an error.
Let me explain it **clearly and simply**.

---

## Why it builds “two times”

You defined **TWO executables** in CMake:

1. **`SanskritTamilNLP`** → your main program
2. **`SanskritTamilNLP_Test`** → your unit tests

Both of them use the **same source files**:

```
core/*.cpp
engine/*.cpp
grammar/*.cpp
phoneme/*.cpp
```

### What CMake must do

CMake **cannot reuse object files between executables** by default.

So it does this:

* Compile sources → for **main executable**
* Compile the same sources again → for **test executable**
* Link each separately

That’s why you see:

```
GrammarRule.cpp.o   (for main)
GrammarRule.cpp.o   (for test)
```

Same code → different targets → built twice.

✔ This is **normal**
✔ This is **correct**
✔ This is **safe**

---

## How to confirm (mental model)

Think like this:

> One engine, two cars
> Each car needs its own engine copy

---

## ✅ BEST PRACTICE (fix double compilation)

Turn shared code into a **library**, then link it.

### Clean architecture

```
[ core / engine / grammar / phoneme ] → libSanskritEngine.a
                         ↘            ↙
                    main app      unit test
```

---

## 🔧 Improved CMake (library-based)

```cmake
cmake_minimum_required(VERSION 3.10)
project(SanskritTamilNLP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------
# Shared library
# ----------------------------------
file(GLOB_RECURSE ENGINE_SRC
    src/core/*.cpp
    src/engine/*.cpp
    src/grammar/*.cpp
    src/phoneme/*.cpp
)

add_library(SanskritEngine STATIC ${ENGINE_SRC})
target_include_directories(SanskritEngine PUBLIC src)

# ----------------------------------
# Main executable
# ----------------------------------
add_executable(SanskritTamilNLP src/main.cpp)
target_link_libraries(SanskritTamilNLP SanskritEngine)

# ----------------------------------
# Test executable
# ----------------------------------
add_executable(SanskritTamilNLP_Test src/test.cpp)
target_link_libraries(SanskritTamilNLP_Test SanskritEngine)
```

---

## What changes now

* Shared code compiles **ONCE**
* Faster builds
* Cleaner dependency graph
* Professional CMake layout

---

## When double-build is OK

* Small projects
* Early prototypes
* Few source files

## When library is better

* Growing project (you are here ✅)
* Tests
* CI/CD
* Future reuse

---

If you want next:

* `ctest` integration
* install/export library
* split grammar vs phoneme libs
* performance flags

Just say it 👍
