# </> MiniShell

Welcome to the MiniShell project! This is a simple shell implementation written in C. It supports basic shell commands and environment handling.

## 📁 Project Structure

```
cd.c
env_handling.c
include/lib.h
include/my.h
lib/my/free_word_array.c
lib/my/my_put_nbr.c
lib/my/my_putchar.c
lib/my/my_putstr.c
lib/my/my_str_to_word_array.c
lib/my/my_strcat.c
lib/my/my_strcmp.c
lib/my/my_strdup.c
lib/my/my_strlen.c
lib/my/my_strncmp.c
lib/my/my_strstr.c
main.c
Makefile
parsing.c
signal_checking.c
```

## 🚀 Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Building the Project

To build the project, run the following command:

```sh
make
```

This will compile the source files and generate the `mysh` executable.

### Running the Shell

To run the shell, execute the following command:

```sh
./mysh
```

## 📜 File Descriptions

### Main Files

- **main.c**: Entry point of the shell. Contains the main loop and command execution logic.
- **cd.c**: Implements the `cd` command.
- **env_handling.c**: Handles environment variables.
- **parsing.c**: Parses the input commands.
- **signal_checking.c**: Checks for signals like segmentation faults.

### Library Files

Located in the lib/my directory:

- **free_word_array.c**: Frees a word array.
- **my_put_nbr.c**: Prints a number.
- **my_putchar.c**: Prints a character.
- **my_putstr.c**: Prints a string.
- **my_str_to_word_array.c**: Splits a string into words.
- **my_strcat.c**: Concatenates two strings.
- **my_strcmp.c**: Compares two strings.
- **my_strdup.c**: Duplicates a string.
- **my_strlen.c**: Returns the length of a string.
- **my_strncmp.c**: Compares two strings up to a given number of characters.
- **my_strstr.c**: Finds a substring in a string.

### Header Files

Located in the include directory:

- **lib.h**: Contains function prototypes and includes necessary libraries.
- **my.h**: Contains function prototypes and the `env_t` struct definition.

## 🛠️ Development

### Code Style

The project follows the EPITECH coding style.

## 📄 License

This project is licensed under the MIT License.

## 👥 Authors

- Gabriel Decloquement

Feel free to contribute to this project by submitting issues or pull requests!