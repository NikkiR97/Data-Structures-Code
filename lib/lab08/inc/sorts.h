#ifndef CMPE126F17_LABS_SORTS_H
#define CMPE126F17_LABS_SORTS_H

#include "doubly_linked_list.h"

class sorts{
public:
    lab6::doubly_linked_list insertion_sort(lab6::doubly_linked_list input, int iterations);
    lab6::doubly_linked_list selection_sort(lab6::doubly_linked_list input, int iterations);
    lab6::doubly_linked_list bubble_sort(lab6::doubly_linked_list input, int iterations);
    lab6::doubly_linked_list cocktail_sort(lab6::doubly_linked_list input, int iterations);

    lab6::doubly_linked_list quick_sort(lab6::doubly_linked_list input);
    lab6::doubly_linked_list merge_sort(lab6::doubly_linked_list input);
    lab6::doubly_linked_list radix_sort(lab6::doubly_linked_list input);

    int partition (lab6::doubly_linked_list &obj, int low, int high);

    lab6::doubly_linked_list quickSort(lab6::doubly_linked_list &obj, int low, int high);
    void BottomUpMerge(lab6::doubly_linked_list &A, int iLeft, int iRight, int iEnd, lab6::doubly_linked_list &B);
    lab6::doubly_linked_list merge(lab6::doubly_linked_list left, lab6::doubly_linked_list right);
    void Merge(lab6::doubly_linked_list &obj, int l, int m, int r);
    lab6::doubly_linked_list mergeSort(lab6::doubly_linked_list &obj, int l, int r);

    lab6::doubly_linked_list radixsort(lab6::doubly_linked_list &obj, int n);
    int max(lab6::doubly_linked_list &obj, int n);
    void sort_count(lab6::doubly_linked_list &obj, int n, int exp);

    lab6::doubly_linked_list Merge2(lab6::doubly_linked_list &obj,int beg, int end);

};

#endif //CMPE126F17_LABS_SORTS_H
