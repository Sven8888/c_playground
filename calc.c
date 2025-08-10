#include <stdio.h>    // printf, scanf, puts
#include <stdbool.h>  // bool, true, false
#include <math.h>     // math functions: fmod for floating-point modulo

int main(void) {
    puts("Mini Calc: use  +  -  *  /  m  (m = modulo via fmod).  Type q to quit.");

    while (true) {
        char op;
        double a, b;

        printf("> ");

        int n = scanf(" %c", &op);   // read operator or 'q'
        if (n != 1) { puts("\nInput error or EOF. Exiting."); break; }
        if (op == 'q' || op == 'Q') { puts("Bye."); break; }

        if (scanf(" %lf %lf", &a, &b) != 2) {
            puts("Need two numbers after the operator, e.g., + 3 5");
            int c; while ((c = getchar()) != '\n' && c != EOF) {} // clear line
            continue;
        }

        bool ok = true;
        double res = 0.0;

        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/':
                if (b == 0.0) { puts("Error: divide by zero"); ok = false; }
                else res = a / b;
                break;
            case 'm':  // floating-point modulo
                if (b == 0.0) { puts("Error: modulo by zero"); ok = false; }
                else res = fmod(a, b);
                break;
            default:
                puts("Unknown op. Use one of: + - * / m");
                ok = false;
        }

        if (ok) printf("= %.10g\n", res);
    }
    return 0;
}

