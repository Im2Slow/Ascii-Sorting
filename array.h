#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"

typedef struct _array {
    long long unsigned N;//size
    int base;
    vector * content;
} array;

long long unsigned power(long long unsigned n, unsigned int p);
long long unsigned indexCalculator(char lastname[], char firstname[], int base, long long unsigned N);
void readFile(char fileName[], array * workingArray, int numberOfUsersToAdd);
array * createArray(int base, long long unsigned N);
void displayArray(array * arrayToDisplay);
void sortArray(array * arrayToSort);
void addSingleUserToArray(user * userToAdd, array * workingArray);
user * searchUserInArray(user * userToSearch, array * workingArray);
#endif
