#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256
void CopyString(char** strFirst, char* strSecond) {
    strFirst = (char*)malloc(sizeof(char)*strlen(strSecond));
    char* temp = strFirst;
    while (*temp) {
        *strSecond++ = *temp++;
    }
    *strSecond = '\0';
}
char** AddGuest(char** arrAllGuests, int* ionGuestCounter, char* szName) {
    ionGuestCounter += 1;
    arrAllGuests = realloc(&arrAllGuests, sizeof(char*) * (*ionGuestCounter));
    if (arrAllGuests == NULL) {
        return NULL;
    }
    else{
        CopyString(arrAllGuests[*ionGuestCounter], szName);
    }
    return arrAllGuests;
}
char** CancelGuest(char** arrAllGuests, int* ionGuestCounter, char* szName) {
    char** newArrAllGuests = (char**)malloc(sizeof(char*) * (*ionGuestCounter));
    for (int i = 0; i < (*ionGuestCounter); i++) {
        arrAllGuests[i] != szName ? newArrAllGuests[i] = arrAllGuests[i]: NULL;
    }
    free(arrAllGuests);
    return newArrAllGuests;
}
int ValidInput(char ch) {
    if (ch >= '1' && ch <= '5') {
        return int(ch);
    }
    else {
        return 0;
    }
}
void getName(char* szName) {
    printf("Please enter the name for the new order");
    *szName = (char*)malloc(sizeof(char) * BUFFER);
    gets(*szName);
    int size = strlen(szName);
    *szName = realloc(szName, sizeof(char) * size);
}
void ActionCode1(char** arrpszNames, int size) {
    size == 0 ? printf("There are no orders") : printf("There are %d orders with the names: \n", size);
    for (int i = 0; i < size; i++) {
        printf("%s\n", arrpszNames[i]);
    }
}
void ActionCode2(char** arrAllGuests, int* ionGuestCounter) {
    char* szName;
    getName(&szName);
    int size = strlen(szName);
    arrAllGuests = AddGuest(arrAllGuests, ionGuestCounter, szName);
}
void ActionCode3(char** arrAllGuests, int* ionGuestCounter) {
    char* szName;
    getName(&szName);
    arrAllGuests = CancelGuest(arrAllGuests, ionGuestCounter, szName);
}
void ActionCode4(char** arrAllGuests, int* ionGuestCounter) {
    for (int i = 0; i < *ionGuestCounter; i++) {
        free(arrAllGuests[i]);
    }
    free(arrAllGuests);
}
int main(void) {
    char** arrpszNames;
    int size = 0;

    char choice;
    printf("Welcome to the DonPringuili !\n");
    printf("Enter 1 to show the current waiting list \n");
    printf("Enter 2 to add a new guest to the waiting list \n");
    printf("Enter 3 to remove a guest from the waiting list \n");
    printf("Enter 4 to clear the waiting list \n");
    printf("Enter 5 to exit \n");
    printf("Please enter the choice - ");
    scanf("%c", &choice);
    choice = ValidInput(choice);
    while (!choice) {
        printf("Invalid input. Try again.\n");
        printf("Please enter the choice - ");
        scanf("%c", &choice);
        choice = ValidInput(choice);
    }
    while (choice) {
        if (choice == 1) {
            ActionCode1(arrpszNames,size);
        }
        else if (choice == 2) {
            ActionCode2(arrpszNames,&size);
        }
        else if (choice == 3) {
            ActionCode3(arrpszNames,size);
        }
        else if (choice == 4) {
            ActionCode4(arrpszNames,&size);
        }
        else if (choice == 5){
            break;
        }
        printf("Enter 1 to show the current waiting list \n");
        printf("Enter 2 to add a new guest to the waiting list \n");
        printf("Enter 3 to remove a guest from the waiting list \n");
        printf("Enter 4 to clear the waiting list \n");
        printf("Enter 5 to exit \n");
        printf("Please enter the choice - ");
        scanf("%c", &choice);
        choice = ValidInput(choice);
        while (!choice) {
            printf("Invalid input. Try again.\n");
            printf("Please enter the choice - ");
            scanf("%c", &choice);
            choice = ValidInput(choice);
        }
    }
    return 0;
}