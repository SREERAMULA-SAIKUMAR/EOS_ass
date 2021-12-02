# Embedded Operating System

## TOPICS

- Embedded Systems vs General Purpose Systems
- Two and three layer Embedded Systems

- Modularize project and code
- Build
- Makefile

- Hex dump vs Execution under Embedded Linux

- ELF

- Parallelism
    - pseudo Parallelism
    - True Parallelism

- Uniprocessor
- Multiprocessor
- objdump -S
- Machine Code
- .text Section
- Cross-Compiler
- arm-linux-gnueabi-

## Filesystem

- Root FS
- Directory Structure

- Shell
    - Environment variables
    - PATH, USER
    - Custom Environment Variables

- Sections
    - .text => PC/IP
    - .data => global init
    - .bss => global uninitialized
    - heap => malloc
    - stack => return addr, local variables
- size
## C
- Header (importance header files)
- Library

- Declaration => Function prototype
- Definitions
## Library
- Static (.a) => archive
- Dynamic (.so) => gcc -shared -fPIC

- Using the library => -lname -Lpath

## PID and PPID

- getpid()
- getppid()


## Fork()

