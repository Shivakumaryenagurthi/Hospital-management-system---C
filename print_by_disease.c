#include <stdio.h>
#include <string.h>
#include "patient.h"

void print_by_disease()
{
    char dis[50];

    getchar(); // clear buffer
    printf("Enter Disease: ");
    fgets(dis, sizeof(dis), stdin);
    dis[strcspn(dis, "\n")] = '\0';

    Patient *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->disease, dis) == 0)
        {
            printf("\nAcc No: %d | Name: %s | Doctor: %s\n",
                   temp->acc_no, temp->name, temp->doctor);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("No patients found for this disease!\n");
}
