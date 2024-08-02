#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "EditDistance.h"

int main (int argc, char *argv[]){
    if (argc != 3) {
        perror("Error on parameters");
        return EXIT_FAILURE;
    }

    char *dictionary_file = argv[1];

    char *correctme_file = argv[2];

    FILE *dictionary = fopen(dictionary_file, "read1");
    if (dictionary == NULL) {
        fclose (dictionary);
        perror("Error opening input file dictionary");
        return EXIT_FAILURE;
    }
    FILE *correctme = fopen(correctme_file, "read2");
    if (dictionary == NULL) {
        fclose (correctme);
        perror("Error opening input file correctme");
        return EXIT_FAILURE;
    }
    int lines_count = 0;
    char d_line[50];
    while (fgets(d_line, sizeof(d_line), dictionary)) {
        lines_count++;
    }
    rewind(dictionary);

    char *words_dictionary = malloc(sizeof(words_dictionary)*lines_count);

    char c_line[1000000];
    fgets(c_line, sizeof(c_line), correctme);
    char *token;

    token = strtok(c_line, " ");
    
    int distance=-1;
    int min_distance;
    char similar_words[5][100];
    int index_similar_words;
    while (token != NULL) {
        min_distance=-1;
        index_similar_words=0;
        while (fgets(d_line, sizeof(d_line), dictionary) && distance != 0) {
            d_line[strcspn(d_line, "\n")] = '\0';
            distance = edit_distance_dyn(token,d_line);
            if (distance != 0){
                if (min_distance == -1){
                    min_distance = distance;
                    strcpy(similar_words[index_similar_words], d_line);
                    index_similar_words ++;
                }else if (distance < min_distance){
                    index_similar_words = 0;
                    min_distance=distance;
                    strcpy(similar_words[index_similar_words], d_line);
                    index_similar_words++;
                }else if (distance == min_distance && index_similar_words<5){
                    strcpy(similar_words[index_similar_words], d_line);
                    index_similar_words++;
                }
            }
        }
        if (distance == 0){
            printf ("%s \n", token);
        }else{
            printf ("%s Sbagliato, parole simili: ", token);
            for (int i=0 ; i<index_similar_words; i++){
                printf ("%s ", similar_words[i]);
            }
            printf ("\n");
        }
        distance = -1;
        rewind (dictionary);
        token = strtok(NULL, " .\n,;:?!");
    }
    fclose (dictionary);
    fclose (correctme);
    return 0;
}