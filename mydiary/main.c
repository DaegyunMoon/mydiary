#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#define MAX_SIZE 1000

typedef struct Memo {
    int date;
    char content[MAX_SIZE];
}Memo;

void ShowMenu();
void NewMemo(char* command, List* list);
void PrintMemoes(List* list);
void FindMemo(char* command, List* list);
void LoadFile(List* list);
void SaveFile(List* list);
void ExitProgram(List* list);

int main() {
    List* list = CreateList();
    char* command = (char*)malloc(sizeof(char) * MAX_SIZE);
    ShowMenu();

    while (1) {
        rewind(stdin);
        printf(">> ");
        scanf("%[^\n]s", command);
        switch (command[0]) {
        case 'H': ShowMenu();
        case 'N': NewMemo(command, list); break;
        case 'P': PrintMemoes(list); break;
        case 'F': FindMemo(command, list); break;
        case 'L': LoadFile(list); break;
        case 'S': SaveFile(list); break;
        case 'E': ExitProgram(list); break;
        default: printf("command not found. enter 'H' to see all commands\n");
        }
        if (command[0] == 'E') break;
    }
}

void ShowMenu() {
    printf("Simple Diary\n");
    printf("------------------------------------\n");
    printf(" N date content : insert a new memo\n");
    printf(" P              : print all memoes\n");
    printf(" F content      : find a memo\n");
    printf(" L filename     : load a file\n");
    printf(" S filename     : save a file\n");
    printf(" E              : exit program\n");
    printf("------------------------------------\n");
}

void NewMemo(char* command, List* list) {

}
void PrintMemoes(List* list) {

}
void FindMemo(char* command, List* list) {

}
void LoadFile(List* list) {

}
void SaveFile(List* list) {

}
void ExitProgram(List* list) {

}