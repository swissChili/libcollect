#include <collect/list.h>

list *new_list()
{
    list *l = malloc(sizeof(list));
    l->first = NULL;
    l->length = 0;
    l->last = NULL;
    return l;
}


list_node *new_list_node()
{
    return malloc(sizeof(list_node));
}

void free_list_node(list_node *node, free_list_node_val_fn fn)
{
    if (fn)
        fn(node->val);
    free(node);
}

void free_list(list *l, free_list_node_val_fn fn)
{
    list_node *this = l->first;
    list_node *next;
    while (this)
    {
        next = this->next;
        free_list_node(this, fn);
        this = next;
    }
}

void list_push(list *l, void *d)
{
    list_node *node = new_list_node();
    node->val = d;
    node->next = NULL;
    node->prev = l->last;
    if (l->last)
    {
        l->last->next = node;
    }
    if (l->first == NULL)
    {
        l->first = node;
    }
    l->last = node;
}