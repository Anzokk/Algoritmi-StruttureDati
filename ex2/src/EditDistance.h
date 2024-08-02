#ifndef SORT_H
#define SORT_H

int edit_distance(const char *s1, const char* s2);
int edit_distance_dyn_loop(int **memo, const char *s1, const char* s2);
int edit_distance_dyn(const char *s1, const char* s2);

#endif 