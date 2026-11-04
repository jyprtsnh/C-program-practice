#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void print_menu(void);
void clear_input_buffer(void);
void perform_addition(void);
void perform_subtraction(void);
void perform_multiplication(void);
void perform_division(void);
void perform_modulus(void);
void perform_power(void);
void perform_sqrt(void);
void perform_trig(int choice);

int main(void) {
    int choice = 0;

    printf("===============================================\n");
    printf("     Welcome to the C Advance CLI Calculator   \n");
    printf("===============================================\n");

    while (1) {
        print_menu();
        printf("Enter your choice (1-10): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid input. Please enter a valid number.\n\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                perform_addition();
                break;
            case 2:
                perform_subtraction();
                break;
            case 3:
                perform_multiplication();
                break;
            case 4:
                perform_division();
                break;
            case 5:
                perform_modulus();
                break;
            case 6:
                perform_power();
                break;
            case 7:
                perform_sqrt();
                break;
            case 8:
            case 9:
            case 10:
                perform_trig(choice);
                break;
            case 0:
                printf("\nThank you for using the calculator. Goodbye!\n");
                exit(0);
            default:
                printf("\nError: Invalid choice. Please choose between 0 and 10.\n");
        }
        printf("\n---------------------------------------\n\n");
    }

    return 0;
}

void print_menu(void) {
    printf("\nSelect an operation:\n");
    printf(" 1. Addition (+)\n");
    printf(" 2. Subtraction (-)\n");
    printf(" 3. Multiplication (*)\n");
    printf(" 4. Division (/)\n");
    printf(" 5. Modulus (%%)\n");
    printf(" 6. Power (x^y)\n");
    printf(" 7. Square Root (√x)\n");
    printf(" 8. Sine (sin x)\n");
    printf(" 9. Cosine (cos x)\n");
    printf("10. Tangent (tan x)\n");
    printf(" 0. Exit\n");
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void perform_addition(void) {
    double a, b;
    printf("\n--- Addition ---\n");
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) == 2) {
        printf("Result: %.4f + %.4f = %.4f\n", a, b, a + b);
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}

void perform_subtraction(void) {
    double a, b;
    printf("\n--- Subtraction ---\n");
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) == 2) {
        printf("Result: %.4f - %.4f = %.4f\n", a, b, a - b);
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}

void perform_multiplication(void) {
    double a, b;
    printf("\n--- Multiplication ---\n");
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) == 2) {
        printf("Result: %.4f * %.4f = %.4f\n", a, b, a * b);
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}

void perform_division(void) {
    double a, b;
    printf("\n--- Division ---\n");
    printf("Enter dividend and divisor: ");
    if (scanf("%lf %lf", &a, &b) == 2) {
        if (b == 0) {
            printf("Error: Division by zero is undefined.\n");
        } else {
            printf("Result: %.4f / %.4f = %.4f\n", a, b, a / b);
        }
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}

void perform_modulus(void) {
    int a, b;
    printf("\n--- Modulus (Integer Remainder) ---\n");
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) == 2) {
        if (b == 0) {
            printf("Error: Division by zero (modulus) is undefined.\n");
        } else {
            printf("Result: %d %% %d = %d\n", a, b, a % b);
        }
    } else {
        printf("Error: Invalid integer input.\n");
        clear_input_buffer();
    }
}

void perform_power(void) {
    double base, exponent;
    printf("\n--- Exponentiation (x^y) ---\n");
    printf("Enter base and exponent: ");
    if (scanf("%lf %lf", &base, &exponent) == 2) {
        printf("Result: %.4f ^ %.4f = %.4f\n", base, exponent, pow(base, exponent));
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}

void perform_sqrt(void) {
    double num;
    printf("\n--- Square Root ---\n");
    printf("Enter a number: ");
    if (scanf("%lf", &num) == 1) {
        if (num < 0) {
            printf("Error: Cannot calculate square root of a negative number in real numbers.\n");
        } else {
            printf("Result: √%.4f = %.4f\n", num, sqrt(num));
        }
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}

void perform_trig(int choice) {
    double degrees, radians;
    printf("Enter angle in degrees: ");
    if (scanf("%lf", &degrees) == 1) {
        radians = degrees * (PI / 180.0);
        if (choice == 8) {
            printf("Result: sin(%.2f°) = %.4f\n", degrees, sin(radians));
        } else if (choice == 9) {
            printf("Result: cos(%.2f°) = %.4f\n", degrees, cos(radians));
        } else if (choice == 10) {
            // Check for tan undefined cases (90, 270, etc.)
            if (fmod(degrees - 90.0, 180.0) == 0.0) {
                printf("Error: Tangent is undefined at %.2f degrees.\n", degrees);
            } else {
                printf("Result: tan(%.2f°) = %.4f\n", degrees, tan(radians));
            }
        }
    } else {
        printf("Error: Invalid numeric input.\n");
        clear_input_buffer();
    }
}