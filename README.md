*This project has been created as part of the 42 curriculum by tkazmina <tkazmina@student.codam.nl>* 

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C `printf` function. The goal of this project is to recreate formatted output handling using variadic arguments, closely mimicking the behavior of the original `printf`.

---

## Features

* Supports the following format specifiers:

  * `%c` : character
  * `%s` : string
  * `%p` : pointer address (in hexadecimal format)
  * `%d` / `%i` : signed integers
  * `%u` : unsigned integers
  * `%x` : lowercase hexadecimal
  * `%X` : uppercase hexadecimal
  * `%%` : literal `%`

---

## Function Prototype

```c
int ft_printf(const char *format, ...);
```

---

## Return Value

* Returns the total number of characters printed
* Returns `-1` if an error occurs

---

## Instructions

To compile the library:

```shell
$ cd path/to/ft_printf && make
```

---

## Usage

Include the header file in your project:

```c
#include "ft_printf.h"
```

Example:

```c
ft_printf("Hello %s! Number: %d\n", "world", 42);
```

## Resources

### Documentation & references

- [cppreference.com](https://en.cppreference.com/w/c)
- [man pages online — Linux man-pages project](https://man7.org/linux/man-pages/)
- [Stack Overflow](https://stackoverflow.com/)

