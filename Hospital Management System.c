#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "STD_TYPES.h"
#include "HOSPITAL_FUNCTIONS.h"

typedef struct {
    u32 Room_number;
    u8 Is_empty[10];
    u8 Patient_id;
} Rooms;

Rooms Patient[MAX_ROOMS] = {
    {100, "Full", 1},
    {200, "Full", 2},
    {300, "Empty", 3},
    {400, "Full", 4}
};

typedef struct {
    u8 Username[100];
    u8 Password[50];
} User;


User *Account;

User AdminUser = {
    .Username = "Admin1",
    .Password = "Admin123"
};

User Ramy = {
    .Username = "Ramy",
    .Password = "Ramy123"
};

User Seif = {
    .Username = "Seif",
    .Password = "Seif123"
};

User Daniel = {
    .Username = "Daniel",
    .Password = "Daniel123"
};

User Mohamed = {
    .Username = "Mohamed",
    .Password = "Mohamed123"
};

typedef struct {
    u8 Name[100];
    u8 status[50];
    u32 patient_id;
} Patients;

Patients Data[MAX_ROOMS] = {
    {"Ramy", "Critical condition", 1},
    {"Seif", "Stable", 2},
    {"Daniel", "Critical condition", 3},
    {"Mohamed", "Stable", 4}
   
};
void Creat_New_Account() 
{
    u8 Is_Created = 1;
    Account = malloc((MAX_USERS + 1) * sizeof(User));
    if (Account == NULL) 
    {
        printf("Error: Try Again Later :( \n");
        return;
    }

    printf("Please Enter your Username: ");
    scanf("%s", Account->Username);
    
    printf("Please Enter your Password: ");
    scanf("%s", Account->Password);

    if ((strcmp(Account->Username, AdminUser.Username) == 0) || 
        (strcmp(Account->Username, Ramy.Username) == 0) ||
        (strcmp(Account->Username, Seif.Username) == 0) || 
        (strcmp(Account->Username, Daniel.Username) == 0) ||
        (strcmp(Account->Username, Mohamed.Username) == 0))
    {
        Is_Created = 0;
        printf("The Account Is Already Exist, Please Try Another Name \n");
        for (u8 i = 0; i <= MAX_USERS; i++) 
        {
            if (Is_Created == 0) 
            {
                printf("Please Enter your Username: ");
                scanf("%s", Account->Username);

                printf("Please Enter your Password: ");
                scanf("%s", Account->Password);

                if ((strcmp(Account->Username, AdminUser.Username) != 0) && 
                    (strcmp(Account->Username, Ramy.Username) != 0) &&
                    (strcmp(Account->Username, Seif.Username) != 0) && 
                    (strcmp(Account->Username, Daniel.Username) != 0) &&
                    (strcmp(Account->Username, Mohamed.Username) != 0))
                {
                    printf("Account Created Successfully!\n");
                    Is_Created = 1;
                } 
                else 
                {
                    printf("The Account Is Already Exist, Please Try Another Name\n");
                }
            } 
            else 
            {
                break;
            }
        }
    }

    if (Is_Created == 1) 
    {
        printf("Account Created Successfully!\n");
        Is_Created = 1;
    }

}

void Log_In() 
{
    printf("Please Enter Your UserName: ");
    scanf(" %s", Account->Username);
    printf("Please Enter Your Password: ");
    scanf(" %s", Account->Password);

    u8 Log_InCheck = 0;
    if ((strcmp(Account->Username, AdminUser.Username) == 0) || 
    (strcmp(Account->Username, Ramy.Username) == 0) ||
    (strcmp(Account->Username, Seif.Username) == 0) || 
    (strcmp(Account->Username, Daniel.Username) == 0) ||
    (strcmp(Account->Username, Mohamed.Username) == 0) &&
    ((strcmp(Account->Password, AdminUser.Password) == 0) || 
    (strcmp(Account->Password, Ramy.Password) == 0) ||
    (strcmp(Account->Password, Seif.Password) == 0) || 
    (strcmp(Account->Password, Daniel.Password) == 0) ||
    (strcmp(Account->Password, Mohamed.Password) == 0)))

    {
        printf("User Login Successful \n");
        Log_InCheck = 1;
    }
   if (Log_InCheck == 0)
    {
     printf("Invalid input. Exiting program.\n");
     exit ;
    }
}

