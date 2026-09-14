# TeachMate Roadmap

Four weeks, seven capstone steps. Each lesson is a standalone runnable program;
the capstone is the same program refactored and extended as each week's ideas
arrive. Every step only *adds* to the previous one — nothing is removed — so the
final program is the sum of the whole course. Read the stages in order:
`stage1`, `stage2a`, `stage2b`, `stage3a`, `stage3b`, `stage4a`, `stage4b`.

Target: **C++17**, edited in **Visual Studio Code** with the C/C++ extension and
built with **MinGW-w64 GCC 13+**. Compiler flags for every program:
`-std=c++17 -Wall -Wextra -Wpedantic`. Build with **Ctrl+Shift+B** in VS Code or
`run.cmd <lesson-folder>` from the `CPP` folder. The tools use `g++` from `PATH`
(or the `CXX` environment variable if set).

---

## Week 1 — Foundations (generated)
From a blank file to reusable functions. Every program is short (roughly 10–25
lines), teaches **one idea**, and prints with plain `std::cout`.

| # | Folder | Topic | Key ideas |
|---|--------|-------|-----------|
| 01 | `lesson01_hello` | Hello! | `main`, `#include <iostream>`, one `std::cout`, `"\n"` |
| 02 | `lesson02_printing` | Several lines | several `cout` statements, comments |
| 03 | `lesson03_int` | Whole numbers | `int`, assignment, adding |
| 04 | `lesson04_double` | Decimal numbers | `double` |
| 05 | `lesson05_string` | Text | `std::string` |
| 06 | `lesson06_input` | Reading input | `std::cin >>` |
| 07 | `lesson07_arithmetic` | Arithmetic | `+ - * / %`, integer division |
| 08 | `lesson08_decisions` | Decisions | `if` / `else` |
| 09 | `lesson09_loops` | Loops | `for` |
| 10 | `lesson10_functions` | Functions | a parameter and a return value |
| 11 | `lesson11_fizzbuzz` | Challenge | `%` + `if`/`else if` inside a loop |
| 12 | `lesson12_even_odd` | Challenge | testing with `%` |
| 13 | `lesson13_times_table` | Challenge | printing with a loop |

**Capstone stage1 — `CPP/capstone/stage1`:** read three marks with a loop, add
them up, and compute the average with a small `average()` function (~35 lines).
Uses only Week 1 ideas: variables, `std::cin`, a `for` loop, a function and
arithmetic. Still no menu and no array.

### Week 1 outcomes
- Build and run a single-file C++ program (VS Code or `run.cmd`).
- Store values in variables and read input with `cin`.
- Make decisions, repeat work with loops, and write a small function.

### Deliberately deferred (not in Week 1)
`switch`/`enum`, references, arrays, pointers, `<random>`, `auto`, and overloads
are introduced in later weeks so beginners meet one new idea at a time.
Output formatting with `<iomanip>` arrives in Week 2; plain `std::cout` is used
throughout Week 1.

---

## Week 2 — Data, memory & persistence (generated)
More data, and data that survives after the program exits. Still short programs,
still one idea each.

| # | Folder | Topic | Key ideas |
|---|--------|-------|-----------|
| 14 | `lesson14_format` | Nicer output | `<iomanip>`: `fixed`, `setprecision`, `setw`, `left`/`right` |
| 15 | `lesson15_arrays` | Arrays | fixed size, positions start at 0, looping |
| 16 | `lesson16_array_stats` | Array summary | total, average, smallest, largest in one loop |
| 17 | `lesson17_strings` | Text operations | join with `+`, `size()`, `[i]` |
| 18 | `lesson18_getline` | Reading a line | `std::getline` (text with spaces) |
| 19 | `lesson19_structs` | Structs | group related fields into one type |
| 20 | `lesson20_vector` | `std::vector` | `push_back`, `size()`, range-based `for` |
| 21 | `lesson21_files` | File I/O | `ofstream` / `ifstream`, read back what you wrote |
| 22 | `lesson22_references` | Passing by reference | `&` lets a function change the caller's variable |
| 23 | `lesson23_challenge_max` | Challenge | largest value in an array |
| 24 | `lesson24_challenge_reverse` | Challenge | print a word backwards |
| 25 | `lesson25_challenge_word_count` | Challenge | count characters and spaces in a line |

**Capstone stage2a — `CPP/capstone/stage2a`:** the marks move into a fixed
array of `int`. Functions take the array and its size and report the total,
average, largest and smallest mark, and `<iomanip>` prints the average to two
decimals. This is the "array" step that `stage1` pointed forward to.

**Capstone stage2b — `CPP/capstone/stage2b`:** each mark gains a name. A
`struct Student` groups a name and a mark, a `std::vector<Student>` lets the
list grow while the program runs, and an `if`/`else` menu (add, list, average,
save, load, quit) appears for the first time. Functions take the vector by
reference (`&` / `const &`), names are read with `std::getline`, and a text file
makes the data survive.

---

## Week 3 — Object-Oriented Programming (generated)
Bundling data and behaviour together. Each lesson is still short and focused.

