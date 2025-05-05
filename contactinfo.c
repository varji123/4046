#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define MAX_CONTACTS 100
    #define NAME_LEN 50
    #define PHONE_LEN 15
    
    typedef struct 
    {
        char name[NAME_LEN];
        char phone[PHONE_LEN];
    } Contact;

    
    Contact contacts[MAX_CONTACTS];
    int contact_count = 0;
    

    void addContact() 
    {
        if (contact_count >= MAX_CONTACTS) 
        {
    
            printf("Contact list is full.\n");
            return;
    
        }
    
        printf("Enter name: ");
        scanf(" %[^\n]", contacts[contact_count].name);
    
        printf("Enter phone number: ");
        scanf(" %[^\n]", contacts[contact_count].phone);
    
        contact_count++;
        printf("Contact added successfully.\n");
    
    }
    
    void displayContacts() 
    
    {
        if (contact_count == 0) 
        {
            printf("No contacts to display.\n");
            return;
        }
    
        printf("\n--- Contact List ---\n");
        for (int i = 0; i < contact_count; i++) 
        {
            printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
        }
    }
    
    void searchContact() 
    
    {
        char searchName[NAME_LEN];
        printf("Enter name to search: ");
        scanf(" %[^\n]", searchName);
    
        for (int i = 0; i < contact_count; i++) 
        {
            if (strcmp(contacts[i].name, searchName) == 0) 
            {
                printf("Found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
                return;
            }
        }
        printf("Contact not found.\n");
    }
    
    void deleteContact() 
    
    {
        char deleteName[NAME_LEN];
        printf("Enter name to delete: ");
        scanf(" %[^\n]", deleteName);
    
        for (int i = 0; i < contact_count; i++) 
    
        {
            if (strcmp(contacts[i].name, deleteName) == 0) 
    
            {
                for (int j = i; j < contact_count - 1; j++) 
    
                {
                    contacts[j] = contacts[j + 1];
                }
    
                contact_count--;
                printf("Contact deleted successfully.\n");
                return;
            }
    
        }
    
        printf("Contact not found.\n");
    
    }
    
    void showMenu() 
    
    {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
    }
    
    int main() 
    {
        int choice;
    
        while (1) 
    
        {
            showMenu();
            scanf("%d", &choice);
    
            switch (choice) 
            {
                case 1:
                    addContact();
                    break;
                case 2:
                    displayContacts();
                    break;
                case 3:
                    searchContact();
                    break;
                case 4:
                    deleteContact();
                    break;
                case 5:
                    printf("Exiting program.\n");
                    return 0;
                default:
                    printf("Invalid option. Try again.\n");
            }
        }
    
        return 0;
    }
    
