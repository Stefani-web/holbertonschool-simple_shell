# <p align="center">Simple_Shell - C</p>

<p align="center">
<img src="https://cdn.discordapp.com/attachments/1217825406699180052/1232665014717120572/SimpleShell.jpg?ex=662a4841&is=6628f6c1&hm=fbe5c3fcda6a486c3ffb2dd1db7480d4e3eed39434f273fdc5aa98bfe3dd4d23&" alt="Created illustration SShell en C"/>
</p>

## ➤ DESCRIPTION

SimpleShell is a basic shell written in C, designed to provide an interface between the user and the operating system. It allows users to enter commands through a command line interface, which are then executed by the system

## ➤ UML - ACTIVITY DIAGRAM

TO DO

## ➤ INSTALLATION INSTRUCTIONS AND HOW TO USE IT

```
To compile and run SimpleShell project in C, follow the steps below:

0. A C compiler: All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

1. Install a C compiler :
    Make sure you have a C compiler installed on your system. GCC is a popular choice for Unix systems, while Visual Studio is commonly used on Windows.

2. Download the source code:
    Clone or download the project source code from the GitHub repository or any other code sharing platform.

3. Compile the project:
Open a terminal or command prompt and navigate to the directory containing the source code. Compile the code using the following command:
```bash
gcc -o source_program_name.c

```
here we will use the following compilation:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## EXECUTION

Run the generated binary to start the shell.
To start the shell you need to run this binary file. Here are the general steps:

```
0. Open a terminal on your system.
1. Navigate to the directory where the binary file is located.
2. Launch the shell by typing the name of the binary file preceded by ./
(which indicates the current directory in Unix systems).
3. The binary file is called SimpleShell, you would start it with the following command:

```
```
./hsh
```

## ➤ Check for memory leaks

Installing Valgrind:
Valgrind is a debugging tool that helps detect memory leaks, memory usage errors, and other memory-related issues.
To install it, open a terminal and run the appropriate command depending on your operating system:
On Linux (Debian/Ubuntu):
```
sudo apt-get install valgrind
```
Using Valgrind:
After installing Valgrind, you can use it to check your program (for example, your shell) for memory leaks.
To run Valgrind on your program, use the following command (replacing your_program with the name of your binary):
```
valgrind --leak-check=full ./hsh
```
**--leak-check=full** enables full memory leak checking.
Valgrind will display any memory leaks and other issues detected.

![valgrind Test](https://cdn.discordapp.com/attachments/1230499916309069895/1232696943759855806/valgring_test.jpg?ex=662a65fd&is=6629147d&hm=992ec3937d614a6a0f6acbec16a2cb6cc7a902e139d305803595b0c27f456d53&)

## ➤ MAN

command use :
```
man ./man_1_simple_shell
```

## ➤ EXAMPLES TESTING

Testing your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## ➤ LIBRARIES USED

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
```

## ➤ PROTOTYPES

```
extern char **environ;

char **split_string(char *line);
char *get_path(char *input_line);
void free_args(char **strings_array);
void execute_command(char **command_args, int command_number);
char *_getenv(const char *name);
```

## ➤ TUTORIALS

- [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [PID & PPID](https://www.youtube.com/watch?v=PZrQ4eGm-hM&ab_channel=CodeVault)

## ➤ REQUIREMENTS

* Compilation: Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All your header files should be include guarded

## ➤ LICENSE

Distributed under the MIT License. See [LICENSE](https://github.com/Stefani-web/holbertonschool-simple_shell/blob/main/LICENSE) for more information.

Copyright (c) 2024 Ines Ouazene - Stephanie CARVALHO

## ➤ [AUTHORS](https://github.com/Stefani-web/holbertonschool-simple_shell/blob/main/AUTHORS)

* [Ines Ouazene](https://github.com/inesouazene)
* [Stephanie Carvalho](https://github.com/Stefani-web)
