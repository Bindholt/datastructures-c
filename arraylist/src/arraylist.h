#include <stdlib.h>
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;


ArrayList *arraylist(int initial_capacity);
void alst_add(ArrayList *list, int value);
int alst_get(ArrayList *list, int index);
int alst_size(ArrayList *list);
void alst_remove(ArrayList *list);
void alst_remove_index(ArrayList *list, int index);
void alst_set(ArrayList *list, int index, int value);
void alst_clear(ArrayList *list);



#endif