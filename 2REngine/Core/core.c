#include "core.h"
#include "Logging/logging.h"
#include <corecrt_malloc.h>

void* mem_alloc(size_t size, const char* name)
{
    if(MEMORY_ALLOCATION_DEBUG_MODE_ENABLED)
        printf("%s%s %d%s\n", "ALLOCATING TO POINTER ", name, (int)size, " BYTES");
    return malloc(size);
}

void mem_free(void* ptr, const char* name)
{
    if(MEMORY_ALLOCATION_DEBUG_MODE_ENABLED)
        printf("%s%s %d%s\n", "FREEING POINTER ", name, (int)sizeof(ptr), " BYTES");

    free(ptr);
    ptr = NULL;
}
