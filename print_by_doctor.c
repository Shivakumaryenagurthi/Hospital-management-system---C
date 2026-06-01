#include <stdio.h>
#include <string.h>
#include "patient.h"

void print_by_doctor()
{
    char doc[50];

    getchar(); // clear buffer
    printf("Enter Doctor Name: ");
    fgets(doc, sizeof(doc), stdin);
    doc[strcspn(doc, "\n")] = '\0';

    Patient *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->doctor, doc) == 0)
        {
            printf("\nAcc No: %d | Name: %s | Disease: %s\n",
                   temp->acc_no, temp->name, temp->disease);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("No patients found for this doctor!\n");
}
