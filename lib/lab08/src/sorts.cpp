#include "sorts.h"

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input; //sets equal the incoming doubly linked list
    int j, i, key;

    for(int i=1; i<iterations; i++){
        key = working_list.get_data(i);
        j=i-1;
        while(j>=0 && working_list.get_data(j) > key){
            working_list.swap(j, j+1);//working_list.get_data(j);
            j=j-1;
        }
        working_list.setter(j+1,key);
    }

    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    int min;

    for(int i=0; i<iterations-1; i++){
        min = i;
        for(int j=0; j<iterations; j++) {
            if(working_list.get_data(j) < working_list.get_data(i)){
                min=j;
            }
        }
        working_list.swap(i,min);
    }
    return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
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