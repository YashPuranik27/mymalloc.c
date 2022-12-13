#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

// Global variables
int allocAlg;
int blockSize;
void* heap;

// Function definitions
void myinit(int allocAlg) {
    // Create a 1 MB "heap" and perform any other initializations your code needs.
    blockSize = 1024*1024;
    heap = malloc(blockSize);
    if (heap == NULL) {
        printf("Error allocating memory!\n");
        return;
    }
    // Set the allocation algorithm
    allocAlg = allocAlg;
}

void* mymalloc(size_t size) {
    // From the “heap”, allocate a region of at least the requested size and return a pointer to the beginning of the region.
    if (size == 0) {
        return NULL;
    }
    // All returned addresses must be 8-byte aligned.
    int alignedSize = size + (8 - (size % 8));
    void* start;
    switch (allocAlg) {
        // First fit
        case 0:
            start = firstFit(alignedSize);
            break;
        // Next fit
        case 1:
            start = nextFit(alignedSize);
            break;
        // Best fit
        case 2:
            start = bestFit(alignedSize);
            break;
    }
    return start;
}

void myfree(void* ptr) {
    // Mark the given region as free and available to be allocated for future requests.
    if (ptr == NULL) {
        return;
    }
    // Coalesce with adjacent free regions
    coalesce();
}

void* myrealloc(void* ptr, size_t size) {
    // Reallocate the region pointed to by ptr to be at least the new given size.
    if (ptr == NULL) {
        return mymalloc(size);
    }
    if (size == 0) {
        myfree(ptr);
        return NULL;
    }
    // If this cannot be done in-place, a new region should be allocated, the data from the original region should be copied over, and the old region should be freed.
    void* start = mymalloc(size);
    memcpy(start, ptr, size);
    myfree(ptr);
    return start;
}

void mycleanup() {
    // Free the 1 MB “heap” and perform any other cleanup your code needs.
    free(heap);
}

// Helper functions
void* firstFit(int size) {
    // Search for the first free block with sufficient size.
    // Allocate the block and return the start address.
    // Return NULL if no such block is found.
    return NULL;
}

void* nextFit(int size) {
    // Search for the next free block with sufficient size.
    // Allocate the block and return the start address.
    // Return NULL if no such block is found.
    return NULL;
}

void* bestFit(int size) {
    // Search for the best free block with sufficient size.
    // Allocate the block and return the start address.
    // Return NULL if no such block is found.
    return NULL;
}

void coalesce() {
    // Coalesce adjacent free blocks.
}