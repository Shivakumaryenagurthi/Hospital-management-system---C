#include <stdio.h>
#include "patient.h"

void save_to_file()
{
    if (head == NULL)
    {
        printf("No patient data to save.\n");
        return;
    }

    FILE *fp = fopen(SAVE_FILE, "w");
    if (fp == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    Patient *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        fprintf(fp, "ACC_NO:%d\n",          temp->acc_no);
        fprintf(fp, "NAME:%s\n",            temp->name);
        fprintf(fp, "CONTACT:%s\n",         temp->contact);
        fprintf(fp, "ROOM_NO:%d\n",         temp->room_no);
        fprintf(fp, "ADMITTED:%d\n",        temp->admitted);
        fprintf(fp, "DOCTOR:%s\n",          temp->doctor);
        fprintf(fp, "DISEASE:%s\n",         temp->disease);
        fprintf(fp, "JOIN_DATE:%s\n",       temp->join_date);
        fprintf(fp, "DISCHARGE_DATE:%s\n",  temp->discharge_date);
        fprintf(fp, "---\n"); // record separator

        count++;
        temp = temp->next;
    }

    fclose(fp);
    printf("Data saved successfully to '%s'. (%d records)\n", SAVE_FILE, count);
}
