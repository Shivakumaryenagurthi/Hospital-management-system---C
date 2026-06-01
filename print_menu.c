#include <stdio.h>
#include "patient.h"

void print_menu()
{
    int choice;

    printf("\n--- PRINT SUB-MENU ---\n");
    printf("1. Print all patients (complete details)\n");
    printf("2. Print specific patient details\n");
    printf("3. Print patients of a specific doctor\n");
    printf("4. Print patients with a specific disease/issue\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1: print_all();        break;
        case 2: print_by_acc();     break;
        case 3: print_by_doctor();  break;
        case 4: print_by_disease(); break;
        default: printf("Invalid choice!\n");
    }
}
