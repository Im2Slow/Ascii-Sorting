#include "main.h"

int main(int argc, char **argv) {
    /*
    long long unsigned int N = 10;
    array * workingArray = createArray(12, N);
    readFile("chicago.txt", workingArray, N*10);
    displayArray(workingArray);
    */
    menu(initialization());
    return 0;
}

array * initialization() {
    printf("\tINITIALIZATION\n");
    printf("Please enter a size for the table : ");
    long long unsigned N = 0;
    scanf(" %llu%*c", &N);
    printf("Please enter a base for the table : ");
    int base = 0;
    scanf(" %d%*c", &base);
    array * newArray = createArray(base, N);
    return newArray;
}

void menu(array * workingArray) {
    int stop = 0;
    while (stop == 0) {
        printf("\tMENU\nChoose an option by entering it's associated number\n0. Display the table\n1. Index calculation for a user\n2. Add a user in the table\n3. Load a number of users from the chicago.txt file\n4. Display a user's salary\n5. Display from an index to another\n6. Number of conflicts\n7. Average size of conflicts\n8. Remove a user\n9. Remove from an index to another\n10. Exit\nInput : ");
        int input;
        scanf(" %d%*c", &input); //switch needs an int, but if a non int is typed as input, the menu goes haywire, goes in a scary circle
        switch (input) {
            case 0:
                displayArray(workingArray);
                scanf("%*c");
                break;
            case 1:
                ex1(workingArray);
                break;
            case 2:
                ex2(workingArray);
                break;
            case 3:
                ex3(workingArray);
                break;
            case 4:
                ex4(workingArray);
                break;
            case 5:
                ex5(workingArray);
                break;
            case 6:
                ex6(workingArray);
                break;
            case 7:
                ex7(workingArray);
                break;
            case 8:
                ex8(workingArray);
                break;
            case 9:
                ex9(workingArray);
                break;
            case 10:
                printf("stop\n");
                stop = 1;
                break;
            default:
                break;
        }
    }
}

void ex1(array * workingArray) {
    printf("\tINDEX CALCULATION FOR A USER\nPlease enter a lastname for the user : ");
    char lastname[56], firstname[56];
    scanf(" %s%*c", lastname);
    printf("Please enter a firstname for the user : ");
    scanf(" %s%*c", firstname);
    printf("Index for \"%s %s\" : %llu\n", lastname, firstname, indexCalculator(lastname, firstname, workingArray->base, workingArray->N));
    scanf("%*c");
}

void ex2(array * workingArray) {
    printf("\tADD A USER TO THE TABLE\nPlease enter a lastname for the user : ");
    char lastname[56], firstname[56];
    int salary = 0;
    scanf(" %s%*c", lastname);
    printf("Please enter a firstname for the user : ");
    scanf(" %s%*c", firstname);
    printf("Please enter a salary for the user : ");
    scanf(" %d%*c", &salary);
    user * userToAdd = createUser(lastname, firstname, salary);
    addSingleUserToArray(userToAdd, workingArray);
    displayArray(workingArray);
    scanf("%*c");
}

void ex3(array * workingArray) {
    printf("\tLOAD A NUMBER OF USERS FROM THE CHICAGO.TXT FILE\nPlease enter the number of users to load : ");
    long long unsigned int numberOfUsersToAdd = 0;
    scanf(" %llu%*c", &numberOfUsersToAdd);
    printf("working...\n");
    readFile("../chicago.txt", workingArray, numberOfUsersToAdd);
    displayArray(workingArray);
    scanf("%*c");
}

void ex4(array * workingArray) {
    printf("\tDISPLAY A USER\'S SALARY\nPlease enter the lastname of the user : ");
    char lastname[56], firstname[56];
    scanf(" %s%*c", lastname);
    printf("Please enter the firstname of the user : ");
    scanf(" %s%*c", firstname);
    user * userToSearch = createUser(lastname, firstname, 0);
    user * workingUser = searchUserInArray(userToSearch, workingArray);
    if (workingUser == NULL) {
        printf("Sorry, user \"%s %s\" was not found\n", lastname, firstname);
    }
    else {
        displayUser(workingUser);
    }
    scanf("%*c");
}

void ex5(array * workingArray) {
    printf("\tDISPLAY USERS FROM AN INDEX TO ANOTHER\nPlease enter an starting index : ");
    long long unsigned int startingIndex = 0, finishingIndex = 0;
    scanf(" %llu%*c", &startingIndex);
    printf("Please enter a finishing index : ");
    scanf(" %llu%*c", &finishingIndex);
    if (startingIndex < workingArray->N && finishingIndex < workingArray->N) {
        printf("array :\n");
        for (long long unsigned int i = startingIndex; i <= finishingIndex; i++) {
            printf("\tvector %llu:\n", i);
            displayVector(workingArray->content + i);
        }
    }
    else {
        printf("Indexes out of range of the table, aborting.\n");
    }
    scanf("%*c");
}

void ex6(array * workingArray) {
    printf("\tNUMBER OF CONFLICTS\n");
    long long unsigned int numberOfConflicts = 0;
    for (long long unsigned int i = 0; i < workingArray->N; i++) {
        if ((workingArray->content + i)->currentNumberOfUsers > 1) {
            numberOfConflicts++;
        }
    }
    printf("There are %llu conflicts in the table\n", numberOfConflicts);
    scanf("%*c");
}

void ex7(array * workingArray) {
    printf("\tAVERAGE SIZE OF CONFLICTS\n");
    long long unsigned int numberOfConflicts = 0, totalSizeOfConflicts = 0;
    for (long long unsigned int i = 0; i < workingArray->N; i++) {
        if ((workingArray->content + i)->currentNumberOfUsers > 1) {
            numberOfConflicts++;
            totalSizeOfConflicts+=(workingArray->content + i)->currentNumberOfUsers;
        }
    }
    float averageSizeOfConflicts = totalSizeOfConflicts / numberOfConflicts + totalSizeOfConflicts % numberOfConflicts;
    printf("Conflicts have an average size of %f\n", averageSizeOfConflicts);
    scanf("%*c");
}

void ex8(array * workingArray) {
    printf("\tREMOVE A USER\nPlease enter the lastname of the user : ");
    char lastname[56], firstname[56];
    scanf(" %s%*c", lastname);
    printf("Please enter the firstname of the user : ");
    scanf(" %s%*c", firstname);
    user * userToRemove = createUser(lastname, firstname, 0);
    removeUserFromVector(userToRemove, workingArray->content + indexCalculator(lastname, firstname, workingArray->base, workingArray->N));
    printf("User was removed.\n");
    scanf("%*c");
}

void ex9(array * workingArray) {
    printf("\tREMOVE FROM AN INDEX TO ANOTHER\nPlease enter a starting index : ");
    long long unsigned int startingIndex = 0, finishingIndex = 0;
    scanf(" %llu%*c", &startingIndex);
    printf("Please enter a finishing index : ");
    scanf(" %llu%*c", &finishingIndex);
    if (startingIndex < workingArray->N && finishingIndex < workingArray->N) {
        printf("removing...\n");
        for (long long unsigned int i = startingIndex; i <= finishingIndex; i++) {
            //removeVector(workingArray->content + i);
            *(workingArray->content + i) = *createVector();
        }
        printf("Users were removed\n");
    }
    else {
        printf("Indexes out of range of the table, aborting.\n");
    }
    scanf("%*c");
}
