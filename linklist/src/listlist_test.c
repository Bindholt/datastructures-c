#include <stdio.h>
#include "linklist.h"

int main()
{
    LinkList *list = linklist();
    llst_add_first(list, 10);
    llst_add_first(list, 20);
    llst_add_last(list, 30);
    // llst_dump_list(list);

    // llst_remove_first(list);
    // llst_dump_list(list);

    // llst_remove_last(list);
    // llst_dump_list(list);

    // llst_clear(list);

    // llst_dump_list(list);

    llst_insert_after(list, 10, 15);

    llst_insert_before(list, 10, 25);

    llst_dump_list(list);

    return 0;
}