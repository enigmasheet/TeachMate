# Setting up C++ on Windows (student guide)

A from-zero guide for writing, compiling and running C++ on a Windows laptop.
Follow it once; after that you only ever repeat the last two steps.

---

## 1. What we install

| Software | Purpose |
| --- | --- |
| **Visual Studio Code** | The editor where you type code |
| **GCC / MinGW-w64** (through MSYS2) | The **compiler** that turns C++ into a program |
| **C/C++ extension for VS Code** | IntelliSense, error highlighting, debugging |

The one idea to remember:

> **VS Code is not a C++ compiler.**

```text
     you write C++ code
            │
            ▼
      VS Code  (editor only)
            │
            ▼
        g++  (compiler)
            │
            ▼
        hello.exe  (program)
            │
            ▼
         output
```

VS Code is just a smart text editor. `g++` is what actually builds the program.

---

## 2. Install Visual Studio Code

1. Go to <https://code.visualstudio.com/> and download the **Windows**
   installer.
2. Run it. The default options are fine.
3. If you see these checkboxes, keep them on:
   - **Add to PATH**
   - **Add "Open with Code"**
   - **Register Code as an editor**

---

## 3. Install MSYS2 (it brings GCC)

1. Go to <https://www.msys2.org/> and download the installer.

2. Install it to the default location:

   ```text
   C:\msys64
   ```

   Keeping the default makes every later step (and every tutorial) match.

---

## 4. Open the MSYS2 UCRT64 terminal

Open the Start menu and launch:

```text
MSYS2 UCRT64
```

You should see a prompt like:

```text
user@computer UCRT64 ~
$
```

---

## 5. Update MSYS2

In that terminal run:

```bash
pacman -Syu
```

Press `Y` when asked. If it tells you to close the terminal, then:

1. Close the terminal.
2. Open **MSYS2 UCRT64** again.
3. Run `pacman -Syu` again.

Repeat until it says there is nothing left to update.

---

## 6. Install the GCC toolchain

In **MSYS2 UCRT64** run:

```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

Press Enter, then `Y` to confirm. This installs `gcc`, `g++`, `gdb` and
friends. The one we care about is `g++`.

> `g++` is the GNU C++ compiler. `g++ main.cpp -o hello` means "compile
> `main.cpp` and write the program to `hello.exe`".

---

## 7. Add the compiler to your PATH

This lets you type `g++` from any folder instead of the whole path.

1. Press the Windows key and search for **"environment variables"**.

2. Choose **Edit the system environment variables** →
   **Environment Variables…**

3. Under **User variables**, select **Path** → **Edit…** → **New**.

4. Add exactly:

   ```text
   C:\msys64\ucrt64\bin
   ```

5. Click **OK** on every dialog.

---

## 8. Verify the compiler

**Close and reopen** Command Prompt or PowerShell, then run:

```bash
g++ --version
```

You should see something like:

```text
g++ (Rev...) ...
Copyright (C) ...
```

The exact version does not matter. If you see version information,
**your compiler is installed**.

### If you see `'g++' is not recognized`

Windows cannot find the compiler. Check that this file exists:

```text
C:\msys64\ucrt64\bin\g++.exe
```

Then check the `Path` entry from step 7, and **reopen the terminal**
after changing PATH. Try `g++ --version` again.

---

## 9. Install the C/C++ extension in VS Code

1. Open VS Code.
2. Press **Ctrl+Shift+X** (Extensions).
3. Search for **C/C++**.
4. Install the one from publisher **Microsoft** (`ms-vscode.cpptools`).

This gives syntax highlighting, IntelliSense, error detection and debugging.

---

## 10. Your first program

Organise your work — do not scatter files on the Desktop. Make:

```text
C:\CPP\01-HelloWorld\
```

Open **that folder** in VS Code (**File → Open Folder…**). Then create
a new file called `main.cpp` (the `.cpp` extension matters) with:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World!";
    return 0;
}
```

Save with **Ctrl+S**.

### Understand every line

- `#include <iostream>` — pulls in the **i**nput/**o**utput **stream**
  library, which provides `std::cout`.
- `int main()` — the **entry point**; Windows starts your program here.
- `{` `}` — the **body** of `main`.
- `std::cout << "Hello World!";` — send the text to the **st**andard
  output. `<<` means "send to output".
- `;` — ends a statement. Forgetting it is the most common beginner error.
- `return 0;` — tells Windows the program finished **successfully**
  (`0` = success, non-zero = failure).

---

## 11. Compile and run (do this manually first)

Open the VS Code terminal (**Terminal → New Terminal**, or
` Ctrl+` `), make sure you are inside `01-HelloWorld`, then run:

```bash
g++ main.cpp -o hello
```

This creates `hello.exe`. Now run it:

### PowerShell

```powershell
.\hello.exe
```

### Command Prompt (cmd)

```cmd
hello.exe
```

Output:

```text
Hello World!
```

### Compile vs run — two different things

- `g++ main.cpp -o hello` → **compile** (translate source into a program).
- `.\hello.exe` → **run** (execute the program you already built).

```text
main.cpp  ──g++──►  hello.exe  ──run──►  Hello World!
```

---

## 12. When there is an error

Delete the semicolon:

```cpp
std::cout << "Hello World!"
```

and compile again with `g++ main.cpp -o hello`. You will get a
**compile-time error** similar to:

```text
error: expected ';' before 'return'
```

Put the `;` back, compile and run. Congratulations — you just did the
core programming loop:

```text
write → compile → error? → read the message → fix → compile → run
```

---

## 13. Then use VS Code's buttons

Once you understand the pipeline above, you can use the shortcuts:

- **Ctrl+Shift+B** — build the file you are editing (output in `build/`).
- **F5** — build and debug it (breakpoints, step through).

Do not let the Run button replace your understanding of
`source → compiler → .exe → run`.

---

## 14. Common problems

| Symptom | Likely cause | Fix |
| --- | --- | --- |
| `'g++' is not recognized` | PATH not set | Add `C:\msys64\ucrt64\bin`, reopen the terminal |
| VS Code shows red squiggles everywhere | extension missing / compiler not found | Install **C/C++**; reopen VS Code after PATH changes |
| Program compiled but "won't run" | PowerShell needs a path | Use `.\hello.exe`, not `hello.exe` |
| `undefined reference to main` | file not named `.cpp` (e.g. `hello.c`) | C++ files must end in `.cpp` |
| No `hello.exe`, but there is an `a.exe` | you ran `g++ main.cpp` with no `-o` | Use `g++ main.cpp -o hello` |

---

## 15. Cheat sheet

See `docs/cheatsheet.md` for the create/compile/run commands and the
symbols you will use every day.

Next: open `docs/roadmap.md` and start with Week 1.
