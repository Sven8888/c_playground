#include <stdio.h>    // printf
#include <stdint.h>   // fixed-width types like uint32_t
#include <inttypes.h> // printf macros for fixed-width ints (not used yet, but handy)
#include <stddef.h>   // size_t

int main(void) {
    printf("== Host (your machine) ==\n");
    printf("char        : %zu\n", sizeof(char));
    printf("short       : %zu\n", sizeof(short));
    printf("int         : %zu\n", sizeof(int));
    printf("long        : %zu\n", sizeof(long));
    printf("long long   : %zu\n", sizeof(long long));
    printf("pointer     : %zu\n", sizeof(void*));

    printf("\n== Typical MCU (ILP32) reference ==\n");
    printf("char        : 1\n");
    printf("short       : 2\n");
    printf("int         : 4\n");
    printf("long        : 4\n");
    printf("long long   : 8\n");
    printf("pointer     : 4\n");

    // Bonus: quick “guess” of your model
    printf("\nModel guess: ");
    if (sizeof(long) == 8 && sizeof(void*) == 8 && sizeof(int) == 4) {
        printf("LP64 (common on 64-bit Linux/macOS)\n");
    } else if (sizeof(long) == 4 && sizeof(void*) == 8 && sizeof(int) == 4) {
        printf("LLP64 (common on 64-bit Windows)\n");
    } else if (sizeof(long) == 4 && sizeof(void*) == 4 && sizeof(int) == 4) {
        printf("ILP32 (common on 32-bit MCUs)\n");
    } else {
        printf("Unusual/other\n");
    }

    return 0;
}
