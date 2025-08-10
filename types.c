#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
    printf("char:        %zu\n", sizeof(char));
    printf("short:       %zu\n", sizeof(short));
    printf("int:         %zu\n", sizeof(int));
    printf("long:        %zu\n", sizeof(long));
    printf("long long:   %zu\n", sizeof(long long));
    printf("float:       %zu\n", sizeof(float));
    printf("double:      %zu\n", sizeof(double));
    printf("pointer:     %zu\n", sizeof(void*));

    // A couple of ranges you’ll use a lot
    printf("INT_MIN..INT_MAX:   %d..%d\n", INT_MIN, INT_MAX);
    printf("UINT_MAX:           %u\n", UINT_MAX);
    return 0;
}
