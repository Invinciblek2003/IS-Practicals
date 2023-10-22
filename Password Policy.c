/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_ROLES 10

typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    int role;
} User;

typedef struct {
    int minLength;
    int maxLength;
} PasswordPolicy;

typedef struct {
    int role;
    char privileges[100];
} Role;

User users[MAX_USERS];
int userCount = 0;

PasswordPolicy passwordPolicy;

Role roles[MAX_ROLES];
int roleCount = 0;

void createUser(char *username, char *password, int role) {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        return;
    }

    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Password length exceeds the limit!\n");
        return;
    }

    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    newUser.role = role;

    users[userCount++] = newUser;

    printf("User created successfully!\n");
}

void deleteUser(char *username) {
    bool userFound = false;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            userFound = true;
            break;
        }
    }

    if (userFound) {
        printf("User deleted successfully!\n");
    } else {
        printf("User not found!\n");
    }
}

void changePassword(char *username, char *oldPassword, char *newPassword) {
    bool userFound = false;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, oldPassword) == 0) {
                strcpy(users[i].password, newPassword);
                userFound = true;
                break;
            } else {
                printf("Incorrect old password!\n");
                return;
            }
        }
    }

    if (userFound) {
        printf("Password changed successfully!\n");
    } else {
        printf("User not found!\n");
    }
}

void createPasswordPolicy(int minLength, int maxLength) {
    passwordPolicy.minLength = minLength;
    passwordPolicy.maxLength = maxLength;

    printf("Password policy created successfully!\n");
}

void assignRoleToUser(char *username, int role) {
    bool userFound = false;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].role = role;
            userFound = true;
            break;
        }
    }

    if (userFound) {
        printf("Role assigned successfully!\n");
    } else {
        printf("User not found!\n");
    }
}

void assignPrivilegesToRole(int role, char *privileges) {
    if (role >= roleCount) {
        printf("Role does not exist!\n");
        return;
    }

    Role *selectedRole = &roles[role];
    strcpy(selectedRole->privileges, privileges);

    printf("Privileges assigned to the role successfully!\n");
}

void checkPasswordPolicy(char *username, char *password) {
    bool userFound = false;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strlen(password) >= passwordPolicy.minLength && strlen(password) <= passwordPolicy.maxLength) {
                printf("Password meets the policy requirements!\n");
            } else {
                printf("Password does not meet the policy requirements!\n");
            }
            userFound = true;
            break;
        }
    }

    if (!userFound) {
        printf("User not found!\n");
    }
}

int main() {
    int choice;
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    int role;

    while (1) {
        printf("\n--- User Administration Menu ---\n");
        printf("1. Create User\n");
        printf("2. Delete User\n");
        printf("3. Change Password\n");
        printf("4. Create Password Policy\n");
        printf("5. Assign Role to User\n");
        printf("6. Assign Privileges to Role\n");
        printf("7. Check Password Policy\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                printf("Enter role (0-%d): ", roleCount - 1);
                scanf("%d", &role);
                createUser(username, password, role);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                deleteUser(username);
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter old password: ");
                scanf("%s", password);
                printf("Enter new password: ");
                scanf("%s", password);
                changePassword(username, password, password);
                break;
            case 4:
                printf("Enter minimum password length: ");
                scanf("%d", &passwordPolicy.minLength);
                printf("Enter maximum password length: ");
                scanf("%d", &passwordPolicy.maxLength);
                createPasswordPolicy(passwordPolicy.minLength, passwordPolicy.maxLength);
                break;
            case 5:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter role (0-%d): ", roleCount - 1);
                scanf("%d", &role);
                assignRoleToUser(username, role);
                break;
            case 6:
                printf("Enter role (0-%d): ", roleCount - 1);
                scanf("%d", &role);
                printf("Enter privileges: ");
                scanf("%s", roles[role].privileges);
                assignPrivilegesToRole(role, roles[role].privileges);
                break;
            case 7:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                checkPasswordPolicy(username, password);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}