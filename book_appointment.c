#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

void book_appointment()
{
    Patient *new = (Patient *) malloc(sizeof(Patient));
    if (new == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("\n--- Book Appointment ---\n");

    printf("Enter Account Number : ");
    scanf("%d", &new->acc_no);

    if (check_duplicate(new->acc_no))
    {
        printf("Account number already exists.\n");
        free(new);
        return;
    }

    getchar(); // clear newline

    printf("Enter Patient Name   : ");
    fgets(new->name, sizeof(new->name), stdin);
    new->name[strcspn(new->name, "\n")] = '\0';

    printf("Enter Contact        : ");
    fgets(new->contact, sizeof(new->contact), stdin);
    new->contact[strcspn(new->contact, "\n")] = '\0';

    printf("Enter Room Number    : ");
    scanf("%d", &new->room_no);

    printf("Admitted? (1-Yes / 0-No): ");
    scanf("%d", &new->admitted);

    getchar(); // clear newline

    printf("Enter Doctor Name    : ");
    fgets(new->doctor, sizeof(new->doctor), stdin);
    new->doctor[strcspn(new->doctor, "\n")] = '\0';

    printf("Enter Disease/Issue  : ");
    fgets(new->disease, sizeof(new->disease), stdin);
    new->disease[strcspn(new->disease, "\n")] = '\0';

    printf("Enter Appointment Date (Join Date): ");
    fgets(new->join_date, sizeof(new->join_date), stdin);
    new->join_date[strcspn(new->join_date, "\n")] = '\0';

    printf("Enter Discharge Date : ");
    fgets(new->discharge_date, sizeof(new->discharge_date), stdin);
    new->discharge_date[strcspn(new->discharge_date, "\n")] = '\0';

    new->next = NULL;

    // Insert at end of linked list
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        Patient *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    printf("Appointment booked successfully! (Acc No: %d)\n", new->acc_no);
}
