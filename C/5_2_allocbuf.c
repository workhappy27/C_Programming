#include <stdio.h>
#include <stddef.h>  // size_t

#define ALLOC_SIZE 10000

static char allocbuff[ALLOC_SIZE];
static char *allocp = allocbuff;  // next free location

typedef char* AllocMarker;

AllocMarker alloc_mark(void) {
    return allocp;
}

char *alloc_mem(size_t req_n)
{
    if (req_n == 0) {
        return NULL;  // refuse zero-sized allocations
    }

    // How many bytes remain?
    size_t remaining = (size_t)(allocbuff + ALLOC_SIZE - allocp);

    if (remaining >= req_n) {
        char *ret = allocp;
        allocp += req_n;
        return ret;
    } else {
        return NULL;  // out of memory
    }
}

void alloc_release(AllocMarker m) {
    // Ensure the marker is within our buffer; add checks in debug builds
    if (m >= allocbuff && m <= allocbuff + ALLOC_SIZE) {
        allocp = m;
    }
}

int main(void)
{
char *p = alloc_mem(5);
AllocMarker m = alloc_mark();

    if (p == NULL) {
        puts("Allocation failed");
        return 1;
    }
    printf("p: %p\n", (void *)p);
    alloc_release(m);
    return 0;
}

/*
can’t call free(p) in your current program.
Your allocator hands out pointers into a static global array (allocbuff).
Those pointers were not obtained from malloc/calloc/realloc, so the C 
runtime’s free must not be used on them. Doing so is undefined behavior.

In order to reclaim memory in bulk for a region, capture a “marker”
(the current position) and later “pop” back to it.
*/
