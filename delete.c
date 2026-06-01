#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

void delete_patient()
{
    if (head == NULL)
    {
        printf("No patients in the system.\n");
        return;
    }

    int acc;
    printf("\n--- Delete Patient ---\n");
    printf("Enter Account Number of patient to delete: ");
    scanf("%d", &acc);

    Patient *curr = head;
    Patient *prev = NULL;

    while (curr != NULL)
    {
        if (curr->acc_no == acc)
        {
            // Confirm before deleting
            printf("Are you sure you want to delete '%s'? (1-Yes / 0-No): ",
                   curr->name);
            int confirm;
            scanf("%d", &confirm);

            if (confirm != 1)
            {
                printf("Deletion cancelled.\n");
                return;
            }

            // Unlink the node
            if (prev == NULL)
                head = curr->next;   // deleting head
            else
                prev->next = curr->next;

            free(curr);
            printf("Patient deleted successfully.\n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Patient with Account Number %d not found.\n", acc);
}
