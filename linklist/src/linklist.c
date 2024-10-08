#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

LinkList* linklist() 
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node* node(int data) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void llst_add_first(LinkList* list, int data) 
{
    Node* n = node(data);
    if(list->head != NULL) {
        list->head->prev = n; 
        n->next = list->head;
        list->head = n;
    } else {
        list->head = n;
        list->tail = n;
    }
}

void llst_add_last(LinkList* list, int data)
{
    Node* n = node(data);
    if(list->head != NULL)
    {
        list->tail->next = n;
        n->prev = list->tail;
        list->tail = n;
    } else {
        list->head = n;
        list->tail = n;
    }
}

void llst_remove_first(LinkList* list) 
{
    if(list->head == list->tail)
    {
        llst_clear(list);
    } else {
        Node* next = list->head->next;
        free(list->head);
        list->head = next;
        list->head->prev = NULL;
    }
}

void llst_remove_last(LinkList* list) 
{
    if(list->head == list->tail) 
    {
        llst_clear(list);
    } else {
        Node* prev = list->tail->prev;
        free(list->tail);
        list->tail = prev;
        list->tail->next = NULL;
    }
}

void llst_insert_before_node(LinkList* list, Node* new_node, int data) 
{
    Node* n = node(data);
    if(new_node->prev != NULL) 
    {
        new_node->prev->next = n;
        n->prev = new_node->prev;
    } else {
        list->head = n;
    }
    n->next = new_node;
    new_node->prev = n;
}

void llst_insert_after_node(LinkList* list, Node* new_node, int data) 
{
    Node* n = node(data);
    if(new_node->next != NULL) 
    {
        new_node->next->prev = n;
        n->next = new_node->next;
    } else {
        list->tail = n;
    }
    n->prev = new_node;
    new_node->next = n;
}

void llst_insert_after(LinkList* list, int data, int new_data) 
{
    Node* current = list->head;
    while(current != NULL) 
    {
        if(current->data == data) 
        {
            llst_insert_after_node(list, current, new_data);
            return;
        }
        current = current->next;
    }
}

void llst_insert_before(LinkList* list, int data, int new_data) 
{
    Node* current = list->head;
    while(current != NULL) 
    {
        if(current->data == data) 
        {
            llst_insert_before_node(list, current, new_data);
            return;
        }
        current = current->next;
    }
}

int llst_first(LinkList* list) 
{
    return list->head->data;
}

int llst_last(LinkList* list) 
{
    return list->tail->data;
}

void llst_remove_node(LinkList* list, Node* node) 
{
    if(node->prev != NULL) 
    {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if(node->next != NULL) 
    {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node);
}

void llst_remove(LinkList* list, int data) 
{
    Node* current = list->head;
    while(current != NULL) 
    {
        if(current->data == data) 
        {
            llst_remove_node(list, current);
            return;
        }
        current = current->next;
    }
}

void llst_swap_nodes(Node* node1, Node* node2) 
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

int llst_size(LinkList* list) 
{
    int size = 0;
    Node* current = list->head;
    while(current != NULL) 
    {
        size++;
        current = current->next;
    }
    return size;
}

int llst_node_at(LinkList* list, int index) 
{
    int i = 0;
    Node* current = list->head;
    while(current != NULL) 
    {
        if(i == index) 
        {
            return current->data;
        }
        i++;
        current = current->next;
    }
    return -1;
}

int llst_get(LinkList* list, int index) 
{
    return llst_node_at(list, index);
}

int llst_index_of(LinkList* list, int data) 
{
    int i = 0;
    Node* current = list->head;
    while(current != NULL) 
    {
        if(current->data == data) 
        {
            return i;
        }
        i++;
        current = current->next;
    }
    return -1;
}



void llst_clear(LinkList* list) 
{
    Node* current = list->head;
    while(current != NULL) 
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}


void llst_dump_list(LinkList* list) 
{
    Node* current = list->head;
    while(current != NULL) 
    {
        printf("Data: %d next: %d \n", current->data, current->next != NULL ? current->next->data : -1);
        printf("=====================================\n");
        current = current->next;
    }
}