*This project has been created as part of the 42 curriculum by mdaoui.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C
(`va_list`, `va_start`, `va_arg`, `va_end`) and to write clean, extensible code
that can later be added to your `libft`.

The prototype of the function is:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed (like the original `printf()`).
The buffer management of the original `printf()` is **not** implemented: output
is written directly with `write()`.

### Supported conversions

| Conversion | Description                                          |
|------------|------------------------------------------------------|
| `%c`       | Prints a single character                            |
| `%s`       | Prints a string (prints `(null)` if the pointer is NULL) |
| `%p`       | Prints a `void *` pointer in hexadecimal (`0x...`, `(nil)` if NULL) |
| `%d`       | Prints a signed decimal (base 10) number             |
| `%i`       | Prints a signed integer in base 10                   |
| `%u`       | Prints an unsigned decimal (base 10) number          |
| `%x`       | Prints a number in lowercase hexadecimal (base 16)   |
| `%X`       | Prints a number in uppercase hexadecimal (base 16)   |
| `%%`       | Prints a percent sign                                |

## Instructions

### Compilation

```bash
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! %d + %d = %i\n", "42", 1, 2, 3);
    ft_printf("Printed %d characters\n", count);
    ft_printf("Hex: %x / %X, pointer: %p, percent: 100%%\n", 255, 255, &count);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

### Testing

Compare the output and the return value of `ft_printf()` with the real
`printf()` for every conversion, including edge cases:
`INT_MIN`, `INT_MAX`, `UINT_MAX`, `0`, `NULL` strings, `NULL` pointers, empty
strings, and a `%` at the end of the format string.

## Algorithm and data structure

### Algorithm

1. `va_start` initializes the argument list from the last named parameter.
2. The format string is read **character by character**:
   - a normal character is written directly with `write()`;
   - a `%` means a conversion specifier: the next character is read and
     the matching handler is called.
3. Each handler fetches its argument with `va_arg` using the correct type
   (`int`, `unsigned int`, `char *`, `void *`) and prints it.
4. Every printing function **returns the number of bytes written**, and these
   values are accumulated into one total, which `ft_printf()` returns.
5. `va_end` cleans up the argument list.

Numbers are printed **recursively**: the number is divided by its base
(10 or 16) until it is smaller than the base, then digits are written
on the way back. This prints digits in the right order without needing a
buffer or `malloc`. Hexadecimal digits are taken from the string
`"0123456789abcdef"` (or `"0123456789ABCDEF"` for `%X`).

Special cases:
- `INT_MIN` is handled by converting to a wider type (e.g. `long`) before negating.
- `%p` is converted to `unsigned long` and printed as `0x` followed by its
  hexadecimal value; a NULL pointer prints `(nil)` to match glibc.
- `%s` with a NULL pointer prints `(null)` to match glibc.


## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [Variadic Functions](https://www.youtube.com/watch?v=S-ak715zIIE&pp=ygUXdmFyaWFkaWMgZnVuY3Rpb25zIGluIGM%3D)
- [How printf work in c](https://www.youtube.com/watch?v=Dypp3YjnWCU&t=619s&pp=ygUWcHJpbnRmICAgaG93IHdvcmsgaW4gYw%3D%3D)
- [cppreference – printf](https://en.cppreference.com/w/c/io/fprintf)
### Use of AI

AI tools were used as a learning and support resource during this printf project.They helped with:

Understanding variadic functions (va_start, va_arg, va_copy, va_end) and format specifier parsing (%c, %s, %p, %d, %i, %u, %x, %X, %%).

Clarifying edge cases such as NULL strings/pointers, INT_MIN / UINT_MAX, width/precision or flag interactions (if implemented), and return value counting.
All parsing logic, formatting helpers, tests, and final code were written, debugged, and verified by me. AI was used to support comprehension and preparation.