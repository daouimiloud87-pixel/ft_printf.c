This project has been created as part of the 42 curriculum by mdaoui.

ft_printf
Description
ft_printf is a foundational C programming project at 42 that challenges to recreate the standard C library function printf() from <stdio.h>.

The primary goal of this project is to understand and implement variadic functions in C (using stdarg.h) while building a clean, modular, and extensible codebase. The custom ft_printf function mimics the behavior of the original printf by parsing a format string, handling format specifiers, printing formatted output to the standard output (fd 1), and returning the total number of characters printed.

Supported Conversions
The mandatory part of this implementation handles the following format specifiers:

%c: Prints a single character.
%s: Prints a string (as defined by the common C convention).
%p: Prints a void * pointer address in hexadecimal format (prefixed with 0x).
%d: Prints a decimal (base 10) number.
%i: Prints an integer in base 10.
%u: Prints an unsigned decimal (base 10) number.
%x: Prints a number in hexadecimal (base 16) lowercase format.
%X: Prints a number in hexadecimal (base 16) uppercase format.
%%: Prints a percent sign.
(Note: If you implemented bonus flags such as -, 0, ., #, +, space, or minimum field width, list them here.)

Instructions
Prerequisites
A C compiler (cc, gcc, or clang)
make
Compilation
The project includes a Makefile that compiles the source files into a static library named libftprintf.a at the root of the repository.

Clone the repository and navigate to the project directory:

git clone <your-repository-url> ft_printf
cd ft_printf

Compile the library:

make

(If you implemented the bonus part, run make bonus instead.)

Additional Makefile rules available:

make clean: Removes object files (.o).
make fclean: Removes object files and the libftprintf.a archive.
make re: Recompiles the entire project from scratch.
Usage / Execution
To use ft_printf in your own C programs, include the header file ft_printf.h and link libftprintf.a during compilation.

Example (main.c):

#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! The answer is %d (0x%x).\n", "42", 42, 42);
    ft_printf("Total characters printed: %d\n", count);
    return (0);
}

Compile and run with your main.c:

cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf

Algorithm and Data Structure
Chosen Algorithm: Single-Pass Linear Parsing & Recursive Base Conversion
Format String Parsing (Linear Scan): The core ft_printf function iterates through the input const char *format string sequentially character-by-character (
O
(
n
)
O(n) time complexity, where 
n
n is the length of the string).

Whenever a standard character is encountered, it is immediately written to stdout via write(), incrementing a running character counter.
When a % character is encountered, the parser inspects the immediately following character (format[i + 1]) and dispatches the corresponding variadic argument (va_arg) to a dedicated handler function.
Number Formatting (Recursive Base Conversion): For numeric conversions (%d, %i, %u, %x, %X, %p), a recursive division-and-modulo algorithm is used (number / base and number % base).

Justification: Recursion naturally reverses the order of digits extracted via modulo without requiring dynamic memory allocation (malloc) or fixed-size temporary character buffers. This completely eliminates the risk of buffer overflows and memory leaks while keeping the stack depth minimal (at most 20 recursive calls for a 64-bit integer in base 10, and 16 calls in base 16).
Data Structures
va_list (<stdarg.h>): The primary data structure used to traverse the variable arguments passed to ft_printf. It safely manages stack/register argument retrieval across different architectures.
No Heap Structures / Zero Dynamic Allocation: Rather than building an intermediate string buffer or Abstract Syntax Tree (AST) for the mandatory conversions, characters are written directly to file descriptor 1 using the write system call.
Justification: Avoiding malloc for mandatory conversions makes ft_printf faster, avoids heap fragmentation, and guarantees that the function will never fail due to out-of-memory conditions. (Note: If you used a t_flags struct for bonus flag parsing, describe your struct fields and how it tracks width, precision, and active flags here.)
Resources
Classic References
Linux Programmer's Manual (man pages):
man 3 printf — Official specification of printf behavior, conversion specifiers, and return values.
man 3 stdarg — Documentation for va_start, va_arg, va_copy, and va_end.
man 2 write — Low-level system call documentation for writing bytes to a file descriptor.
C Standard Reference:
The C Programming Language (2nd Edition) by Brian W. Kernighan and Dennis M. Ritchie — Section 7.2 (Formatted Output - Printf) and Section 7.3 (Variable-length Argument Lists).
cppreference.com - Variadic functions & fprintf specification.
AI Usage
Task & Scope: AI was used strictly as a learning and documentation assistant during this project—specifically to clarify edge-case behaviors of the standard printf (such as NULL pointer printing with %p and NULL strings with %s), brainstorm test cases, and structure this README.md file.
Implementation: All C source code, header files, and the Makefile were written, debugged, and tested manually to ensure full compliance with the 42 Norm and deep understanding of variadic mechanics.