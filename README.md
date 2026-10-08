# Simple Shell

A simple Unix-like shell written in C that reads commands from standard input, parses them, and executes them using the system PATH.

## Features

- Displays a prompt (`cisfun$ `) in interactive mode
- Executes commands found in the current environment PATH
- Supports command arguments
- Handles `exit` and `env` built-ins
- Uses `fork` and `execve` to run programs
- Returns exit status for child processes

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh
```

## Usage

```bash
./hsh
```

Then type commands such as:

```bash
ls
/bin/ls -l /tmp
env
exit
```

## Example

```bash
$ ./hsh
cisfun$ ls
AUTHORS  README.md  env.c  execFork.c  shell.c  hsh
cisfun$ exit
```

## Authors

- Henok Haile
- Amir Michael
