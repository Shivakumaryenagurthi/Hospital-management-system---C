#include <stdio.h>
#include <string.h>
#include "patient.h"

void modify_patient()
{
    if (head == NULL)
    {
        printf("No patients in the system.\n");
        return;
    }

    int acc;
    printf("\n--- Modify Patient ---\n");
    printf("Enter Account Number of patient to modify: ");
    scanf("%d", &acc);
    getchar(); // clear buffer

    Patient *temp = head;
    while (temp != NULL)
    {
        if (temp->acc_no == acc)
        {
            printf("Patient found: %s\n", temp->name);
            printf("\nWhich field do you want to modify?\n");
            printf("1.  Name\n");
            printf("2.  Contact\n");
            printf("3.  Room Number\n");
            printf("4.  Admitted Status\n");
            printf("5.  Doctor\n");
            printf("6.  Disease / Issue\n");
            printf("7.  Join / Appointment Date\n");
            printf("8.  Discharge Date\n");
            printf("Enter choice: ");

            int field;
            scanf("%d", &field);
            getchar(); // clear buffer

            switch (field)
            {
                case 1:
                    printf("Enter new Name: ");
                    fgets(temp->name, sizeof(temp->name), stdin);
                    temp->name[strcspn(temp->name, "\n")] = '\0';
                    break;
                case 2:
                    printf("Enter new Contact: ");
                    fgets(temp->contact, sizeof(temp->contact), stdin);
                    temp->contact[strcspn(temp->contact, "\n")] = '\0';
                    break;
                case 3:
                    printf("Enter new Room Number: ");
                    scanf("%d", &temp->room_no);
                    break;
                case 4:
                    printf("Admitted? (1-Yes / 0-No): ");
                    scanf("%d", &temp->admitted);
                    break;
                case 5:
                    printf("Enter new Doctor Name: ");
                    fgets(temp->doctor, sizeof(temp->doctor), stdin);
                    temp->doctor[strcspn(temp->doctor, "\n")] = '\0';
                    break;
                case 6:
                    printf("Enter new Disease/Issue: ");
                    fgets(temp->disease, sizeof(temp->disease), stdin);
                    temp->disease[strcspn(temp->disease, "\n")] = '\0';
                    break;
                case 7:
                    printf("Enter new Join/Appointment Date: ");
                    fgets(temp->join_date, sizeof(temp->join_date), stdin);
                    temp->join_date[strcspn(temp->join_date, "\n")] = '\0';
                    break;
                case 8:
                    printf("Enter new Discharge Date: ");
                    fgets(temp->discharge_date, sizeof(temp->discharge_date), stdin);
                    temp->discharge_date[strcspn(temp->discharge_date, "\n")] = '\0';
                    break;
                default:
                    printf("Invalid field choice.\n");
                    return;
            }

            printf("Record updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Patient with Account Number %d not found.\n", acc);
}
