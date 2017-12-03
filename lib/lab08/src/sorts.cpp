#include "sorts.h"
#include "doubly_linked_list.h"

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list(input); //sets equal the incoming doubly linked list
    int j, i;
    int m;

    if (iterations == 0) //handles 0 iteration case
    {
        return working_list;
    }
    if (iterations > working_list.get_size() - 1) // handles case for where iterations will pass the linked list
    {
        iterations = working_list.get_size() - 1;
    }
    for(int i=1; i<=iterations; i++){
        //j=i;
        for(int j= i; j>0; j--) {
                if (working_list.get_data(j) < working_list.get_data(j-1)) {
                    working_list.swap_data(j,j-1);
                }
                else{
                    break;
                }
        }
    }

    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list(input);
    int min, min_index;
    unsigned size = working_list.get_size();

    if(iterations>size){
        iterations = size-1;
    }
        for (int i = 0; i < iterations; i++) {
            min = working_list.get_data(i);
            min_index = i;
            for (int j = i+1; j < size; j++) {
                if (working_list.get_data(j) < min) {
                    min = working_list.get_data(j);
                    min_index = j;
                }
            }
            if (min_index != i)
            {
            working_list.swap_data(i, min_index); //swap with the node at the front
            }
        }

        return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    unsigned size = working_list.get_size();

    for(int i=0; i<iterations; i++){
        for(int j=0; j<size-1; j++){
            if(working_list.get_data(j) > working_list.get_data(j+1)) {
                working_list.swap_data(j, j + 1);
            }
        }
    }

    /*for (int i = 0; i < iterations - 1; i++){
        for (int j = 0; j < size - i - 1; j++) {
            if (working_list.get_data(j) > working_list.get_data(j + 1)) {
                working_list.swap_data(working_list.get_data(j), working_list.get_data(j + 1));
            }
        }
    }*/

    return working_list;
}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    return working_list;
}

lab6::doubly_linked_list sorts::quick_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}