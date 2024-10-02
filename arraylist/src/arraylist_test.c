#include <stdio.h>
#include "arraylist.h"

int main() 
{
    ArrayList *list = arraylist(10);
    printf("Size: %d\n", list->size);
    printf("Capacity: %d\n", list->capacity);

    alst_add(list, 10);
    alst_add(list, 20);
    alst_add(list, 30);

    printf("Size: %d\n", list->size);
    printf("Capacity: %d\n", list->capacity);
    printf("Data: %d\n", list->data[2]);

    alst_remove(list);

    printf("Size: %d\n", list->size);

    alst_remove_index(list, 0);

    printf("Size: %d\n", list->size);
    printf("Data: %d\n", list->data[0]);

    alst_set(list, 0, 100);

    printf("Data: %d\n", list->data[0]);


    alst_clear(list);
    
    printf("Size: %d\n", list->size);



    return 0;
}