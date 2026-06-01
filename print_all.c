#include <stdio.h>
#include "patient.h"

void print_all()
{
    if (head == NULL)
    {
        printf("No patients available!\n");
        return;
    }

    Patient *temp = head;

    printf("\n--- All Patients ---\n");

    while (temp != NULL)
    {
        printf("\nAcc No       : %d", temp->acc_no);
        printf("\nName         : %s", temp->name);
        printf("\nContact      : %s", temp->contact);
        printf("\nRoom No      : %d", temp->room_no);
        printf("\nAdmitted     : %s", temp->admitted ? "Yes" : "No");
        printf("\nDoctor       : %s", temp->doctor);
        printf("\nDisease      : %s", temp->disease);
        printf("\nJoin Date    : %s", temp->join_date);
        printf("\nDischarge    : %s\n", temp->discharge_date);
        printf("------------------------\n");

        temp = temp->next;
    }
}
