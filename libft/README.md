*This activity has been created as part of the 42 curriculum by yboutakh.*

# Libft

## Description

Libft is a C library built to understand how common libc functions work and reuse them in later 42 projects.

The build target is `libft.a`, with the public functions declared in `libft.h`.

## Library contents

The library is split into three parts:

- **Libc functions:** character checks, case conversion, memory operations and basic string functions, rewritten with an `ft_` prefix. This also includes string-to-integer conversion and memory allocation.
- **Extra helpers:** functions to cut, join, trim and split strings, convert integers to strings and process characters with callbacks. The `*_fd` functions write characters, strings or numbers to a file descriptor.
- **Linked lists:** functions to create nodes, add them to a list, count them, apply callbacks and delete them. They use `t_list`, where each node holds a content pointer and a pointer to the next node.

Allocated results belong to the caller and must be freed after use. With `ft_split`, that means freeing each string, then the array. For lists, a deletion callback handles the content of each node.

## Instructions

### Compilation

Requirements: a C compiler available as `cc`, `make` and `ar`.

From the repository root:

```sh
make
```

The Makefile compiles with `-Wall -Wextra -Werror` and uses `ar rcs` to create `libft.a`. Linked-list sources are included in the default build; there is no separate bonus target.

| Command | Action |
| --- | --- |
| `make` | Build the library. |
| `make clean` | Remove object files. |
| `make fclean` | Remove object files and `libft.a`. |
| `make re` | Remove build output and rebuild the library. |

### Usage

To use Libft in a program, include `libft.h` and link against `libft.a`.

For example, save this as `main.c` at the repository root:

```c
#include "libft.h"

int	main(void)
{
	char	*message;

	message = ft_strjoin("Hello, ", "libft!");
	if (!message)
		return (1);
	ft_putendl_fd(message, 1);
	free(message);
	return (0);
}
```

Build and run the example program using the library compiled by `make`:

```sh
cc -Wall -Wextra -Werror -I. main.c libft.a -o example
./example
```

It prints `Hello, libft!` followed by a newline.

## Resources

- The 42 Libft subject, version 1.3.
- [Linux man-pages](https://man7.org/linux/man-pages/man3/intro.3.html) for the standard C functions.
- [OpenBSD manual](https://man.openbsd.org/strlcpy) for `strlcpy` and `strlcat`.

AI was used to review the subject, explain some wording and linked lists.
