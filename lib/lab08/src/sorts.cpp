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

//    if (iterations == 0) //handles 0 iteration case
//    {
//        return working_list;
//    }
//    if (iterations > working_list.get_size() - 1) // handles case for where iterations will pass the linked list
//    {
//        iterations = working_list.get_size() - 1;
//    }
//    for (int i = 1; i <= iterations; i++) //general case
//    {
//        for (int j = i; j > 0; j--) {
//            if (working_list.get_data(j) < working_list.get_data(j - 1)) {
//                //working_list.swap(j, j - 1);
//            } else {
//                break;
//            }
//        }
//    }

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

//    if (iterations == 0)
//        return working_list;
//    else {
//        for (int k = 0; k < iterations; k++) {
//            int length = working_list.get_size();
//            for (int i = 0; i < length - 1; i++) {
//                int iMin = working_list.get_data(i);
//                for (int j = i + 1; j < length; j++) {
//                    if (working_list.get_data(j) < working_list.get_data(iMin)) {
//                        iMin = working_list.get_data(j);
//                    }
//                }
//                working_list.swap(i, iMin);
//            }
//            return working_list;
//        }
//    }


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