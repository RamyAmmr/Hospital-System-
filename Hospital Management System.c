/*
    * Author: Ramy Amr & Seif Saleh
    * Version: 1.1
    * Description: Hospital Management System 
*/

#include <stdio.h>  // Standard Input/Output library
#include <stdlib.h> // Standard library providing memory allocation, process control functions
#include <string.h> // String manipulation functions
#include <time.h>   // Time functions
#include "STD_TYPES.h"          // User-defined standard types header file
#include "HOSPITAL_FUNCTIONS.h"// User-defined hospital functions header file

// Structure definition for hospital rooms
typedef struct {
    u32 Room_number;    // Room number
    u8 Is_empty[10];    // Indicates whether the room is empty or not
    u8 Patient_id;      // ID of the patient occupying the room
} Rooms;

// Array of Rooms representing the hospital rooms
Rooms Patient[MAX_ROOMS] = {
    {100, "Full", 1},
    {200, "Full", 2},
    {300, "Empty", 3},
    {400, "Full", 4}
};

// Structure definition for user accounts
typedef struct {
    u8 Username[100];   // Username
    u8 Password[50];    // Password
} User;

User *Account;  // Pointer to User structure representing the current account

// Definition of admin and user accounts
User AdminUser = {
    .Username = "Admin1",   // Username of the admin account
    .Password = "Admin123"  // Password of the admin account
};

User Ramy = {
    .Username = "Ramy",     // Username of the user account "Ramy"
    .Password = "Ramy123"   // Password of the user account "Ramy"
};

User Seif = {
    .Username = "Seif",     // Username of the user account "Seif"
    .Password = "Seif123"   // Password of the user account "Seif"
};

User Daniel = {
    .Username = "Daniel",   // Username of the user account "Daniel"
    .Password = "Daniel123" // Password of the user account "Daniel"
};

User Mohamed = {
    .Username = "Mohamed",  // Username of the user account "Mohamed"
    .Password = "Mohamed123"// Password of the user account "Mohamed"
};

// Definition of structure representing patient data
typedef struct {
    u8 Name[100];       // Name of the patient
    u8 status[50];      // Status of the patient
    u32 patient_id;     // ID of the patient
} Patients;

// Array of Patients representing patient data
Patients Data[MAX_ROOMS] = {
    {"Ramy", "Critical condition", 1},   // Patient "Ramy" with critical condition and ID 1
    {"Seif", "Stable", 2},                // Patient "Seif" with stable condition and ID 2
    {"Daniel", "Critical condition", 3},  // Patient "Daniel" with critical condition and ID 3
    {"Mohamed", "Stable", 4}              // Patient "Mohamed" with stable condition and ID 4
};

// Function to create a new user account
void Creat_New_Account() 
{
    u8 Is_Created = 1;  // Flag to track if the account is created successfully
    Account = malloc((MAX_USERS + 1) * sizeof(User));  // Allocate memory for the Account pointer
    
    if (Account == NULL) // Check if memory allocation failed
    {
        printf("Error: Try Again Later :( \n");  // Print error message
        return;  // Exit function
    }

    printf("Please Enter your Username: ");  // Prompt the user to enter a username
    scanf("%s", Account->Username);  // Read username from user input
    
    printf("Please Enter your Password: ");  // Prompt the user to enter a password
    scanf("%s", Account->Password);  // Read password from user input

    // Check if the entered username already exists in the system
    if ((strcmp(Account->Username, AdminUser.Username) == 0) || 
        (strcmp(Account->Username, Ramy.Username) == 0) ||
        (strcmp(Account->Username, Seif.Username) == 0) || 
        (strcmp(Account->Username, Daniel.Username) == 0) ||
        (strcmp(Account->Username, Mohamed.Username) == 0))
    {
        Is_Created = 0;  // Set flag to indicate the account is not created
        printf("The Account Is Already Exist, Please Try Another Name \n");  // Print message indicating username already exists
        
        // Loop to prompt the user to enter a different username until a unique one is provided
        for (u8 i = 0; i <= MAX_USERS; i++) 
        {
            if (Is_Created == 0) 
            {
                printf("Please Enter your Username: ");  // Prompt the user to enter a username
                scanf("%s", Account->Username);  // Read username from user input

                printf("Please Enter your Password: ");  // Prompt the user to enter a password
                scanf("%s", Account->Password);  // Read password from user input

                // Check if the entered username is unique
                if ((strcmp(Account->Username, AdminUser.Username) != 0) && 
                    (strcmp(Account->Username, Ramy.Username) != 0) &&
                    (strcmp(Account->Username, Seif.Username) != 0) && 
                    (strcmp(Account->Username, Daniel.Username) != 0) &&
                    (strcmp(Account->Username, Mohamed.Username) != 0))
                {
                    printf("Account Created Successfully!\n");  // Print message indicating account creation success
                    Is_Created = 1;  // Set flag to indicate the account is created
                } 
                else 
                {
                    printf("The Account Is Already Exist, Please Try Another Name\n");  // Print message indicating username already exists
                }
            } 
            else 
            {
                break;  // Exit loop if the account is created
            }
        }
    }

    // Check if the account is created successfully
    if (Is_Created == 1) 
    {
        printf("Account Created Successfully!\n");  // Print message indicating account creation success
        Is_Created = 1;  // Set flag to indicate the account is created
    }

}