| # | Folder | Topic | Key ideas |
|---|--------|-------|-----------|
| 26 | `lesson26_classes` | Classes | a class with data and methods |
| 27 | `lesson27_constructors` | Constructors | initialize an object at creation |
| 28 | `lesson28_encapsulation` | Hiding data | `private` data, getters/setters, validation |
| 29 | `lesson29_destructors_raii` | Destructors & RAII | `~Tracer`, scope, automatic cleanup |
| 30 | `lesson30_operator_overload` | Operator overloading | `operator+` on a `Point` |
| 31 | `lesson31_inheritance` | Inheritance | base/derived classes, constructor chaining |
| 32 | `lesson32_polymorphism` | Polymorphism | `virtual`, `override`, base-class references |
| 33 | `lesson33_smart_pointers` | Smart pointers | `unique_ptr`, `make_unique`, automatic delete |
| 34 | `lesson34_challenge_shapes` | Challenge | shape hierarchy with virtual `area()` |
| 35 | `lesson35_challenge_bank` | Challenge | an `Account` class with private state |
| 36 | `lesson36_challenge_inventory` | Challenge | a class held in a `std::vector` |

**Capstone stage3a — `CPP/capstone/stage3a`:** the gradebook becomes genuinely
object-oriented. `Student` hides its data behind `private` and a constructor
that keeps the mark inside 0..100, and `Gradebook` owns the `vector` and offers
`add`/`list`/`average`/`save`/`load`. The same add/list/average/save/load menu as
`stage2b` continues.

**Capstone stage3b — `CPP/capstone/stage3b`:** the way the gradebook is reported
becomes an object too. An abstract `Report` base with `SimpleReport` and
`SummaryReport` subclasses shows inheritance and virtual dispatch, chosen with a
`std::unique_ptr` and printed through the base pointer. The menu gains a
"Report" option.

---

## Week 4 — Modern C++ & generalization (generated)
The final layer: writing code that works for many types and reads cleanly.

| # | Folder | Topic | Key ideas |
|---|--------|-------|-----------|
| 37 | `lesson37_templates_func` | Function templates | `template <typename T>`, deduction |
| 38 | `lesson38_templates_class` | Class templates | `Box<T>` for any type |
| 39 | `lesson39_stl_map` | `std::map` | key -> value, sorted keys, structured bindings |
| 40 | `lesson40_stl_set` | `std::set` | unique items, auto-sorted |
| 41 | `lesson41_algorithms` | `<algorithm>` | `sort`, `count`, `accumulate` |
| 42 | `lesson42_lambdas` | Lambdas | inline functions, `count_if`, captures |
| 43 | `lesson43_algorithms2` | Filter & transform | `copy_if`, `transform`, `back_inserter` |
| 44 | `lesson44_exceptions` | Exceptions | `throw`/`catch`, `what()` |
| 45 | `lesson45_move_semantics` | Move semantics | `std::move`, avoiding a copy |
| 46 | `lesson46_optional_variant` | `optional` / `variant` | "maybe a value", one-of-several |
| 47 | `lesson47_challenge_sort` | Challenge | sort students by mark with a lambda |
| 48 | `lesson48_challenge_word_count` | Challenge | word frequency with a `map` |
| 49 | `lesson49_challenge_safe_parse` | Challenge | safe parsing with `optional`/exceptions |

**Capstone stage4a — `CPP/capstone/stage4a`:** the container becomes reusable.
A generic `template <typename T> class Repository` stores any type, and
`Gradebook` keeps a `Repository<Student>` instead of a raw `vector`. `top()`
finds the best student with `std::max_element` and a lambda. Every Week 3 idea —
including the `Report` hierarchy — stays. The menu is add / list / average /
top / report / save / load / quit.

**Capstone stage4b — `CPP/capstone/stage4b` (final):** `top()` and a new
`find()` return `std::optional<Student>` to express "maybe a student";
`save()`/`load()` throw exceptions caught in `main`; `Repository::add` takes its
item by value and uses `std::move` to avoid a copy; and `<iomanip>` aligns the
output. The final menu is add / list / average / top / find / report / save /
load / quit — the union of all four weeks.

> The course stays with `std::optional` + `std::variant` (both C++17); later
> standards such as C++20/23 are out of scope.

---

## Assessment
- **Per lesson:** the program compiles without warnings and answers a short
  "predict the output" / "modify it" prompt.
- **Per week:** the challenge set plus a saved capstone stage (copy the folder or
  tag it in version control).
- **Final:** capstone demo plus one unseen problem combining the week's topic.
- **Rubric:** correctness, memory safety (ASan/valgrind where available), code
  style, and design.

## Toolchain notes
- The course uses only **C++17** features, so it builds on any GCC/Clang from
  ~2017 onward.
- Ensure `g++` is on `PATH` (VS Code ships no compiler). If you cannot add it to
  `PATH`, set `CXX` to the full path of your `g++.exe` before running
  `run.cmd` / `build-all.cmd`.
- Output formatting uses `<iomanip>` rather than `std::format` (which needs
  C++20), keeping the lessons inside C++17.
