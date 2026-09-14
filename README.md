# TeachMate — C++23 Bootcamp

A 4-week, hands-on C++ course for bachelor students. It moves from the smallest
possible program to modern C++23 by **stacking one new layer at a time**, while a
single capstone project ("Gradebook / Student Records Manager") grows along with
the material.

## Who this is for
Students who have never written C++, or who have written a little code in another
language. No prior C/C++ experience is assumed.

## Toolchain (Code::Blocks + MinGW-w64 GCC)
The examples target **C++23** and are built with **Code::Blocks**.

1. Install Code::Blocks **with the MinGW-w64 compiler** (the "codeblocks-*-mingw-setup.exe"
   download). The bundled GCC must be **13 or newer** for C++23 features such as
   `std::format`, `std::ranges` and `std::expected`.
2. Check your compiler version: open Code::Blocks -> Settings -> Compiler ->
   Toolchain executables, or run `g++ --version` from the MinGW `bin` folder.
   - If GCC is older than 13, install a newer MinGW-w64 (e.g. a recent
     winlibs.com build) and point Code::Blocks at it: **Settings -> Compiler ->
     Toolchain executables -> Compiler's installation directory**.
3. Enable the C++23 language standard. For every project:
   **Project -> Build options -> Compiler settings -> Other options** and add:

   ```
   -std=c++23 -Wall -Wextra -Wpedantic
   ```

   All `.cbp` files in this repo already contain these flags.
   If your compiler rejects `-std=c++23`, use the temporary alias `-std=c++2b`.

## How to build and run a lesson
1. Open Code::Blocks.
2. **File -> Open** and pick the lesson's `.cbp` file, e.g.
   `CPP/week1/lesson01_hello/lesson01_hello.cbp`.
3. Press **F9** (Build and run), or use **Build -> Build** (F9 builds and runs;
   Ctrl-F9 builds only).
4. Debugging: set a breakpoint by clicking the left gutter, then press **F8**
   (Debug -> Start). Use **F7** to step into and **Shift-F7** to step over.

A `week1.workspace` file is provided so you can open all Week 1 projects at once:
**File -> Open -> CPP/week1/week1.workspace**.

### Why one project per lesson?
Code::Blocks compiles and links **every** `.cpp` file that belongs to a project.
If two lessons with two `main()` functions lived in one project, the linker would
fail with a "multiple definition of `main`" error. Each lesson is therefore its
own small project.

## Repository layout
```
TeachMate/
  README.md                 this file
  docs/roadmap.md           full 4-week schedule, challenges and grading
  CPP/                      all C++ source code lives here
    week1/                  foundations: 13 short lessons + 3 challenges
      lesson01_hello/       main.cpp + lesson01_hello.cbp
      ...
      week1.workspace       opens all 13 Week 1 projects
    week2/                  data: format, arrays, strings, structs, vectors, files
      lesson14_format/      main.cpp + lesson14_format.cbp
      ...
      week2.workspace       opens all 12 Week 2 projects
    week3/                  objects: classes, inheritance, polymorphism, smart pointers
      lesson26_classes/     main.cpp + lesson26_classes.cbp
      ...
      week3.workspace       opens all 11 Week 3 projects
    capstone/stage1/        first layer of the evolving project
    capstone/stage2/        structs + vector + file menu
    capstone/stage3/        classes + polymorphism + smart pointer
    (week4 and capstone/stage4 are added as the course progresses)
```

## Roadmap at a glance
| Week | Theme | Capstone layer |
|------|-------|----------------|
| 1 | Foundations: printing, variables, input, flow, functions | Average of three marks (no menu/array yet) |
| 2 | Arrays, strings, structs, pointers, vectors, files | Records in a `vector`, save/load to file |
| 3 | Classes, encapsulation, RAII, inheritance, polymorphism | `Student` + `Gradebook` classes, polymorphic `Report` |
| 4 | Templates, STL, algorithms, ranges, exceptions, move | Generic `Repository<T>` final application |

See `docs/roadmap.md` for every lesson and challenge.

## How to use it as a student
- Read the comments at the top of each `main.cpp` — they state the goal.
- Type the program yourself at least once; do not only run it.
- Do the "Try it" prompts before moving on.
- Keep a personal copy of each capstone stage; you will refactor it.
