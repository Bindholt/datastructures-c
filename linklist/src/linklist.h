#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    int data;
};

typedef struct {
    Node* tail;
    Node* head;
} LinkList;

LinkList* linklist();
Node* node(int data);
void llst_add_first(LinkList* list, int data);
void llst_add_last(LinkList* list, int data);
void llst_remove_first(LinkList* list);
void llst_remove_last(LinkList* list);
void llst_clear(LinkList* list);
int llst_first(LinkList* list);
int llst_last(LinkList* list);
void llst_remove_node(LinkList* list, Node* node);
void llst_insert_before_node(LinkList* list, Node* new_node, int data);
void llst_insert_after_node(LinkList* list, Node* new_node, int data);
void llst_insert_after(LinkList* list, int data, int new_data);
void llst_insert_before(LinkList* list, int data, int new_data);
int llst_index_of(LinkList* list, int data);
int llst_get(LinkList* list, int index);
int llst_node_at(LinkList* list, int index);
int llst_size(LinkList* list);
void llst_dump_list(LinkList* list);

#endif