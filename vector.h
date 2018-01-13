#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "user.h"

typedef struct _vector {
    long long unsigned int currentNumberOfUsers;
    long long unsigned int capacity;
    user * content;
}vector;

vector * createVector();
void addUserInVector(user * userToAdd, vector * vectorWhereToAdd);
void displayVector(vector * vectorToDisplay);
void sortVectorAlphabetically(vector * vectorToSort);
user * searchUserInVector(user * userToSearch, vector * vectorWhereToSearch);
void removeUserFromVector(user * userToRemove, vector * vectorToRemoveFrom);
void removeVector(vector * vectorToRemove);
#endif