// Function to log in a user
void Log_In() 
{
    printf("Please Enter Your UserName: ");  // Prompt the user to enter a username
    scanf(" %s", Account->Username);  // Read username from user input
    
    printf("Please Enter Your Password: ");  // Prompt the user to enter a password
    scanf(" %s", Account->Password);  // Read password from user input

    u8 Log_InCheck = 0;  // Flag to check if login is successful
    // Check if the entered username and password match any of the existing accounts
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
        printf("User Login Successful \n");  // Print message indicating successful login
        Log_InCheck = 1;  // Set flag to indicate successful login
    }
    // Check if login is unsuccessful
    if (Log_InCheck == 0)
    {
     printf("Invalid input. Exiting program.\n");  // Print message indicating invalid input
     exit ;  // Exit program
    }
}

// Function to remove current reservation for a patient
void Remove_Current_Reservation() 
{
    u8 patientName[100];  // Array to store patient name
    u8 ReservationFound = 0;  // Flag to indicate if the reservation is found
    printf("Enter the name of the patient to remove reservation: \n");  // Prompt the user to enter patient name
    scanf("%s", patientName);  // Read patient name from user input
    // Loop through patient data to find the matching patient
    for (u8 i = 0; i < MAX_ROOMS; i++) 
    {
        // Check if the entered patient name matches any of the patients in the system
        if (strcmp(patientName, Data[i].Name) == 0) 
        {
            printf("Reservation for %s removed successfully.\n", patientName);  // Print message indicating successful reservation removal

            strcpy(Data[i].status, "Cancelled");  // Update patient status to "Cancelled"
            ReservationFound = 1;  // Set flag to indicate reservation is found
            break;  // Exit loop
        }
    }
    // Check if reservation is not found
    if (ReservationFound == 0) 
    {
        printf("No reservation found for patient: %s \n", patientName);  // Print message indicating no reservation found
    }
}

// Function to check empty rooms in the hospital
void Check_Empty_Rooms() 
{
    u8 emptyRoomsFound = 0;  // Flag to indicate if empty rooms are found
    // Loop through hospital rooms to check for empty rooms
    for (u8 i = 0; i < MAX_ROOMS; i++) 
    {
        // Check if the room is empty
        if (strcmp(Patient[i].Is_empty, "Empty") == 0) 
        {
            printf("Room Number : %d\n", Patient[i].Room_number);  // Print room number of empty room
            emptyRoomsFound = 1;  // Set flag to indicate the empty room is found
        }
    }
    // Check if no empty rooms are found
    if (emptyRoomsFound == 0) 
    {
        printf("No empty rooms.\n");  // Print message indicating no empty rooms found
    }
}

// Function to display patient data
void Patient_Data() 
{
    u8 patientName[100];  // Array to store patient name
    u8 PatientFound = 0;  // Flag to indicate if the patient is found
    printf("Enter the name of the patient to view data: \n");  // Prompt the user to enter patient name
    scanf("%s", patientName);  // Read patient name from user input
    
    // Loop through patient data to find the matching patient
    for (u8 i = 0; i < MAX_ROOMS; i++) 
    {
        // Check if the entered patient name matches any of the patients in the system
        if (strcmp(patientName, Data[i].Name) == 0) 
        {
            printf("The Patient Status: %s & Patient ID %d \n", Data[i].status, Data[i].patient_id);  // Print patient status and ID
            PatientFound = 1;  // Set flag to indicate patient is found
            break;  // Exit loop
        }
    }
    // Check if patient is not found
    if (PatientFound == 0) 
    {
        printf("No patient data found for user: %s\n", patientName);  // Print message indicating no patient data found
    }
}

