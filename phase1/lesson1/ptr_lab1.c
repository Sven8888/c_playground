/*
  Lesson 1: Pointer Lab 1
  ---------------------------------------------------------
  GOALS
  - Understand what a pointer is (a variable that stores a memory address)
  - Understand & (address-of) and * (dereference)
  - See how arrays “decay” to pointers
  - See pointer arithmetic by ELEMENTS, not bytes
  - Practice printing addresses safely with %p (cast to void*)

  BUILD
    gcc -Wall -Wextra -Werror -std=c17 -O0 -g ptr_lab1.c -o ptr_lab1

  RUN
    ./ptr_lab1

  DEBUG (quick peek with gdb)
    gdb ./ptr_lab1 -q
      (gdb) break main
      (gdb) run
      (gdb) print x
      (gdb) print p
      (gdb) x/4dw a     // examine 4 decimal words starting at 'a'
      (gdb) quit

  WHY THIS MATTERS (EMBEDDED PREVIEW)
  - MCU peripherals (GPIO, UART, I2C, timers) are exposed as memory-mapped registers.
  - Accessing those addresses is literally: *(volatile uint32_t*)0x40020000 = 0x01;
  - Today’s pointer/dereference skills become tomorrow’s hardware control.
*/

#include <stdio.h>   // printf
#include <stdint.h>  // fixed-width types (handy for embedded), e.g., uint8_t, uint32_t
#include <inttypes.h> // portable integer print macros (we’ll use later)

int main(void) {
    // ---- 1) A plain int and a pointer to it ------------------------------
    int x = 42;        // 'x' is an int living on the stack in this function frame.
    int *p = &x;       // 'p' stores the ADDRESS of x. Type: "pointer to int".

    // %p expects a void*, so we cast addresses to (void*) to print them safely/portably.
    printf("x value               = %d\n", x);
    printf("&x (address)          = %p\n", (void*)&x);
    printf("p (same as &x)        = %p\n", (void*)p);

    // DEREFERENCE: '*p' means "go to the address stored in p and read/write the int there"
    printf("*p (read via p)       = %d\n", *p);

    // Write through the pointer: modifies x because p points AT x
    *p = 100;
    printf("after *p = 100, x     = %d (x actually changed!)\n", x);

    // ---- 2) Arrays and decay to pointers --------------------------------
    int a[4] = {10, 20, 30, 40};  // contiguous block: [10][20][30][40]
    // In many expressions, 'a' "decays" to a pointer to its first element (&a[0]).
    int *q = a; // same as: int *q = &a[0];

    printf("\nArray basics\n");
    printf("a (=&a[0])            = %p\n", (void*)a);
    printf("q                      = %p\n", (void*)q);

    // IMPORTANT: Pointer arithmetic advances by ELEMENTS (sizeof(*q)), not bytes.
    // Here, *q is an int, so q+1 moves by sizeof(int) bytes (usually 4 on Linux x86-64).
    printf("q+1                    = %p  (moved by sizeof(*q) bytes)\n", (void*)(q + 1));
    printf("*(q+2)                 = %d  (3rd element)\n", *(q + 2)); // should print 30

    // Array indexing is just syntactic sugar: q[i] == *(q + i)
    printf("q[0]=%d q[1]=%d q[2]=%d q[3]=%d\n", q[0], q[1], q[2], q[3]);

    // ---- 3) Viewing memory as BYTES (sometimes needed) -------------------
    // To move by BYTES instead of elements, cast to unsigned char* (a byte pointer).
    unsigned char *b = (unsigned char*)a;
    printf("\nByte-wise view\n");
    printf("b                      = %p\n", (void*)b);
    printf("b+1                    = %p  (moved by 1 byte)\n", (void*)(b + 1));

    // NOTE: Reinterpreting memory with a different pointer type is advanced.
    // We’re only printing addresses here. Be careful with strict aliasing rules in real code.

    // ---- 4) Common pointer pitfalls (DON’T DO THESE) ---------------------
    // int *danger;    // Uninitialized pointer: contains garbage address.
    // *danger = 5;    // Undefined behavior: writing to a random address.
    // int *np = NULL;
    // *np = 5;        // Also undefined behavior: NULL is not a valid object address.

    // ---- 5) Mini self-check prompt --------------------------------------
    // On your machine, does q+1 advance by 4 or 8 bytes, and why?
    // Answer: it advances by sizeof(int) bytes; on typical Linux x86-64, int is 4 bytes.

    return 0;
}
