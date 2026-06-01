#include <stdio.h>
#include <string.h>
#include "patient.h"

// Helper: print one patient's full details
static void print_patient(Patient *p)
{
    printf("\n  Acc No       : %d",  p->acc_no);
    printf("\n  Name         : %s",  p->name);
    printf("\n  Contact      : %s",  p->contact);
    printf("\n  Room No      : %d",  p->room_no);
    printf("\n  Admitted     : %s",  p->admitted ? "Yes" : "No");
    printf("\n  Doctor       : %s",  p->doctor);
    printf("\n  Disease      : %s",  p->disease);
    printf("\n  Join Date    : %s",  p->join_date);
    printf("\n  Discharge    : %s\n", p->discharge_date);
    printf("  --------------------------\n");
}

void find_patient()
{
    if (head == NULL)
    {
        printf("No patients in the system.\n");
        return;
    }

    printf("\n--- Find Patient ---\n");
    printf("1. Search by Account Number (ID)\n");
    printf("2. Search by Name\n");
    printf("3. Search by Contact\n");
    printf("Enter choice: ");

    int choice;
    scanf("%d", &choice);
    getchar(); // clear buffer

    Patient *temp = head;
    int found = 0;

    if (choice == 1)
    {
        int id;
        printf("Enter Account Number: ");
        scanf("%d", &id);

        while (temp != NULL)
        {
            if (temp->acc_no == id)
            {
                print_patient(temp);
                found = 1;
                break;
            }
            temp = temp->next;
        }
    }
    else if (choice == 2)
    {
        char name[50];
        printf("Enter Name (or part of name): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        while (temp != NULL)
        {
            // Case-sensitive partial match
            if (strstr(temp->name, name) != NULL)
            {
                print_patient(temp);
                found = 1;
            }
            temp = temp->next;
        }
    }
    else if (choice == 3)
    {
        char contact[15];
        printf("Enter Contact: ");
        fgets(contact, sizeof(contact), stdin);
        contact[strcspn(contact, "\n")] = '\0';

        while (temp != NULL)
        {
            if (strcmp(temp->contact, contact) == 0)
            {
                print_patient(temp);
                found = 1;
            }
            temp = temp->next;
        }
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    if (!found)
        printf("No matching patient found.\n");
}
