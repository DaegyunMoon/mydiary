#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

List* CreateList() {
	List* list = (List*)malloc(sizeof(List));
	if (list != NULL) {
		list->size = 0;
		list->head = NULL;
		return list;
	}
	else {
		printf("Memory Allocation Error\n");
		return NULL;
	}
}
void FreeList(List* list) {
	ListNode* node;
	while (!is_empty(list)) {
		node = list->head;
		list->head = node->link;
		free(node);
		node = NULL;
	}
	free(list);
}
void InsertFirstNode(List* list, void* data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node != NULL) {
		node->data = data;
		node->link = list->head;
		list->head = node;
		list->size++;
	}
	else {
		printf("Memory Allocation Error\n");
		return;
	}
}
void InsertMiddleNode(List* list, ListNode* pre, void* data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node != NULL) {
		node->data = data;
		if (pre == NULL) {
			return;
		}
		else if (is_empty(list)) {
			node->link = NULL;
			list->head = node;
		}
		else {
			node->link = pre->link;
			pre->link = node;
		}
		list->size++;
	}
	else {
		printf("Memory Allocation Error\n");
		return;
	}
}
void InsertLastNode(List* list, void* data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* temp = list->head;
	if (node != NULL) {
		node->data = data;
		node->link = NULL;
		if (is_empty(list)) {
			list->head = node;
		}
		else {
			while (temp->link != NULL) {
				temp = temp->link;
			}
			temp->link = node;
		}
		list->size++;
	}
	else {
		printf("Memory Allocation Error\n");
		return;
	}
}
void DeleteNode(List* list, ListNode* node) {
	if (is_empty(list) || node == NULL) {
		return;
	}
	else if (list->head->link == NULL) {
		free(list->head);
		list->head = NULL;
		list->size--;
		return;
	}
	else {
		ListNode* temp = list->head;
		if (temp == node) {
			list->head = node->link;
			free(node);
			list->size--;
			return;
		}
		while (temp->link != node) {
			temp = temp->link;
		}
		temp->link = node->link;
		free(node);
		list->size--;
	}
}