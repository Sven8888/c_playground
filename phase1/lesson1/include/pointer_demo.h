#ifndef POINTER_DEMO_H
#define POINTER_DEMO_H
/*
  pointer_demo.h
  ----------------
  Public API for Lesson 1’s pointer demo module.

  WHY A HEADER?
  - Declarations live here so multiple .c files can call these functions.
  - Implementation stays in src/pointer_demo.c.
  - Keeps compile units small and encourages modular design.
*/

#ifdef __cplusplus
extern "C" {
#endif

// Run the pointer demonstration (prints to stdout).
void pointer_demo_run(void);

#ifdef __cplusplus
}
#endif

#endif /* POINTER_DEMO_H */
