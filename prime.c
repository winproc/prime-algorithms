#include <stdio.h>
#include <stdlib.h>

#define MAX_ATTEMPT 7

int sieve_prime(int n);
int linear_prime(int n);

// uses sieve of eratosthenes to get prime number
int sieve_prime(int n) {

    int block_size = n - 1;
    int* nblock = (int*)malloc(sizeof(int) * block_size); // allocate memory

    // assign values from 2 -> block-size
    for (int i = 0; i < block_size; i++) {
        nblock[i] = i + 2;
    }

    // algorithm
    for (int i = 0; i < MAX_ATTEMPT; i++) {
        int base_primer = nblock[i];

        if (base_primer != 0) {
            for (int iv = 0; iv < block_size; iv++) {

                if (!(nblock[iv])) { continue; } // break iteration if index is 0
                if (nblock[iv] != base_primer && nblock[iv] % base_primer == 0) {
                    nblock[iv] = 0;
                }

            }
        }
    } 

    int result = nblock[block_size - 1] ? 1 : 0; // get last int and return 1 or 0

    free(nblock);
    
    return result;
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
    printf("%d", sieve_prime(prime));
    return 0;
}