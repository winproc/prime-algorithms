#include <stdio.h>
#include <stdlib.h>

#define CH_PRIME 7

int* range_prime(int n);
int linear_prime(int n);

// uses sieve of eratosthenes to get prime numbers until n, returns pointer to array of n - 1 elements
int* range_prime(int n) {

    int block_size = n - 1;
    int* nblock = (int*)malloc(sizeof(int) * block_size); // allocate memory

    // assign values from 2 -> block-size
    for (int i = 0; i < block_size; i++) {
        nblock[i] = i + 2;
    }

    // algorithm
    for (int i = 0; i < CH_PRIME; i++) {
        int base_primer = nblock[i];
        
        if (base_primer != 0 && i <= block_size) { // prevent overflow by checking index
            for (int iv = 0; iv < block_size; iv++) {

                if (!(nblock[iv])) { continue; } // break iteration if index is 0
                if (nblock[iv] != base_primer && nblock[iv] % base_primer == 0) {
                    nblock[iv] = 0;
                }

            }
        }
    } 
    
    return nblock;
}

// get prime by linear iteration
int linear_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int prime;
    scanf("%d", &prime);

    printf("%d\n", linear_prime(prime));

    int* arrptr = range_prime(prime); // get prime nums from 2 -> prime
    for (int i = 0; i < prime - 1; i++) {
        if (arrptr[i] == 0) { continue; }
        printf("n: %d\n", arrptr[i]); // print list
    }
    free(arrptr);

    return 0;
}