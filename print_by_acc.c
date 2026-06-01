#include <stdio.h>
#include "patient.h"

void print_by_acc()
{
    int acc;
    printf("Enter Account Number: ");
    scanf("%d", &acc);

    Patient *temp = head;

    while (temp != NULL)
    {
        if (temp->acc_no == acc)
        {
            printf("\nPatient Found!\n");
            printf("Name    : %s\n", temp->name);
            printf("Doctor  : %s\n", temp->doctor);
            printf("Disease : %s\n", temp->disease);
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found!\n");
}
