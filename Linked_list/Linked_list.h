#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "stdlib.h"

typedef node_s node_t;
struct node_s
{
	void *data;
	node_t *next;
};

typedef list_s list_t;
struct list_s
{
	int size;
	int	(*match)(const void *key1, const void *key2);
	void (*destory)(void *data);
	node_t *head;
	node_t *tail;
};

/* Public Interface */

void list_init(list_t *list, void (*destory)(void *data));
void list_destroy(list_t *list);
int list_ins_next(list_t *list, node_t *element, const void *data);
int list_rem_next(list_t *list, node_t *element, void **data);
#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next) 


#endif