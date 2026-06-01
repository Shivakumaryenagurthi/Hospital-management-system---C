#include <stdio.h>
#include "patient.h"

// Global head pointer – shared across all source files via extern in patient.h
Patient *head = NULL;

int main()
{
    char choice;

    while (1)
    {
        printf("\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n");
        printf(" A - Book appointment to visit doctor\n");
        printf(" P - Print patient details (sub-menu)\n");
        printf(" S - Save all data to file\n");
        printf(" F - Find / search a patient\n");
        printf(" M - Modify patient details\n");
        printf(" X - Delete a patient record\n");
        printf(" Q - Quit\n");
        printf("=================================================\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A': case 'a': book_appointment(); break;
            case 'P': case 'p': print_menu();       break;
            case 'S': case 's': save_to_file();     break;
            case 'F': case 'f': find_patient();     break;
            case 'M': case 'm': modify_patient();   break;
            case 'X': case 'x': delete_patient();   break;
            case 'Q': case 'q': 
                printf("Goodbye!\n"); 
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
