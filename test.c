#include "test.h"
#include <collect/map.h>
#include <collect/vector.h>
#include <collect/list.h>

int main()
{
    map *m = new_map();
    vector *v = new_vector();
    list *l = new_list();
    MAP_SET(m, "one", 1);
    MAP_SET(m, "two", 2);
    int one = 1;
    vector_push(v, &one);
    list_push(l, &one);

    ASSERT(MAP_GET(int, m, "one") == 1);
    ASSERT(MAP_GET(int, m, "two") == 2);
    ASSERT(vector_at(v, 0)           == &one);
    ASSERT(l->first->val             == &one);

    free_list(l, NULL);
}