// Function to exit the system
void ExitSystem()
{
    printf("Thank you for using MIU Hospital system \n");  // Print message thanking user for using the system
}

// Main function
int main() 
{
    u8 Continue = 'y';  // Variable to control program continuation
    // Loop to keep the program running until the user chooses to exit
    while ((Continue == 'Y')||(Continue == 'y')) 
    {
        Account = malloc(MAX_USERS * sizeof(User));  // Allocate memory for the Account pointer
        u8 choice;  // Variable to store user choice
        u8 choice1;  // Variable to store user sub-choice
        printf("Welcome to MIU Hospital System\n");  // Print welcome message
        printf("\n 1. Create New Account");  // Display option to create a new account
        printf("\n 2. Login");  // Display option to log in
        printf("\n 3. Exit\n");  // Display option to exit
        printf("\n Enter your choice: \n");  // Prompt the user to enter choice
        scanf(" %hhd", &choice);  // Read choice from user input

        switch (choice)  // Switch statement based on user choice
        {
            case (1):  // Case for creating a new account
                Creat_New_Account();  // Call function to create a new account
                printf("\n Enter your choice: \n");  // Prompt the user to enter sub-choice
                printf("\n 1.Remove Current Reservation");  // Display option to remove current reservation
                printf("\n 2.Check Empty Rooms");  // Display option to check empty rooms
                printf("\n 3.Update Patient's data\n");  // Display option to update patient's data
                scanf("%hhd", &choice1);  // Read sub-choice from user input
                switch (choice1)  // Switch statement based on sub-choice
                {
                    case (1):  // Case for removing current reservation
                    {
                        Remove_Current_Reservation();  // Call function to remove current reservation
                        break;  // Exit switch statement
                    }
                    case (2):  // Case for checking empty rooms
                    {
                        Check_Empty_Rooms();  // Call function to check empty rooms
                        break;  // Exit switch statement
                    }
                    case (3):  // Case for updating patient's data
                    {
                        Patient_Data();  // Call function to update patient's data
                        break;  // Exit switch statement
                    }
                    default:  // Default case for invalid input
                    {
                        printf("Invalid input Please try again.\n");  // Print message indicating invalid input
                        break;  // Exit switch statement
                    }
                }
                break;  // Exit switch statement

            case (2):  // Case for logging in
                u8 log_in_flag = 1;  // Flag to indicate login status
                Log_In();  // Call function to log in
                if (log_in_flag == 1)  // Check if login is successful
                {
                    printf("\n 1.Remove Current Reservation");  // Display option to remove current reservation
                    printf("\n 2.Check Empty Rooms");  // Display option to check empty rooms
                    printf("\n 3.Update Patient's data \n");  // Display option to update patient's data
                    scanf("%hhd", &choice1);  // Read sub-choice from user input
                    switch (choice1)  // Switch statement based on sub-choice
                    {
                        case (1):  // Case for removing current reservation
                        {
                            Remove_Current_Reservation();  // Call function to remove current reservation
                            break;  // Exit switch statement
                        }
                        case (2):  // Case for checking empty rooms
                        {
                            Check_Empty_Rooms();  // Call function to check empty rooms
                            break;  // Exit switch statement
                        }
                        case (3):  // Case for updating patient's data
                        {
                            Patient_Data();  // Call function to update patient's data
                            break;  // Exit switch statement
                        }
                        default:  // Default case for invalid input
                        {
                            printf("Invalid input Please try again.\n");  // Print message indicating invalid input
                            break;  // Exit switch statement
                        }
                    }
                } 
                else  // Case for unsuccessful login
                {
                    log_in_flag = 0;  // Set flag to indicate unsuccessful login
                    printf("Failed to login please try again \n");  // Print message indicating failed login
                }
                break;  // Exit switch statement

            case (3):  // Case for exiting the system
            {
                ExitSystem();  // Call function to exit the system
                Continue = 1;  // Set variable to exit program loop
                break;  // Exit switch statement
            }
            default:  // Default case for invalid input
            {
                printf("Invalid input. Please try again.\n");  // Print message indicating invalid input
                break;  // Exit switch statement
            }
        }
        free(Account);  // Free memory allocated for Account pointer
        printf("Please Enter (Y) To Continue Or Any Other Letter To EXIT \n");  // Prompt the user to continue or exit
        scanf(" %c", &Continue);  // Read continuation choice from user input
    }
}
