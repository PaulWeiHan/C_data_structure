#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Linked_list.h"

int list_init(list_t *list, void (*destory)(void *data))
{
    list->size = 0;
    list->destory = destory;
    list->head = NULL;
    list->tail = NULL;
    return 0;
}

void list_destroy(list_t *list)
{
    void *data;
    while(list_size(list) > 0)
    {
        if (list_rem_next(list,NULL,(void **)&data) == 0 && list->destory != NULL)
        {
            list->destory(data);
        }
    }
    memset(list,0,sizeof(list_t));
}

int list_ins_next(list_t *list, node_t *element, const void *data)
{
    node_t *new_element;

    //Allocate storage for the element.
    if((new_element = (node_t *)malloc(sizeof(node_t))) == NULL) 
        return -1;
    //Insert the new element into the list.
    new_element->data = (void *)data;
    if(element == NULL){
        if(list_size(list) == 0) 
            list->tail = new_element;
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        if(element_next = NULL)
            list->tail = element;
        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;
    return 0;
}

int list_rem_next(list_t *list, node_t *element, void **data)
{
    node_t *old_element;

    if(list_size(list) == 0)
        return -1;

    if(element == NULL)
    {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if(list_size(list) == 1)
            list->tail = NULL;
    }
    else
    {
        if(element->next == NULL)
            return -1;
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if(element->next ==NULL)
            list->tail == NULL;
    }

    free (old_element);

    list->size--;
    return 0;
}












