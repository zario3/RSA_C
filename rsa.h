#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int pgcd(int a, int b);
int premiers(int a, int b);
int e(int phi_n);
int d(int a, int b);
int puissance(int x, int n);
int size_bloc(int n);
int rsa_cipher_bloc(int m, int e, int n);
int rsa_decipher_bloc(int mc,int d, int n);
void rsa_c(int* m, int size_m, int e, int n);
void rsa_c_d(int* mc, int size_m, int d, int n);
int modInverse(int a, int m);
