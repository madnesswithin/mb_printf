# mb_printf
Re-implementing the inbuilt printf functionality in my own function
*This project has been created as part of the 42 curriculum by mbabu.*

## ft_printf 42 Project

### Description

`ft_printf` is a reimplementation of the C standard library `printf()` function.
It handles a variable number of arguments using variadic functions (`stdarg.h`) and supports the following format conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.

The function returns the total number of czzharacters printed, just like the original.

#### Variadic Functions

In this project we learned about the concept of variadic functions and macros.

`va_list args;` declares an uninitialized pointer (type va_list).
`va_start (args, last_fixed_parameter);` macro that sets the start, by giving it the arguments and the last parameter that is not part of the variadic arguments.
`va_arg (args, type);` returns the value at the current position and advances the pointer by sizeof(type), to the next argument.
`va_end (args);` is run once your function has run; frees memory (on some systems)

### Instructions

**Compile the library (Linux/Mac):**

```bash
make
```

**Compile the library (Windows, no make):**

```bash
 cc -Wall -Wextra -Werror -c ft_printf.c ft_print_csdiu ft_print_ptr_hex 
            &&
 ar rcs libftprintf.a ft_printf.o ft_print_csdiu.o ft_print_ptr_hex.o 
```

**Use in another project:**

```bash
cc main.c -L. -lftprintf -o my_program
```

**Include in your code:**

```c
#include "ft_printf.h"

ft_printf("Hello %s, you are %d years old.\n", "world", 42);
```

**Makefile rules:**

- `make` / `make all` — build `libftprintf.a`
- `make clean` — remove object files
- `make fclean` — remove object files and library
- `make re` — full rebuild

### Algorithm and Data Structure

The implementation uses a single-pass loop over the format string.
When a `%` is encountered, the next character is passed to a static helper
function `ft_type_specifier()` along with a pointer to the `va_list`. This helper
dispatches to the appropriate output function based on the specifier.

Each output function (`ft_putchar`, `ft_putstr`, `ft_putnbr`, etc.) writes
directly to stdout using `write()` and returns the number of characters written.
These return values are accumulated into a total count which is returned by
`ft_printf` at the end.

In C, memory lives in two places: the **stack** (fast, automatic — local variables, function calls) and the **heap** (manual, dynamic — memory you request with `malloc` and must free yourself). No heap allocation is used here — `malloc` is never called. All number conversions are handled recursively, printing each digit directly to stdout as it's computed — no intermediate string buffer means no temporary array is used to hold the digits before printing them.

**How recursive number printing works (`ft_putnbr`, `ft_unsignputnbr`):**

The function recurses by dividing by 10 until it reaches a single digit, then prints digits
on the way back up. For example, `ft_unsignputnbr(423)`:

```
→ enter 423: n >= 10 → recurse into ft_putnbrunsigned(42)
  → enter 42:  n >= 10 → recurse into ft_putnbrunsigned(4)
    → enter 4:  n < 10  → print '4', return 1    ← deepest point
  ← back in 42: print '2' (42 % 10), return 2
← back in 423: print '3' (423 % 10), return 3
```

`n % 10` extracts the last digit; `+ '0'` converts it to its ASCII character (e.g. digit `3` → `'3'`).
The recursion ensures digits print left to right without needing a temporary buffer.

### Resources

- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C - cppreference](https://en.cppreference.com/w/c/variadic)
- [42 Norm](https://github.com/42School/norminette)
- [Claude](https://claude.ai/)

#### AI Usage

Claude (claude.ai) was used during this project for the following tasks:

- Debugging a return value discrepancy in the test file
- Writing tests
- Give tips on how to refactor `ft_printf` into a helper function to
  comply with the 25-line norm limit
- Reviewing the project against the subject requirements
