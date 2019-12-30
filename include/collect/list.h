#ifndef LIBCOLLECT_LIST_H
#define LIBCOLLECT_LIST_H

#include <stdlib.h>

/**
 * @brief A single node in a linked list
 */
typedef struct list_node
{
    struct list_node *prev;
    struct list_node *next;
    void *val;
} list_node;

/**
 * @brief A linked list
 */
typedef struct list
{
    list_node *first;
    list_node *last;
    size_t length;
} list;

typedef void (* free_list_node_val_fn)(void *);

/**
 * @brief Allocate a list on the heap
 * @return A pointer to the list
 */
list *new_list();

/**
 * @brief Free a list node
 * @param node
 * @param The function to call on the value
 */
void free_list_node(list_node *node, free_list_node_val_fn fn);

/**
 * @brief Free an allocated list
 * @param l The list to free
 * @param fn The function to call on each list node's value
 */
void free_list(list *l, free_list_node_val_fn fn);

/**
 * @brief Push an item to the back of a list
 * @param l The list
 * @param d A pointer to the data to push
 */
void list_push(list *l, void *d);

#endif //LIBCOLLECT_LIST_H
