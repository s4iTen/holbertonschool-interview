#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);

int find_max_int(int *array, size_t size);
void build_buckets(int *bucket_sizes, int **buckets);
void into_array(int *array, size_t size, int **buckets, int *bucket_sizes);
void radix_sort(int *array, size_t size);

#endif
