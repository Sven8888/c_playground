/*
  main.c
  ------
  Entry point that calls our pointer demo module.
  Keeping main small is a good habit: it reads like a table of contents.
*/

#include <stdio.h>
#include "pointer_demo.h"  // brings in the declaration for pointer_demo_run()

int main(void) {
    puts("Lesson 1: Pointer Lab (modularized)");
    pointer_demo_run();  // all the interesting stuff is inside the module
    return 0;
}
