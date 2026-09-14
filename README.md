# TeachMate — C++17 Bootcamp

A 4-week, hands-on C++ course for bachelor students. It moves from the smallest
possible program to modern C++ by **stacking one new layer at a time**, while a
single capstone project ("Gradebook / Student Records Manager") grows along with
the material.

## Who this is for

Students who have never written C++, or who have written a little code in another
language. No prior C/C++ experience is assumed.

## Toolchain (VS Code + a C++17 compiler)

The course targets **C++17** — the sweet spot for teaching: modern enough for
`std::optional`, `std::variant`, structured bindings and move semantics, without
the extra syntax of later standards.

- **Editor:** Visual Studio Code with the **C/C++ extension** (`ms-vscode.cpptools`).
- **Compiler:** MinGW-w64 **GCC** through **MSYS2 (UCRT64)** — the official route.

> **Never installed C++ before? Follow the full walkthrough:
> [`docs/setup-windows.md`](docs/setup-windows.md).**

Short version:

1. Install **VS Code** and **MSYS2** (<https://www.msys2.org/>, default `C:\msys64`).
2. Open **MSYS2 UCRT64**, run `pacman -Syu` (repeat until clean), then:

   ```sh
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
   ```

3. Add `C:\msys64\ucrt64\bin` to your **PATH**, reopen the terminal, and check:

   ```sh
   g++ --version
   ```

Any MinGW-w64 **GCC 13+** works (e.g. WinLibs via
`winget install BrechtSanders.WinLibs.POSIX.UCRT` is a one-command alternative).
If `g++` is not on `PATH`, add its `bin` folder, or set the `CXX` environment
variable to the full path of your `g++.exe` (the `run.cmd` and `build-all.cmd`
scripts honour `CXX`).

### Quick start (VS Code)

1. Open the `TeachMate` folder in VS Code (**File → Open Folder…**).
2. Open any lesson, e.g. `CPP/week1/lesson01_hello/main.cpp`.
3. **Ctrl+Shift+B** builds it; **F5** builds and debugs it.
   Output goes to `build/<lesson>.exe`.
4. If VS Code asks, install the **C/C++** extension
   (Extensions view → search `C/C++` → Install).

### Quick start (terminal)

From the `CPP` folder:

```sh
run.cmd week1\lesson01_hello
```

This compiles and runs one lesson with the same compiler and flags.

## Why one file per lesson?

Every lesson is a **single `main.cpp`**. There are no project files to create or
configure, so students spend their attention on C++ concepts (variables, loops,
functions, classes, the STL) instead of on build settings.

## Repository layout

```txt
TeachMate/
  README.md                 this file
  .vscode/                  shared VS Code build/debug config (C++17, g++)
  docs/setup-windows.md     step-by-step C++ setup for Windows (start here)
  docs/cheatsheet.md        create / compile / run + symbol reference
  docs/roadmap.md           full 4-week schedule, challenges and grading
  CPP/                      all C++ source code lives here
    run.cmd                 build + run one lesson
    build-all.cmd           compile every lesson and report warnings
    week1/                  foundations: 13 short lessons + 3 challenges + 7 loop lessons
      lesson01_hello/main.cpp
      lesson09_loops/main.cpp
      lesson09a_for_variations/main.cpp
      ...
      lesson10_functions/main.cpp
      ...
    week2/                  data: formatting, arrays, strings, structs, vectors, files
      lesson14_format/main.cpp
      ...
    week3/                  objects: classes, inheritance, polymorphism, smart pointers
      lesson26_classes/main.cpp
      ...
    week4/                  modern: templates, STL, algorithms, optional, exceptions
      lesson37_templates_func/main.cpp
      ...
    capstone/stage1/        loop + one function: average of three marks
    capstone/stage2a/       marks move into an array, with stats functions
    capstone/stage2b/       struct + vector + menu + file save/load
    capstone/stage3a/       Student and Gradebook classes (encapsulation)
    capstone/stage3b/       polymorphic Report class hierarchy
    capstone/stage4a/       generic Repository<T> + top() algorithm
    capstone/stage4b/       optional + exceptions (final program)
  build/                    compiled programs (created by the tools; ignored by git)
```

## Roadmap at a glance

| Week | Theme | Capstone layer |
| --- | --- | --- |
| 1 | Foundations: printing, variables, input, flow, functions | **stage1** — average of three marks (loop + function, no menu yet) |
| 2 | Formatting, arrays, strings, structs, vectors, files | **stage2a** array of marks + stats, then **stage2b** struct + vector + menu + file |
| 3 | Classes, encapsulation, RAII, inheritance, polymorphism | **stage3a** `Student`/`Gradebook` classes, then **stage3b** polymorphic `Report` |
| 4 | Templates, STL, algorithms, optional/variant, exceptions | **stage4a** generic `Repository<T>` + `top()`, then **stage4b** `optional`/exceptions (final) |

See `docs/roadmap.md` for every lesson and challenge.

Each capstone stage is a **small step** over the one before it, and no feature is
ever removed: the final `stage4b` program is the sum of all four weeks. Read the
stages in order (`stage1`, `stage2a`, `stage2b`, `stage3a`, `stage3b`, `stage4a`,
`stage4b`) to watch one project grow.

## How to use it as a student

- Read the comments at the top of each `main.cpp` — they state the goal.
- Type the program yourself at least once; do not only run it.
- Do the "Try it" prompts before moving on.
- Keep a personal copy of each capstone stage; you will refactor it.
