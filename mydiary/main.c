#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#define MAX_SIZE 1000
#define YEAR date[0]
#define MONTH date[1]
#define DAY date[2]

typedef struct Memo {
    int num;
    int date[3];
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
        case 'H': ShowMenu(); break;
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
    printf(" N yyyy/mm/dd content : insert a new memo\n");
    printf(" P              : print all memoes\n");
    printf(" F content      : find a memo\n");
    printf(" L filename     : load a file\n");
    printf(" S filename     : save a file\n");
    printf(" E              : exit program\n");
    printf("------------------------------------\n");
}

void NewMemo(char* command, List* list) {
    Memo* memo = (Memo*)malloc(sizeof(Memo));
    char* token = strtok(command, " ");

    memo->num = list_size(list) + 1;
    for (int i = 0; i < 3; i++) {
        if (i != 2) {
            token = strtok(NULL, "/");
        }
        else {
            token = strtok(NULL, " ");
        }
        memo->date[i] = atoi(token);
    }
    token = strtok(NULL, "\n");
    strcpy(memo->content, token);
    InsertLastNode(list, memo);
    printf("complete\n");
}

void PrintMemoes(List* list) {
    if (is_empty(list)) {
        printf("list is empty\n");
        return;
    }
    else {
        ListNode* node = list->head;
        printf("------------------------------\n");
        while (node != NULL) {
            printf("%d | %d/%d/%d : %s\n", 
                ((Memo*)node->data)->num, 
                ((Memo*)node->data)->YEAR, 
                ((Memo*)node->data)->MONTH, 
                ((Memo*)node->data)->DAY, 
                ((Memo*)node->data)->content);
            node = node->link;
        }
        printf("------------------------------\n");
    }
}
void FindMemo(char* command, List* list) {

}
void LoadFile(List* list) {

}
void SaveFile(List* list) {

}
void ExitProgram(List* list) {

}