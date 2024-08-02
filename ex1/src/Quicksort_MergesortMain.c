#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Quicksort_Mergesort.h"

int string_compare (const void *a, const void *b) {
    return strcmp(((Record *)a)->field1, ((Record *)b)->field1);
}

int int_compare(const void *a, const void *b) {
    int int_a = ((Record *)a)->field2;
    int int_b = ((Record *)b)->field2;
    return (int_a > int_b) - (int_a < int_b);
}

int float_compare(const void *a, const void *b) {
    float float_a = ((Record *)a)->field3;
    float float_b = ((Record *)b)->field3;
    return (float_a > float_b) - (float_a < float_b);
}

void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo){
    
    int (*compar)(const void*, const void*);
    
    if (field == 1){
        compar= string_compare;
    }else if (field == 2) {
        compar = int_compare;
    }else {
        compar = float_compare;
    }

    int record_count = 0;
    char line[50];

    while (fgets(line, sizeof(line), infile)) {
        record_count++;
    }

    rewind(infile); // 

    Record *records = malloc(sizeof(Record)*record_count); 
    Record *elem;
    size_t index = 0;

    while (fgets(line, sizeof(line), infile)) {
        sscanf(line, "%d,%49[^,],%d, %f", &records[index].id, &records[index].field1, &records[index].field2, &records[index].field3);
        index++;
    }

    fclose(infile);


    clock_t start = clock(); 

    if (algo == 1){
        merge_sort (records,record_count,sizeof(Record),compar);
    }else{
        quick_sort (records,record_count,sizeof(Record),compar);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; 
    printf("Sorting completed in %.6f seconds\n", time_spent);
    
    if (outfile == NULL) {
        perror("Error opening output file");
        free(records);
    }

    for (size_t i = 0; i < record_count; i++) {
        fprintf(outfile, "%d,%s,%d,%.6f\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }

    fclose(outfile);

    free (records); 
}

int main (int argc, char *argv[]){

    if (argc != 5) {
        perror("Error on parameters");
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    
    size_t field = atoi(argv[3]);
    if (field <1 && field >3){
        perror("Field value must be beetween 1 and 3");
        return EXIT_FAILURE;
    }
        
    size_t algo = atoi(argv[4]);
    if (algo <1 && field >2){
        perror("Field value must be 1 or 2");
        return EXIT_FAILURE;
    }

    FILE *infile = fopen(input_file, "read");
    if (infile == NULL) {
        fclose (infile);
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outfile = fopen(output_file, "write");

    sort_records (infile,outfile,field,algo);
    return 0;
}