# Simple Shell

This repository contains the simple UNIX command interpreter project developed in C for Holberton School by cohort10 students.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You need to have and install:

```
Ubuntu 14.04 LTS
gcc 4.8.4
```

### Installing

After you have cloned this repository, you must compile the project with:

```sh
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Running

To run the program in interactive mode:

```sh
$ ./hsh
$ /bin/ls
$ hsh main.c shell.c
```

To run the program in non-interactive mode:

```sh
$ echo "/bin/ls" | ./hsh
$ hsh main.c shell.c test_ls_2
```

## Built With

* [C - programming language](https://en.wikipedia.org/wiki/C_(programming_language)) - The programing language used.

## Authors

* **Diego Garzon** - *Holberton Student* - [GitHub](https://github.com/diesgaro)
* **Stuart Echeverry** - *Holberton Student* - [GitHub](https://github.com/stuartses)

See also the list of [contributors](https://github.com/stuartses/simple_shell/blob/master/AUTHORS) who participated in this project.

## License

This project is licensed under the MIT License.
