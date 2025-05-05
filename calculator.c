#include <stdio.h>
#include <stdlib.h>
    
    // Function prototypes

    void menu();
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    float divide(int a, int b);
    int factorial(int n);
    int isPrime(int n);
    void pause();
    
    int main() 
    {
        int choice;
        int a, b;
    
        while (1) 
        {
            menu();
            printf("Enter your choice: ");
            scanf("%d", &choice);
    
            switch (choice) 
            {
                case 1:
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", add(a, b));
                    pause();
                    break;
                
                case 2:
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", subtract(a, b));
                    pause();
                    break;
                
                case 3:
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", multiply(a, b));
                    pause();
                    break;
                
                case 4:
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    if (b == 0) 
                    {
                        printf("Division by zero error.\n");
                    }
                    else 
                    {
                        printf("Result: %.2f\n", divide(a, b));
                    }
                    pause();
                    break;
                
                case 5:
                    printf("Enter a number: ");
                    scanf("%d", &a);
                    printf("Factorial: %d\n", factorial(a));
                    pause();
                    break;
                
                case 6:
                    printf("Enter a number: ");
                    scanf("%d", &a);
                    if (isPrime(a))
                        printf("%d is prime.\n", a);
                    else
                        printf("%d is not prime.\n", a);
                    pause();
                    break;
    
                case 0:
                    printf("Exiting program.\n");
                    return 0;
                
                default:
                    printf("Invalid choice.\n");
                    pause();
            }
        }
    
        return 0;
    }
    
    void menu() 
    {
        printf("\n===== Simple Calculator Menu =====\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Factorial\n");
        printf("6. Check Prime\n");
        printf("0. Exit\n");
        printf("==================================\n");
    }
    
    int add(int a, int b) 
    {
        return a + b;
    }
    
    int subtract(int a, int b) 
    {
        return a - b;
    }
    
    int multiply(int a, int b) 
    {
        return a * b;
    }
    
    float divide(int a, int b) 
    {
        return (float)a / b;
    }
    
    int factorial(int n) 
    {
        if (n <= 1)
            return 1;
        return n * factorial(n - 1);
    }
    
    int isPrime(int n) 
    {
        if (n <= 1)
            return 0;
        for (int i = 2; i * i <= n; i++) 
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
    
    void pause() 
    {
        printf("Press Enter to continue...");
        while (getchar() != '\n');
        getchar();
    } 
