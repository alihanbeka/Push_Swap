*This project has been created as part of the 42 curriculum by masik.*

# Description

The goal of this project is to create a personal C library by reimplementing functions from the standard C library and developing additional utility functions.

The project provides a deeper understanding of memory management, strings, pointers, dynamic allocation, and linked lists in C.

# Instructions

## Compilation

The library can be compiled using the provided Makefile.

Run:

```bash
make
```

This creates the `libft.a` static library and the required object files.

Available commands:

* `make`: Compiles the library and creates `libft.a`.
* `make clean`: Removes all object files.
* `make fclean`: Removes all object files and `libft.a`.
* `make re`: Removes all compiled files and recompiles the library.

# Resources

## References

* 42 Libft project subject
* Linux `man` pages

## AI Usage

AI was used during the development of this project for the following purposes:

* Clarifying the behavior and purpose of C standard library functions.
* Understanding concepts such as function pointers, dynamic memory allocation, and linked lists.
* Learning how to create and structure a Makefile for compiling the library.
* Reviewing code logic and identifying potential errors.

# Library Details

Libft is a custom C library containing reimplementations of several standard C library functions, as well as additional utility functions and linked list operations.

The library includes functions for:

* Character checking and conversion
* String manipulation
* Memory manipulation
* Memory allocation
* File descriptor output
* Integer-to-string conversion
* Linked list creation and management

The library is compiled into a static archive named `libft.a`, which can be linked with other C programs.

The project is organized into three main sections:

* **Libc functions:** Reimplementations of standard functions such as `ft_strlen`, `ft_memset`, `ft_memcpy`, and `ft_strdup`.
* **Additional functions:** Functions for more advanced string and memory operations, such as `ft_split`, `ft_strjoin`, `ft_strtrim`, and `ft_itoa`.
* **Linked list functions:** Functions for creating, manipulating, and deleting linked list nodes using the `t_list` structure.

Each function is implemented according to the requirements of the 42 Libft project.
