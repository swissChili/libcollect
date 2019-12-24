#include "test.h"
#include <collect/map.h>

int main()
{
    map *m = new_map();
    MAP_SET(m, "one", 1);
    MAP_SET(m, "two", 2);

    ASSERT(MAP_GET(int, m, "one") == 1);
    ASSERT(MAP_GET(int, m, "two") == 2);
}