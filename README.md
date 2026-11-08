*This activity has been created as part of the 42 curriculum by yboutakh.*

# ft_printf

## Description

This project reimplements part of the C library's `printf` function. It is a way to practise variadic functions and understand how a format string tells the program which values to print.

Supported conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and `%%`.

## Instructions

Run `make` from the project root to create `libftprintf.a`:

```sh
make
```

For a test program in `main.c` that includes `ft_printf.h`, compile and run:

```sh
cc -Wall -Wextra -Werror -I. main.c libftprintf.a -o test
./test
```

`make clean` removes the object files. `make fclean` also removes the library, and `make re` rebuilds it.

## Algorithm and data structures

`ft_printf` initializes a variadic argument list with `va_start`, then asks the parser to scan the format string from left to right. A regular character is written directly. When the parser finds `%`, it reads the next conversion, retrieves the matching argument with `va_arg` and calls the appropriate helper. Each helper writes its value and returns the byte count for that conversion; the parser adds these counts. `va_end` finishes the use of the argument list.

Decimal and hexadecimal numbers are printed one digit at a time by recursively dividing by 10 or 16. For hexadecimal output, a constant string provides the lowercase or uppercase digits. Strings are scanned byte by byte. The project does not use a dynamic buffer: a `va_list`, indices, integer counters and constant digit strings are enough here.
All output goes through `ft_write_all`, which handles partial writes and returns `-1` if `write` fails. That error is propagated back to `ft_printf`.

## Resources

- [`printf(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [`write(2)` — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- [POSIX `fprintf` specification](https://pubs.opengroup.org/onlinepubs/9799919799/functions/fprintf.html)

AI was used to explain variadic functions and helped me find the write errors to fix them.
