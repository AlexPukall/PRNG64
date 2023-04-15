# PRNG64
Alexander PUKALL PRNG 64 

Pseudorandom Number Generator

LSFR 64 + LCG 64

128 bits seed

Source code in C and 6502 Assembler

Mix the output of a 64-bit Linear feedback shift register
and the output of a 64-bit Linear congruential generator

The output will be 2^64 random bits

With lfsr seed = 0xffffffffffffffff
and lcg seed = 0xffffffffffffffff

the 50 first bytes are:

83 CA C9 DF F3 82 B1 EB 1D 2D A2 6A 08 A4 7C 58 99 EB 8A 4F
99 B0 43 01 66 66 49 EC 77 C2 6E 91 6E E0 28 58 DD EF 5D 9D
BE F4 DF 57 1D 27 CA B4 2B 16 

Practrand test : ./prng64 | /rng_test stdin8
All tests OK (no anomalies), test with 2TB

CODE FREE TO USE EVEN FOR COMMERCIAL APPLICATIONS
NO RESTRICTION
