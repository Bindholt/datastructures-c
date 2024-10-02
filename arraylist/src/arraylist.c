#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arraylist.h"

const int INITIAL_CAPACITY = 10;

void check_capacity(ArrayList *list);
void resize(ArrayList *list, int new_capacity);

ArrayList *arraylist(int initial_capacity) 
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (int *)malloc(initial_capacity * sizeof(int));
    list->size = 0;
    list->capacity = initial_capacity;
    return list;
}

void alst_add(ArrayList *list, int value) {
    check_capacity(list);
    list->data[list->size] = value;
    list->size++;
}

int alst_get(ArrayList *list, int index)
{
    if(index < 0 || index >= list->size) 
    {
        return 0;
    }

    return list->data[index];
}

int alst_size(ArrayList *list) 
{
    return list->size;
}

void alst_remove(ArrayList *list) {
    if(list->size > 0) 
    {
        list->size--;
        check_capacity(list);
    }
}   

void alst_remove_index(ArrayList *list, int index)
{
    if(index < 0 || index >= list->size) 
    {
        return;
    }

    for(int i = index; i < list->size - 1; i++) 
    {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    check_capacity(list);
}

void insertIndex(ArrayList *list, int index, int value)
{
    if(index < 0 || index >= list->size) 
    {
        return;
    }

    check_capacity(list);

    for(int i = list->size; i > index; i--) 
    {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = value;
    list->size++;
}

void alst_set(ArrayList *list, int index, int value)
{
    if(index < 0 || index >= list->size) 
    {
        return;
    }

    list->data[index] = value;
}

void alst_clear(ArrayList *list) 
{
    list->size = 0;
    check_capacity(list);
}

void check_capacity(ArrayList *list) 
{
    if (list->size >= list->capacity) 
    {
        resize(list, list->capacity * 2);
    } else if (list->size <= list->capacity / 2 && list->capacity > INITIAL_CAPACITY) 
    {
        resize(list, list->capacity / 2);
    }
}

void resize(ArrayList *list, int new_capacity) 
{
    if(new_capacity < INITIAL_CAPACITY) 
    {
        new_capacity = INITIAL_CAPACITY;
    }

    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    memcpy(new_data, list->data, list->size * sizeof(int));
    free(list->data);
    list->data = new_data;
}