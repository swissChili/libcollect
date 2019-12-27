#include <stdlib.h>
#include <stdint.h>
#include <collect/vector.h>


vector *new_vector_sized(uint64_t size)
{
    vector *new = malloc(sizeof(vector));
    new->length = 0;
    new->size = 128;
    new->items = malloc(size * sizeof(void *));

    return new;
}

vector *new_vector()
{
    return new_vector_sized(VEC_ALLOC_SIZE);
}

void free_vector(vector *v)
{
    free(v->items);
    free(v);
}

void *vector_at(vector *v, uint64_t i)
{
    if (i < 0 || i > v->length)
        return NULL;
    else
    {
        return v->items[i];
    }
}

int vector_set(vector *v, uint64_t i, void *val)
{
    if (i >= v->size)
    {
        uint64_t new_len = v->size;

        while (i > new_len)
        {
            new_len *= 2;
        }
        
        v->items = realloc(v->items, new_len * sizeof(void *));

        if (v->items == NULL)
            return 0;
    }
    v->items[i] = val;
    return 1;
}

void vector_push(vector *v, void *val)
{
    if (v->length + 1 >= v->size)
    {
        // double alloc size
        v->size *= 2;
        // Reallocate memory
        v->items = realloc(v->items, v->size * sizeof(void *));
    }
    v->items[v->length++] = val;
}
