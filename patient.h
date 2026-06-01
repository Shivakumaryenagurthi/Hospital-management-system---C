#ifndef PATIENT_H
#define PATIENT_H

#define SAVE_FILE "hospital_data.txt"

typedef struct patient
{
    int  acc_no;
    char name[50];
    char contact[15];
    int  room_no;
    int  admitted;        // 1 = Yes, 0 = No

    char doctor[50];
    char disease[50];

    char join_date[15];
    char discharge_date[15];

    struct patient *next;

} Patient;

// Global head pointer (defined once in main.c)
extern Patient *head;

// ── Core ────────────────────────────────────────────
int  check_duplicate(int acc_no);
void book_appointment();       // A/a

// ── Print ───────────────────────────────────────────
void print_menu();             // P/p  (sub-menu)
void print_all();
void print_by_acc();
void print_by_doctor();
void print_by_disease();

// ── Save ────────────────────────────────────────────
void save_to_file();           // S/s

// ── Find / Search ───────────────────────────────────
void find_patient();           // F/f

// ── Modify ──────────────────────────────────────────
void modify_patient();         // M/m

// ── Delete ──────────────────────────────────────────
void delete_patient();         // X/x

#endif
