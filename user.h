#ifndef USER_H
#define USER_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct _user {
    char lastname[56];
    char firstname[56];
    unsigned int salary;
}user;

user * createUser(char lastname[], char firstname[], unsigned int salary);
void displayUser(user * userToDisplay);
int compareUsers(user * user1, user * user2);
#endif
