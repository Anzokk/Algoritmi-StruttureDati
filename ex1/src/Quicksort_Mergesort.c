#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap (void *elem1, void *elem2, size_t size){
    void *scambia = malloc (size);
    memcpy (scambia, elem1, size);
    memcpy (elem1, elem2, size);
    memcpy (elem2, scambia, size);
    free (scambia);
}

void merge(void *first, size_t nitems1, size_t nitems2, size_t size, int (*compar)(const void*, const void*)) {
    size_t totItems = nitems1 + nitems2; 
    void *ordered = malloc(totItems * size); 
    void *left = first;
    void *right = first + nitems1 * size;
    void *insert = ordered; 

    size_t leftCount = 0, rightCount = 0; 

    while (leftCount < nitems1 && rightCount < nitems2) {
        if (compar(left, right) > 0) {
            memcpy(insert, right, size);
            right = right + size;
            rightCount++;
        } else {
            memcpy(insert, left, size);
            left = left + size;
            leftCount++;
        }
        insert = insert + size;
    }
    while (leftCount < nitems1) {
        memcpy(insert, left, size);
        left=left+size;
        leftCount++;
        insert = insert + size;
    } 
    while (rightCount < nitems2) {
        memcpy(insert, right, size);
        right=right+size;
        rightCount++;
        insert = insert + size;
    }

    memcpy(first, ordered, totItems * size);
    free(ordered);
}

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)){

    if ((nitems)>1) {
        merge_sort(base, nitems/2, size, compar);
        merge_sort(base + nitems/2 * size, nitems - nitems/2, size, compar);
        merge(base, nitems/2, nitems-nitems/2, size, compar);
    }
}



int partition (void *pivot, size_t nitems, size_t size, int (*compar)(const void*, const void*)){
    
    //Definizione del valore di Pivot
    if (nitems>2){
        void *half = pivot+(nitems-1)*size; // Decido quale elemento prendere come Pivot
        swap (pivot,half,size);
    }

    void *right = pivot + (nitems-1)*size;
    int countLeft=2;
    void *left = pivot + size;
    int countRight=nitems;
    while (countLeft<=countRight){
        if (compar (left, pivot) <= 0){
            countLeft ++;
            left = left + size;
        }else if (compar (right,pivot) > 0){
            countRight --;
            right = right - size;
        }else {
            swap(left,right,size);
            countLeft ++;
            left = left + size;
            countRight --;
            right = right - size;
        }
    }
    swap (pivot,right,size);
    return countRight;
}

void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)){
    if (nitems>0){
        int p = partition(base, nitems, size, compar);
            if (p>2){
                quick_sort (base, p - 1 , size, compar);
            }
            if (nitems-p >1){
                quick_sort(base + p * size, nitems - p, size, compar);  
            }
    }
}