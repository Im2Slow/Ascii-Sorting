#include "array.h"


long long unsigned power(long long unsigned n, unsigned int p) {
    long long unsigned toReturn = 1;
    for (int i = 0; i < p; i++) {
        toReturn *= n;
    }
    return toReturn;
}

long long unsigned indexCalculator(char lastname[], char firstname[], int base, long long unsigned N) {
    long long unsigned toReturn = 0;
    char str[] = "      ";
    int i = 0;
    while (i < 4 && lastname[i] != '\0') {
        str[i] = lastname[i];
        i++;
    }
    i = 4;
    while (i < 6 && firstname[i - 4] != '\0') {
        str[i] = firstname[i - 4];
        i++;
    }
    for (int i = 0; i < 6; i++) {
        toReturn += (unsigned int) str[i] * power(base, i);
    }
    return toReturn % N;
}

void readFile(char fileName[], array * workingArray, int numberOfUsersToAdd) {
    FILE *fp;
    fp = fopen(fileName, "r");
    char lastname[16], firstname[16];
    int salary;
    int maximumUsersAddable;
    fscanf(fp, "%d\n", &maximumUsersAddable);
    if (numberOfUsersToAdd > maximumUsersAddable) {
        numberOfUsersToAdd = maximumUsersAddable;
        }
    for (int i = 0; i < numberOfUsersToAdd; i++) {
        fscanf(fp, "%s %s %d\n", lastname, firstname, &salary); // &lastname donne l'élément et pas l'adresse ( char (*)[])
        user * newUser = createUser(lastname, firstname, salary);
        //&array ne donne pas d'erreur, peut etre essayer de d'abord creer un pointeur pour faire plaisir a addUserInVector
        //printf("readFile : %d/%d\n", i + 1, numberOfUsersToAdd);
        addUserInVector(newUser, workingArray->content + indexCalculator(lastname, firstname, workingArray->base, workingArray->N));
    }
    sortArray(workingArray);
}

array * createArray(int base, long long unsigned N) {
    array * newArray = (array*) malloc(sizeof(array));
    newArray->base = base;
    newArray->N = N;
    newArray->content = (vector*) malloc(N * sizeof(vector));
    for (int i = 0; i < N; i++) {
        *(newArray->content) = *createVector();
    }
    return newArray;
}

void displayArray(array * arrayToDisplay) {
    printf("array :\n");
    for (long long unsigned int i = 0; i < arrayToDisplay->N; i++) {
        printf("\tvector %llu:\n", i);
        displayVector(arrayToDisplay->content + i);
    }
}

void sortArray(array * arrayToSort) {
    for (long long unsigned int i = 0; i < arrayToSort->N; i++) {
        sortVectorAlphabetically(arrayToSort->content + i);
    }
}

void addSingleUserToArray(user * userToAdd, array * workingArray) {
    int index = indexCalculator(userToAdd->lastname, userToAdd->firstname, workingArray->base, workingArray->N);
    addUserInVector(userToAdd, workingArray->content + index);
}

user * searchUserInArray(user * userToSearch, array * workingArray) {
    int index = indexCalculator(userToSearch->lastname, userToSearch->firstname, workingArray->base, workingArray->N);
    return searchUserInVector(userToSearch, workingArray->content + index);
}
