
#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap (void *elem1, void *elem2, size_t size);
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void merge(void *first, size_t nitems1, size_t nitems2, size_t size, int (*compar)(const void*, const void*));

void* partition(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
int int_compare(const void *a, const void *b);
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*));

typedef struct Record {
    int id;
    char field1[50];
    int field2;
    float field3;
} Record;


#endif QUICKSORT_H

