#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct ListNode {
	void* data;
	struct ListNode* link;
}ListNode;

typedef struct List {
	ListNode* head;
}List;

List* CreateList();
void FreeList(List* list);
void InsertFirstNode(List* list, void* data);
void InsertMiddleNode(List* list, ListNode* pre, void* data);
void InsertLastNode(List* list, void* data);
void DeleteNode(List* list, ListNode* node);

#define is_empty(List) ((List)->head == NULL ? 1 : 0)

#endif