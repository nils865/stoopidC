#include "../../utils/hashmap/hashmap.h"

Hashmap *variables;

void initVariableManager()
{
    variables = table_create();
}
