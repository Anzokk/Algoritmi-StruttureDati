#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int edit_distance(const char *s1, const char* s2){
    
    size_t size_s1 = strlen(s1);
    size_t size_s2 = strlen(s2);

    if (size_s1 == 0) return size_s2;
    if (size_s2 == 0) return size_s1;

    if (tolower(s1[0]) == tolower(s2[0])){
        return edit_distance(s1 + 1, s2 + 1);
    } else{
        int distance_canc = 1+ edit_distance(s1, s2 + 1);
        int distance_ins = 1+ edit_distance(s1 + 1, s2);
        if (distance_canc <= distance_ins){
            return distance_canc;
        }else{
            return distance_ins;
        }
    }
}

int edit_distance_dyn_loop(int **memo, const char *s1, const char* s2){
    
    size_t size_s1 = strlen(s1);
    size_t size_s2 = strlen(s2);
    
    if (memo[size_s1][size_s2]!= -1){
        return memo[size_s1][size_s2];
    }

    if (size_s1 == 0) return size_s2;
    if (size_s2 == 0) return size_s1;

    int distance;

    if (tolower(s1[0]) == tolower(s2[0])){
        distance = edit_distance_dyn_loop(memo, s1 + 1, s2 + 1);
    }else{
        int distance_canc = 1+ edit_distance_dyn_loop(memo, s1, s2 + 1);
        int distance_ins = 1+ edit_distance_dyn_loop(memo,s1 + 1, s2);
        if (distance_canc <= distance_ins){
            distance = distance_canc;
        }else{
            distance = distance_ins;
        }
    }
    memo[size_s1][size_s2] = distance;
    return distance;

}

int edit_distance_dyn(const char *s1, const char* s2){

    size_t size_s1 = strlen(s1);
    size_t size_s2 = strlen(s2);

    int **memo = (int **)malloc((size_s1 + 1) * sizeof(int *));

    for (int i = 0; i <= size_s1; i++) {
        memo[i] = (int *)malloc((size_s2 + 1) * sizeof(int));
        for (int j = 0; j <= size_s2; j++) {
            memo[i][j] = -1;
        }
    }

    int dyn = edit_distance_dyn_loop(memo,s1,s2);
    free(memo);


    return dyn;
}