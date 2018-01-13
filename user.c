#include "user.h"

user * createUser(char lastname[], char firstname[], unsigned int salary) {
    user * newUser = (user*) malloc(sizeof(user));
    if (newUser != NULL) {
        strcpy(newUser->lastname, lastname);
        strcpy(newUser->firstname, firstname);
        newUser->salary = salary;
    }
    return newUser;
}

void displayUser(user * userToDisplay) {
    printf("%s %s, $%d\n", userToDisplay->lastname, userToDisplay->firstname, userToDisplay->salary);
}

int compareUsersNames(user * user1, user * user2) {
    if (strcmp(user1->lastname, user2->lastname) == 0 && strcmp(user1->firstname, user2->firstname) == 0) {
        return 0;
    }
    else {
        return 1;
    }
}