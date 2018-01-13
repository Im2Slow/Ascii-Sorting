#include "vector.h"

vector * createVector() {
    vector * newVector = (vector*) malloc(sizeof(vector));
    if (newVector != NULL) {
        newVector->currentNumberOfUsers = 0;
        newVector->capacity = 0;
        newVector->content = (user*) malloc(sizeof(user) * newVector->capacity);
    }
    return newVector;
}

void  addUserInVector(user * userToAdd, vector * vectorWhereToAdd) {
    //Growing content if needed
    if (vectorWhereToAdd->currentNumberOfUsers >= vectorWhereToAdd->capacity) {
        user * newContent = (user*) malloc(sizeof(user) * (vectorWhereToAdd->capacity + 1));
        for (long long unsigned int i = 0; i < vectorWhereToAdd->capacity; i++) {
            *(newContent + i) = *(vectorWhereToAdd->content + i);
        }
        free(vectorWhereToAdd->content);
        vectorWhereToAdd->content = newContent;
        vectorWhereToAdd->capacity++;
    }
    *(vectorWhereToAdd->content + vectorWhereToAdd->currentNumberOfUsers) = *userToAdd;
    vectorWhereToAdd->currentNumberOfUsers++;
    //Finding out where the user should be, in order for the vector to stay alphabetically sorted
    /*
    int indexWhereToAddUser = 0;
    for (int i = 0; i < vectorWhereToAdd->currentNumberOfUsers; i++) {
        //printf("%d : strcmp(%s, %s) = %d\n", i, userToAdd->lastname, (vectorWhereToAdd->content + i), strcmp(userToAdd->lastname, (vectorWhereToAdd->content + i)->lastname));
        if (strcmp(userToAdd->lastname, (vectorWhereToAdd->content + i)->lastname) < 0) {
            indexWhereToAddUser = i;
            //printf("\t%d\n", i);
            break;
        }
    }
    */
    //printf("%d\n", indexWhereToAddUser);
    //Putting the user in the right placez
    /*
    for (int i = vectorWhereToAdd->currentNumberOfUsers - 1; i > indexWhereToAddUser; i--) {
        //printf("before\n");
        //displayVector(vectorWhereToAdd);
        user * temp = createUser((vectorWhereToAdd->content + i)->lastname, (vectorWhereToAdd->content + i)->firstname, (vectorWhereToAdd->content + i)->salary);
        //displayUser(temp);
        *(vectorWhereToAdd->content + i) = *(vectorWhereToAdd->content + i - 1);
        //displayUser(temp);
        *(vectorWhereToAdd->content + i - 1) = *temp;
        //displayUser(temp);
        //printf("after\n");
        //displayVector(vectorWhereToAdd);
        free(temp);
    }
    */
}

void displayVector(vector * vectorToDisplay) {
    for (long long unsigned int i = 0; i < vectorToDisplay->currentNumberOfUsers; i++) {
        printf("\t\t");
        displayUser(vectorToDisplay->content + i);
    }
}

void sortVectorAlphabetically(vector * vectorToSort) {
    int n1 = vectorToSort->currentNumberOfUsers, n2 = 0;
    do {
        n2 = 0;
        for (long long unsigned int i = 1; i < n1; i++) {
            if (strcmp((vectorToSort->content + i - 1)->lastname, (vectorToSort->content + i)->lastname) > 0 || (strcmp((vectorToSort->content + i - 1)->lastname, (vectorToSort->content + i)->lastname) == 0 && strcmp((vectorToSort->content + i - 1)->firstname, (vectorToSort->content + i)->firstname) > 0)) {
                user * temp = createUser((vectorToSort->content + i)->lastname, (vectorToSort->content + i)->firstname, (vectorToSort->content + i)->salary);
                *(vectorToSort->content + i) = *(vectorToSort->content + i - 1);
                *(vectorToSort->content + i - 1) = *temp;
                free(temp);
                n2 = i;
            }
        }
        n1 = n2;
    } while(n1 > 0);
}

user * searchUserInVector(user * userToSearch, vector * vectorWhereToSearch) {
    for (long long unsigned int i = 0; i < vectorWhereToSearch->currentNumberOfUsers; i++) {
        if (compareUsersNames(userToSearch, vectorWhereToSearch->content + i) == 0) {
            return (vectorWhereToSearch->content + i);
        }
    }
    return NULL;
}

void removeUserFromVector(user * userToRemove, vector * vectorToRemoveFrom) {
    long long unsigned int index = 0;
    for (long long unsigned int i = 0; i < vectorToRemoveFrom->currentNumberOfUsers; i++) {
        if (compareUsersNames(userToRemove, vectorToRemoveFrom->content + i) == 0) {
            index = i;
            break;
        }
    }
    free(vectorToRemoveFrom->content + index);
    *(vectorToRemoveFrom->content + index) = *(vectorToRemoveFrom->content + vectorToRemoveFrom->currentNumberOfUsers - 1);
    //*(vectorToRemoveFrom->content + vectorToRemoveFrom->currentNumberOfUsers - 1) = NULL;
    vectorToRemoveFrom->currentNumberOfUsers--;
    sortVectorAlphabetically(vectorToRemoveFrom);
}

void removeVector(vector * vectorToRemove) {

    for (long long unsigned int i = 0; i < vectorToRemove->currentNumberOfUsers; i++) {
        displayUser(vectorToRemove->content + i);
        removeUserFromVector(vectorToRemove->content + i, vectorToRemove);
    }
    free(vectorToRemove);
}