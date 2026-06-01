#include <stdio.h>
#include "patient.h"

// Returns 1 if acc_no already exists in the list, 0 otherwise
int check_duplicate(int acc_no)
{
    Patient *temp = head;

    while (temp != NULL)
    {
        if (temp->acc_no == acc_no)
        {
            printf("Duplicate found.\n");
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}
