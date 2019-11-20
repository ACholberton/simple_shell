# A Simple Shell

## Description

*Write a UNIX command line interpreter.

---

## Requirements

*Display a prompt and wait for the user to type a command. A command line always ends with a new line.
*The prompt is displayed again each time a command has been executed.
*If an executable cannot be found, print an error message and display the prompt again.
*Handle errors.
*You have to handle the end of file condition (Ctrl+D)
*Allowed editors: vi, vim, emacs
*All your files will be compiled on Ubuntu 14.04 LTS
*Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
*All your files should end with a new line
*A README.md file, at the root of the folder of the project is mandatory
*Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
*No more than 5 functions per file
*All your header files should be include guarded
*Allowed functions and system calls: access, chdir, close, closedir, execve, \
exit, _exit, fflush, fork, free, getcwd, getline, isatty, kill, malloc, \
open, opendir, perror, read, readdir, signal, stat, lstat, fstat, strtok, \
wait, waitpid, wait3, wait4, write.

---

## Input

*a command entered by the user.

```
USER $ ls

```

## Output
* an executed program.

```
USER $ ls

file1  file2  file3  file4

```

## Authors
* Andres Cheung [ACholberton](https://github.com/ACholberton)
* Nick Uchida [nickuchida](https://github.com/nickuchida)

---