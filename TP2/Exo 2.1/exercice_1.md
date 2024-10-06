# Debugging with GDB (C) and PDB (Python)

This repository contains exercises designed to teach you how to debug C and Python programs using GDB and PDB, respectively. Below are instructions on how to compile, run, and debug the provided code.

## Table of Contents

- [C Exercise: Debugging with GDB](#c-exercise-debugging-with-gdb)
  - [Overview](#overview)
  - [Steps to Debug](#steps-to-debug)
- [Python Exercise: Debugging with PDB](#python-exercise-debugging-with-pdb)
  - [Overview](#overview-1)
  - [Steps to Debug](#steps-to-debug-1)
- [Notes and Tips](#notes-and-tips)

---

## C Exercise: Debugging with GDB

### Overview

The file `erreurs.c` contains a C program that multiplies each element of an array by 2. However, the program contains a bug that causes a "stack smashing" error due to accessing indices beyond the array's bounds.

### Steps to Debug

1. **Compile the Code with Debug Information**:
   To include debug information, compile the code using the `-ggdb3` flag:
   ```bash
   gcc -ggdb3 erreurs.c -o erreurs
   ```

2. **Run the Code with GDB**:
   Start GDB to debug the executable:
   ```bash
   gdb erreurs
   ```

3. **Run the Program in GDB**:
   Once in the GDB interface, run the program:
   ```bash
   (gdb) run
   ```

4. **Locate the Error**:
   When the program crashes, use the `bt` command to show the backtrace and find where the error occurs:
   ```bash
   (gdb) bt
   ```

5. **Set a Breakpoint**:
   Set a breakpoint at the line of interest to stop execution at that point. For example:
   ```bash
   (gdb) break erreurs.c:10
   ```

6. **Restart and Continue Execution**:
   Restart the program from the beginning if necessary:
   ```bash
   (gdb) run
   ```

   To continue execution until the next breakpoint:
   ```bash
   (gdb) continue
   ```

7. **Inspect Variables**:
   Use the `p` (print) command to check the state of variables:
   ```bash
   (gdb) p tableau
   (gdb) p tableau[0]@5  # To print the first 5 elements
   ```

8. **Solution**:
   Modify the loop condition to avoid accessing out-of-bound indices:
   ```c
   for (int compteur = 0; compteur < sizeof(tableau) / sizeof(tableau[0]); compteur++) {
       tableau[compteur] = tableau[compteur] * 2;
   }
   ```

## Python Exercise: Debugging with PDB

### Overview

The files `erreurs1.py` and `exercice_pdb.py` contain Python programs to demonstrate debugging techniques using PDB. The code introduces a bug where some elements are multiplied by 3 instead of 2.

### Steps to Debug

1. **Run the Code with PDB**:
   Start the Python debugger using:
   ```bash
   python3 -m pdb exercice_pdb.py
   ```

2. **Navigate Through the Code**:
   - Use `n` to go to the next line.
   - Use `l` to list the lines of code around the current execution point.
   - Use `b <line_number>` to set a breakpoint at a specific line.

3. **Inspect Variables**:
   Use `p` (print) to check the state of variables:
   ```bash
   (Pdb) p tableau
   (Pdb) p compteur
   ```

4. **Continue Execution**:
   To continue running the program until the next breakpoint or until it finishes:
   ```bash
   (Pdb) c
   ```

5. **Solution**:
   If the intended behavior is to always multiply elements by 2, modify the `double_values` function accordingly:
   ```python
   def double_values(tableau: List[int]) -> None:
       for compteur in range(len(tableau)):
           tableau[compteur] *= 2
       return tableau
   ```

---

## Notes and Tips

- **GDB Commands**:
  - `break <file>:<line_number>`: Set a breakpoint at a specific line.
  - `run` or `r`: Start the program execution.
  - `bt` or `backtrace`: Show the call stack to find where the error occurred.
  - `n` or `next`: Move to the next line of code without stepping into functions.
  - `continue` or `c`: Continue execution until the next breakpoint.

- **PDB Commands**:
  - `l`: List lines of code.
  - `n`: Move to the next line.
  - `b <line_number>`: Set a breakpoint.
  - `p <variable>`: Print the value of a variable.
  - `c`: Continue program execution until the next breakpoint.
  - `q`: Quit the debugger.

- **General Debugging Tips**:
  - Use breakpoints to pause execution and inspect the state of your program.
  - Step through your code line by line to understand its behavior.
  - Always check the values of variables that are critical to your program's logic.

