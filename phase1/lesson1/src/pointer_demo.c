/*
  pointer_demo.c
  --------------
  Implementation of Lesson 1 pointer lab.

  KEY IDEAS
  - A pointer stores a memory ADDRESS.
  - &x  = address-of x
  - *p  = dereference (go to address in p, read/write that object)
  - Arrays decay to pointer-to-first-element in most expressions.
  - Pointer arithmetic moves by ELEMENTS, not bytes.

  BUILD (from lesson folder):
    make
  RUN:
    ./ptr_lab1
*/

#include <stdio.h>     // printf, puts
#include <stdint.h>    // fixed-width integer types (useful for embedded)
#include "pointer_demo.h"

void pointer_demo_run(void) {
    // ---- 1) A plain int and a pointer to it ------------------------------
    int x = 42;             // 'x' is an int on the stack frame of this function
    int *p = &x;            // 'p' holds the ADDRESS of x

    // %p expects void*, so cast addresses to (void*) to print portably
    printf("x value               = %d\n", x);
    printf("&x (address)          = %p\n", (void*)&x);
    printf("p (same as &x)        = %p\n", (void*)p);

    // DEREFERENCE: read the int at the address stored in p
    printf("*p (read via p)       = %d\n", *p);

    // Write through the pointer (modifies x)
    *p = 100;
    printf("after *p = 100, x     = %d (x actually changed)\n", x);

    // ---- 2) Arrays and decay to pointers --------------------------------
    int a[4] = {10, 20, 30, 40}; // contiguous block of 4 ints
    int *q = a;                  // in this expression, 'a' decays to &a[0]

    puts("\nArray basics");
    printf("a (=&a[0])            = %p\n", (void*)a);
    printf("q                      = %p\n", (void*)q);

    // Pointer arithmetic moves by sizeof(*q) bytes; here *q is int (typically 4 bytes)
    printf("q+1                    = %p  (moved by sizeof(*q) bytes)\n", (void*)(q + 1));
    printf("*(q+2)                 = %d  (3rd element)\n", *(q + 2)); // expect 30
    printf("q[0]=%d q[1]=%d q[2]=%d q[3]=%d\n", q[0], q[1], q[2], q[3]);

    // ---- 3) Viewing memory as bytes -------------------------------------
    // If you truly need byte steps, cast to unsigned char*
    unsigned char *b = (unsigned char*)a;
    puts("\nByte-wise view");
    printf("b                      = %p\n", (void*)b);
    printf("b+1                    = %p  (moved by 1 byte)\n", (void*)(b + 1));

    // ---- 4) Pitfalls -----------------------------------------------------
    // int *danger; *danger = 5; // UB: uninitialized pointer (garbage address)
    // int *np = NULL; *np = 5;  // UB: NULL is not a valid object location

    // ---- 5) Self-check ---------------------------------------------------
    puts("\nSelf-check: On your system, does q+1 advance by 4 or 8 bytes, and why?");
}
