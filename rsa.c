#include "rsa.h"

/*Fonctions pour la generation de cle publique et privee, et de chiffrement RSA*/



/*Calcul le pgcd de 2 entiers naturels*/
int pgcd(int a, int b){
    if (a>b)
        return pgcd(b,a);
    if (a == 0)
        return b;
    else
        return pgcd(a, b%a);

}

/*Fonction qui verifie si deux entiers sont premiers entre eux*/
int premiers(int a, int b){
    if (pgcd(a,b)==1)
        return 1;
    else
        return 0;
}

/*Choix de e*/
int e(int phi_n){
    int res = phi_n / 6;
    while (!(premiers(res,phi_n)))
        res++;
    return res;
}



/*
int d(int _e, int phi_n){
    for (int i = 1; i < phi_n ;i++){
        if ((_e*i) % phi_n == 1){
            return i;
        }
    }
    return -1;
}
*/

int modInverse(int x, int n) {
    int m0 = n, t, q;
    int x0 = 0, x1 = 1;

    if (n == 1)
        return -1;

    // Apply extended Euclidean algorithm
    while (x > 1) {
        q = x / n;
        t = n;

        n = x % n;
        x = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to calculate private exponent d given e and phi_n
int d(int _e, int phi_n) {
    // Calculate the modular inverse of e modulo phi_n
    int d = modInverse(_e, phi_n);

    return d;
}


int puissance(int x, int n){
    int res = 1;
    for (int i = 0; i<n ; i++)
        res *= x;
    return res;
}

int size_bloc(int n){
    int t = 0;
    while (puissance(2,t) < n){
        t++;
    }
    return t-1;
}


//Preparation pour chiffrer en RSA une cle AES
//http://www.acrypta.com/telechargements/fichecrypto_202.pdf




//https://github.com/yigitusta/RSA-Implementation

int rsa_cipher_bloc(int m, int e, int n){
    int i;
    unsigned long long int result = 1;
    for (i = 0; i < e; i++)
    {
        result = (result * m) % n;
    }
    return result;
}

int rsa_decipher_bloc(int mc,int d, int n){
    int i;
    unsigned long long int result = 1;
    for (i = 0; i < d; i++)
    {
        result = (result * mc) % n;
    }
    return result;
}

//Chiffrement RSA pour 2^8 < n < 2^16

void rsa_c(int* m, int size_m, int e, int n){

    for (int i =0; i<size_m; i++)
        m[i] = rsa_cipher_bloc(m[i],e, n);
}

void rsa_c_d(int* mc, int size_m, int d, int n){

    for (int i =0; i<size_m; i++)
        mc[i] = rsa_decipher_bloc(mc[i],d, n);
}
