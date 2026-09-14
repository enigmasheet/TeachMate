# C++ cheat sheet (first page)

## Create

```text
main.cpp        (the file name must end in .cpp)
```

## Compile

```bash
g++ main.cpp -o hello
```

- `g++` → the C++ compiler
- `main.cpp` → your source file
- `-o hello` → write the program to `hello.exe` (without `-o` you get `a.exe`)

## Run

```powershell
.\hello.exe      (PowerShell)
hello.exe        (Command Prompt)
```

## The smallest C++ program

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World!";
    return 0;
}
```

## Symbols you use every day

| Symbol | Meaning                                 |
| ------ | --------------------------------------- |
| `;`    | ends a statement                        |
| `{ }`  | a block (the body of a function / if / loop) |
| `( )`  | function parameters / conditions        |
| `" "`  | text (a string)                         |
| `' '`  | a single character                      |
| `<<`   | send to output                          |
| `\n`   | new line                                |
| `//`   | a comment (ignored by the compiler)     |

## Printing

```cpp
std::cout << "Hello\n";        // prints "Hello" then a new line
std::cout << "Age: " << 18;    // prints text and a number
```

## Reading input

```cpp
int age;
std::cin >> age;               // read a whole number from the keyboard
```

## Control flow

```cpp
// if / else
if (x > 0)         { /* … */ }
else if (x == 0)    { /* … */ }
else                 { /* … */ }

// for loop
for (int i = 0; i < 5; i++) { /* … */ }

// while loop — checks before each turn
while (n > 0) { n--; }

// do-while — body always runs at least once
do { std::cin >> n; } while (n <= 0);

// break exits the innermost loop
// continue skips to the next round
```

## Variables (the main types)

```cpp
int    whole  = 42;     // whole numbers
double price  = 9.99;   // decimal numbers
char   letter = 'A';    // one character
bool   ready  = true;   // true / false
std::string name = "Sam";   // needs #include <string>
```

## The usual workflow

```text
write  →  g++ main.cpp -o hello  →  .\hello.exe
                 │
                 └─ error? read it, fix the code, compile again
```
