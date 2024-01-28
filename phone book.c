
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phoneNumber[20];
    char email[50];
};

struct Phonebook {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void addContact(struct Phonebook *phonebook, const char *name, const char *phoneNumber, const char *email) {
    if (phonebook->count < MAX_CONTACTS) {
        strcpy(phonebook->contacts[phonebook->count].name, name);
        strcpy(phonebook->contacts[phonebook->count].phoneNumber, phoneNumber);
        strcpy(phonebook->contacts[phonebook->count].email, email);
        printf("Contact added successfully.\n");
        phonebook->count++;
    } else {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void searchContact(const struct Phonebook *phonebook, const char *name) {
    for (int i = 0; i < phonebook->count; i++) {
        if (strcmp(phonebook->contacts[i].name, name) == 0) {
            printf("Contact details for %s - Phone Number: %s, Email: %s\n",
                   phonebook->contacts[i].name, phonebook->contacts[i].phoneNumber, phonebook->contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void dialCall(const struct Phonebook *phonebook, const char *name) {
    for (int i = 0; i < phonebook->count; i++) {
        if (strcmp(phonebook->contacts[i].name, name) == 0) {
            printf("Dialing %s at number %s...\n", phonebook->contacts[i].name, phonebook->contacts[i].phoneNumber);
            // Additional code for making a call can be added here.
            return;
        }
    }
    printf("Contact not found.\n");
}

void changeContact(struct Phonebook *phonebook, const char *name, const char *newPhoneNumber, const char *newEmail) {
    for (int i = 0; i < phonebook->count; i++) {
        if (strcmp(phonebook->contacts[i].name, name) == 0) {
            strcpy(phonebook->contacts[i].phoneNumber, newPhoneNumber);
            strcpy(phonebook->contacts[i].email, newEmail);
            printf("Contact details updated successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(struct Phonebook *phonebook, const char *name) {
    for (int i = 0; i < phonebook->count; i++) {
        if (strcmp(phonebook->contacts[i].name, name) == 0) {
            // Shift remaining contacts to fill the gap
            for (int j = i; j < phonebook->count - 1; j++) {
                strcpy(phonebook->contacts[j].name, phonebook->contacts[j + 1].name);
                strcpy(phonebook->contacts[j].phoneNumber, phonebook->contacts[j + 1].phoneNumber);
                strcpy(phonebook->contacts[j].email, phonebook->contacts[j + 1].email);
            }
            phonebook->count--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    struct Phonebook phonebook;
    phonebook.count = 0;

    int choice;
    char name[50], phoneNumber[20], email[50];

    do {
        printf("Phonebook Menu:\n");
        printf("1. Add Number\n2. Search Number\n3. Dial Call\n4. Change Name or Number\n5. Delete Account\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%s", phoneNumber);
                printf("Enter Email: ");
                scanf("%s", email);
                addContact(&phonebook, name, phoneNumber, email);
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                searchContact(&phonebook, name);
                break;
            case 3:
                printf("Enter Name to Dial Call: ");
                scanf("%s", name);
                dialCall(&phonebook, name);
                break;
            case 4:
                printf("Enter Name to Change: ");
                scanf("%s", name);
                printf("Enter New Phone Number: ");
                scanf("%s", phoneNumber);
                printf("Enter New Email: ");
                scanf("%s", email);
                changeContact(&phonebook, name, phoneNumber, email);
                break;
            case 5:
                printf("Enter Name to Delete: ");
                scanf("%s", name);
                deleteContact(&phonebook, name);
                break;
            case 6:
                printf("Exiting the Phonebook.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

