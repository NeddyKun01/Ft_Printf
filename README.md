*This project has been created as part of the 42 curriculum by NeddyKun1.*

# ft_printf

> *Because `ft_putnbr()` and `ft_putstr()` aren't enough. Rebuilding formatted output from scratch.*

![42 Project](https://img.shields.io/badge/42-Project-000000)
![Language](https://img.shields.io/badge/Language-C-blue)
![Standard](https://img.shields.io/badge/C-C99-informational)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen)
![Library](https://img.shields.io/badge/Output-libftprintf.a-orange)
![Bonus](https://img.shields.io/badge/Bonus-Flags%20%2B%20Width%20%2B%20Precision-purple)
![License](https://img.shields.io/badge/License-MIT-green)

---

## About

**ft_printf** is a 42 Common Core project focused on recreating part of the standard `printf()` function from libc.

This repository implements a custom formatting library with the goal of understanding variadic functions, format parsing, number conversion and controlled output in C.

The implementation is built with the following principles in mind:

* Clean and readable code
* Strict Norminette compliance
* Memory safety
* Robust edge-case handling
* Correct return values
* Code reuse through the local `Libft`
* Maintainability over cleverness

The project is not only about printing values, but also about understanding how a format string is parsed and how each conversion decides what must be written.

---

## Features

* Recreates the core behaviour of `printf`
* Handles variadic arguments with `stdarg.h`
* Supports all mandatory conversions
* Builds a static library named `libftprintf.a`
* Uses the local `Libft/` library
* Embeds `Libft` objects into `libftprintf.a`
* Provides a separate bonus build
* Bonus support for flags, width and precision
* Returns the number of printed characters

---

## Project Structure

```text
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_text.c
├── ft_print_numbers.c
├── ft_print_hex.c
├── ft_printf_bonus.h
├── ft_printf_bonus.c
├── ft_parse_bonus.c
├── ft_utils_bonus.c
├── ft_base_utils_bonus.c
├── ft_render_base_bonus.c
├── ft_render_text_bonus.c
├── ft_render_num_bonus.c
├── Libft/
└── README.md
```

---

## Function Reference

### Main API

* `ft_printf(const char *format, ...)` - Prints formatted output to standard output and returns the number of characters written.

### Mandatory Conversions

* `%c` - Prints a single character.
* `%s` - Prints a string.
* `%p` - Prints a pointer address in hexadecimal format.
* `%d` - Prints a signed decimal integer.
* `%i` - Prints a signed decimal integer.
* `%u` - Prints an unsigned decimal integer.
* `%x` - Prints a lowercase hexadecimal number.
* `%X` - Prints an uppercase hexadecimal number.
* `%%` - Prints a percent sign.

### Internal Helpers

* `ft_putchar` - Writes one character.
* `ft_putstr` - Writes a string.
* `ft_putnbr` - Writes a signed decimal integer.
* `ft_putunbr` - Writes an unsigned decimal integer.
* `ft_puthex` - Writes a hexadecimal number.
* `ft_putptr` - Writes a pointer address.

---

## Mandatory Part

The mandatory implementation uses these files:

* `ft_printf.c`
* `ft_printf.h`
* `ft_print_text.c`
* `ft_print_numbers.c`
* `ft_print_hex.c`

The mandatory version supports the conversions required by the subject:

```text
c s p d i u x X %
```

It does not implement the original buffering system of libc `printf`.

The output is written directly to standard output using `write()`.

---

## Bonus Part

The bonus implementation adds support for flags, width and precision.

Bonus files:

* `ft_printf_bonus.c`
* `ft_printf_bonus.h`
* `ft_parse_bonus.c`
* `ft_utils_bonus.c`
* `ft_base_utils_bonus.c`
* `ft_render_base_bonus.c`
* `ft_render_text_bonus.c`
* `ft_render_num_bonus.c`

Supported bonus features:

* `-` left alignment
* `0` zero padding
* `.` precision
* field minimum width
* `#` alternate form
* `+` explicit sign
* space flag

Example behaviour:

```c
ft_printf("|%10s|%-10s|%08d|%.5u|%#x|%+d|% d|\n",
	"hi", "hi", 42, 42, 48879, 42, 42);
```

---

## Building

This repository contains the implementation files, a root `Makefile` and a local `Libft/` dependency.

The default build command is:

```bash
make
```

The expected output artifact is:

```text
libftprintf.a
```

For the bonus version:

```bash
make bonus
```

The root `Makefile` builds `Libft/libft.a`, copies it into `libftprintf.a`, and then adds the `ft_printf` object files. This keeps the final library self-contained.

Useful cleaning commands:

```bash
make clean
make fclean
make re
```

---

## Example Usage

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s! value=%d hex=%x pointer=%p%%\n",
			"42", 1337, 48879, (void *)0x1234);
	return (count);
}
```

For the bonus version, include the bonus header when testing bonus-only behaviour:

```c
#include "ft_printf_bonus.h"
```

---

## Testing

Recommended test cases:

* Plain strings
* Empty format strings
* `NULL` strings
* `INT_MIN`
* Unsigned integer limits
* Hexadecimal output in both cases
* Pointer values
* Literal `%`
* Return value comparison with `printf`
* Bonus: width and precision
* Bonus: `-`, `0`, `#`, `+` and space flags

Example:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```

Compare output and return values with the system `printf` whenever possible.

---

## Learning Philosophy

One of the most important lessons of this project is understanding how formatted output is built from smaller decisions.

Before printing a value, `ft_printf` needs to:

* read the format string
* detect conversion specifiers
* fetch the correct variadic argument
* convert the value to text
* apply formatting rules
* count every written character

Useful references:

```bash
man 3 printf
man 3 stdarg
```

Understanding the expected behaviour from documentation is far more valuable than searching for an implementation online.

---

## Resources

Classic references used for this project:

* `man 3 printf`
* `man 3 stdarg`
* [printf(3) manual](https://man7.org/linux/man-pages/man3/printf.3.html)
* [stdarg(3) manual](https://man7.org/linux/man-pages/man3/stdarg.3.html)
* [C variadic functions](https://en.cppreference.com/w/c/variadic)

AI was used to help review the README structure, compare it with the other project READMEs and check that the documentation matched the current implementation.

The implementation itself should always be validated manually with tests, Norminette and comparison against the system `printf`.