void Remove_Current_Reservation() 
{
    u8 patientName[100];
    u8 ReservationFound = 0;
    printf("Enter the name of the patient to remove reservation: \n");
    scanf("%s", patientName);
    for (u8 i = 0; i < MAX_ROOMS; i++) 
    {
        if (strcmp(patientName, Data[i].Name) == 0) 
        {
            printf("Reservation for %s removed successfully.\n", patientName);

            strcpy(Data[i].status, "Cancelled");
            ReservationFound = 1;
            break;
        }
    }
    if (ReservationFound == 0) 
    {
        printf("No reservation found for patient: %s \n", patientName);
    }
}

void Check_Empty_Rooms() 
{
    u8 emptyRoomsFound = 0;
    for (u8 i = 0; i < MAX_ROOMS; i++) 
    {
        if (strcmp(Patient[i].Is_empty, "Empty") == 0) 
        {
            printf("Room Number : %d\n", Patient[i].Room_number);
            emptyRoomsFound = 1;
        }
    }
    if (emptyRoomsFound == 0) 
    {
        printf("No empty rooms.\n");
    }
}

void Patient_Data() 
{
    u8 patientName[100];
    u8 PatientFound = 0;
    printf("Enter the name of the patient to view data: \n");
    scanf("%s", patientName);
    
    for (u8 i = 0; i < MAX_ROOMS; i++) 
    {
        if (strcmp(patientName, Data[i].Name) == 0) 
        {
            printf("The Patient Status: %s & Patient ID %d \n", Data[i].status, Data[i].patient_id);
            PatientFound = 1;
            break;
        }
    }
    if (PatientFound == 0) 
    {
        printf("No patient data found for user: %s\n", patientName);
    }
}

void ExitSystem()
{
    printf("Thank you for using MIU Hospital system \n");
}

int main() 
{
    u8 Continue = 'y';
    while ((Continue == 'Y')||(Continue == 'y')) 
    {
        Account = malloc(MAX_USERS * sizeof(User));
        u8 choice;
        u8 choice1;
        printf("Welcome to MIU Hospital System\n");
        printf("\n 1. Create New Account");
        printf("\n 2. Login");
        printf("\n 3. Exit\n");
        printf("\n Enter your choice: \n");
        scanf(" %hhd", &choice);

        switch (choice) 
        {
            case (1):
                Creat_New_Account();
                printf("\n Enter your choice: \n");
                printf("\n 1.Remove Current Reservation");
                printf("\n 2.Check Empty Rooms");
                printf("\n 3.Update Patient's data\n");
                scanf("%c", &choice1);
                switch (choice1) 
                {
                    case (1):
                    {
                        Remove_Current_Reservation();
                        break;
                    }
                    case (2):
                    {
                        Check_Empty_Rooms();
                        break;
                    }
                    case (3):
                    {
                        Patient_Data();
                        break;
                    }
                    default:
                    {
                        printf("Invalid input Please try again.\n");
                        break;
                    }
                }
                break;
            case (2):
                u8 log_in_flag = 1;
                Log_In();
                if (log_in_flag == 1) 
                {
                    printf("\n 1.Remove Current Reservation");
                    printf("\n 2.Check Empty Rooms");
                    printf("\n 3.Update Patient's data \n");
                    scanf("%hhd", &choice1);
                    switch (choice1) 
                    {
                        case (1):
                        {
                            Remove_Current_Reservation();
                            break;
                        }
                        case (2):
                        {
                            Check_Empty_Rooms();
                            break;
                        }
                        case (3):
                        {
                            Patient_Data();
                            break;
                        }
                        default:
                        {
                            printf("Invalid input Please try again.\n");
                            break;
                        }
                    }
                    
                } 
                else 
                {
                    log_in_flag = 0;
                    printf("Failed to login please try again \n");
                }
                break;
            case (3):
            {
                ExitSystem();
                Continue = 1;
                break;
            }
            default:
            {
                printf("Invalid input. Please try again.\n");
                break;
            }
        }
        free(Account);
        printf("Please Enter (Y) To Continue Or Any Other Letter To EXIT \n");
        scanf(" %c", &Continue);
    }
}
