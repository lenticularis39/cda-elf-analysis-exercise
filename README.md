# CDA ELF Analysis Exercise

This repository contains the sources of three binaries, each of them reads
a password from standard input, compares it with a fixed value, and prints
whether the two match.

The task is to reconstruct the password from the program binaries using
`readelf`, `objdump`, eventually also `strings`. Correct answers can be easily
deduced from the source code of the exercises.

## Exercise 1

The password is stored in the `.data` section at the end, clearly separated
from the rest of the data, where it can be found by both `readelf` and `strings`.

## Exercise 2

*Hint: look at the sections header for clues*

The password is stored in a custom section called `.secretsection`. On the top
of that, it is stored in between two other strings without any separation.

Hence, `objdump` has to be used to deduce the exact arguments to `strncmp` to
get the address, which can be then used together with the start address of the
section to determine the offset inside the section.

(Alternatively, the address of the `passwords` symbol can be used.)

## Exercise 3

The password is determined by a series of compare instructions
`cmp    $0x--,%al`. With some knowledge of x86 assembly, this should be easy to
see; it is also possible to deduce without much understanding of assembly, since
it is the only compare instruction operating on bytes in the code.