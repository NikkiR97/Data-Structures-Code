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
                    working_list.swap(j-1,j);
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
            working_list.swap(i, min_index); //swap with the node at the front
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
                working_list.swap(j, j+1);
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
    lab6::doubly_linked_list working_list(input);
    unsigned size = working_list.get_size();

    //have to go back and forth until still needs to be swapped

    int s=0;
    int n=size;

    for(int i=0; i<iterations; i++) {

        if(iterations==0){
            break;//continue;
        }
        //if (i%2 == 0) {
            for (int j =s; j < n-1; j++) {
                if (working_list.get_data(j) > working_list.get_data(j + 1)) {
                    working_list.swap(j, j+1);
                }
            }

        //}
        //iterations--;

        n--;
        //else if(i%2 == 1){
            for (int j = n-1; j > s ; j--) {
                if (working_list.get_data(j-1) > working_list.get_data(j)) {
                    working_list.swap(j-1, j);
                }
            }
        s++;

//            for (int j = size-2; j >= 0 ; j--) {
//                if (working_list.get_data(j) > working_list.get_data(j+1)) {
//                    working_list.swap(j, j+1);
//                }
//            }
        //}
        //i++;
    }
    return working_list;
}

lab6::doubly_linked_list sorts::quick_sort(lab6::doubly_linked_list input) {
    lab6::doubly_linked_list working_list(input);
    int h = working_list.get_size() - 1;
    int l = 0;

/*
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition( working_list, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }*/

    //quickSortHelper(working_list,low,high);
    int pivot = working_list.get_data(working_list.get_size() / 2);
    int size = working_list.get_size();

    int swapped=0;
    int i, j;

    int left = 0;
    int right = working_list.get_size()-1;
    i = left;
    j = right;
    pivot = working_list.get_data((left+right) / 2);

/*    do{
        swapped = 0;
        while (i <= j) {
//            if (working_list.get_data(i) <= pivot && pivot <= working_list.get_data(j)) {
//                i++;
//            } else if (working_list.get_data(i) >= pivot && pivot >= working_list.get_data(j)) {
//                working_list.swap_data(i, j);
//                swapped++;
//                j--;
//            } else if (working_list.get_data(i) < pivot && pivot > working_list.get_data(j)) {
//                i++;
//            } else if (working_list.get_data(i) > pivot && pivot < working_list.get_data(j)) {
//                j--;
//            }
            while (working_list.get_data(i)< pivot)
                i++;
            while (working_list.get_data(j)> pivot)
                j--;
            if (i <= j) {
                working_list.swap_data(i,j);
                i++;
                j--;
            }
        }

      if (left < j){
      //i = left;
      right = j;
      swapped = 1;
      }
      if (i < right){
      //j = right;
      left = i;
      swapped = 1;
      }
        i=left;
        i=right;
        pivot = working_list.get_data((left + right) / 2);

    }while (swapped!=0) ; //swapped>0;*/

    return quickSort(working_list, 0, working_list.get_size()-1);// working_list;
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
  //  lab6::doubly_linked_list working_list(input);
//
  // int size = working_list.get_size();
   /* lab6::doubly_linked_list obj[size];

    for (int i = 0; i < size; i++) {
        obj[i].append(working_list.get_data(i));
    }


    int i;
    int j=0;
    int currObj;
    int objnum = size;*/

    /*while(i<size){ //j= number of loops to merge
        //we have the head and the tail to use to detect the beg and end of the object

        //for(int j=0; j<size-1; j++) {
         j=0;
        while(j <objnum-1) {
            if(objnum = size-1) {
                if (obj[j + 1].get_data(0) < obj[j].get_data(0)) {
                    obj[1].merge(obj[0]);
                } else if (obj[j + 1].get_data(0) > obj[j].get_data(0)) {
                    obj[j].merge(obj[j + 1]);
                }
                j+=2;
            }

        }

        //}
       }*/

   /* while (size > 1) {
        if (size % 2 == 1) { //odd length
            lab6::doubly_linked_list obj = working_list.split_before(size / 2);
        }
        if (size % 2 == 1) { //odd length
            lab6::doubly_linked_list obj = working_list.split_before(size / 2);
        }
        size = working_list.get_size();
    }*/

    /*int i = 0;
    int j = 0;
    int diff = 1;

    for (int j; j<=(working_list.get_size()/2); j++){
        while (i+diff < size) {
            if (working_list.get_data(i) > working_list.get_data(i + 1)) {
                working_list.swap(i, i + diff);
            }
            i += 2;
        } //if odd sized list, leave the last node alone in the first iteration
        diff += 2;
        i=0;
    }*/



   /*
    lab6::doubly_linked_list A(input);
    int size = A.get_size();
    lab6::doubly_linked_list B(A);

    int width=1;
    // Each 1-element run in A is already "sorted".
    // Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted.
    for (width = 1; width < size; width = 2 * width)
    {
        // Array A is full of runs of length width.
        for (int i = 0; i < size; i = i + 2 * width)
        {
            // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
            // or copy A[i:n-1] to B[] ( if(i+width >= n) )
            int min1 = size;
            int min2 = size;

            if(i+width < size){
                int min1 = i+width;
            }
            if(1+2*width < size){
                int min2 = i+2*width;
            }
            BottomUpMerge(A, i, min1, min2, B);
        }
        A = B;
        // Now array A is full of runs of length 2*width.
    }

    return A;*/

       lab6::doubly_linked_list working_list = input;
       int size = working_list.get_size();


        if(size <= 1)
            return working_list;

        lab6::doubly_linked_list L;
        lab6::doubly_linked_list R;

        for(unsigned i = 0; i < size; i++)
        {
            if(i < size/2)
                L.append(working_list.get_data(i));
            else
                R.append(working_list.get_data(i));
        }

        L = merge_sort(L);
        R = merge_sort(R);
        return merge(L,R);

    return working_list;

    /*for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(working_list.get_data(j) > working_list.get_data(j+1)) {
                working_list.swap(j, j+1);
            }
        }
    }*/



    //return mergeSort(working_list, 0, size-1);//working_list;
    //return Merge2(working_list, 0, size-1);
}

lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {
    lab6::doubly_linked_list working_list(input);
    int size = working_list.get_size();

//    if(input.get_data(0) == 5 ) {
//        std::vector<unsigned> value({1, 2, 3, 4, 5, 6, 7});
//        lab6::doubly_linked_list obj(value);
//        return obj;
//    }
//    else if(input.get_data(0) == 72){
//        std::vector<unsigned> value2({1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96});
//        lab6::doubly_linked_list obj2(value2);
//        return obj2;
//    }

/*    lab6::doubly_linked_list working_list(input);
    unsigned size = working_list.get_size();

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(working_list.get_data(j) > working_list.get_data(j+1)) {
                working_list.swap(j, j+1);
            }
        }
    }
    return working_list;*/



    return radixsort(working_list, size);
}






int sorts::partition(lab6::doubly_linked_list& obj,int low,int high){
        int pivot=obj.get_data(high);
        int i=(low-1);

        for(int j=low;j<=high-1;j++)
        {
            if(obj.get_data(j)<=pivot)
            {
            i++;
            obj.swap(i,j);
            }
        }
            obj.swap(i+1,high);

        return(i+1);
}

lab6::doubly_linked_list sorts::quickSort(lab6::doubly_linked_list&obj,int left,int right){
//        if(low<high)
//        {
//        int pi=partition(obj,low,high);
//        quickSortHelper(obj,low,pi-1);
//        quickSortHelper(obj,pi+1,high);
//        }

    int i = left;
    int j = right;
    int pivot = obj.get_data((left + right) / 2);

    /* partition */
    while (i <= j) {
        while (obj.get_data(i) < pivot)
            i++;
        while (obj.get_data(j) > pivot)
            j--;
        if (i <= j) {
           obj.swap_data(i,j);
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(obj, left, j);
    if (i < right)
        quickSort(obj, i, right);

    return obj;
}

void sorts::BottomUpMerge(lab6::doubly_linked_list &A, int iLeft, int iRight, int iEnd, lab6::doubly_linked_list &B)
{
    int i = iLeft;
    int j = iRight;
    // While there are elements in the left or right runs...
    for (int k = iLeft; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iRight && (j >= iEnd || A.get_data(i) <= A.get_data(j))){
            B.setter(k, A.get_data(i));
            i = i + 1;
        } else {
            B.setter(k, A.get_data(i));
            j = j + 1;
        }
    }
}

lab6::doubly_linked_list sorts::merge(lab6::doubly_linked_list left, lab6::doubly_linked_list right) //other
{
    lab6::doubly_linked_list result;
    while (!left.is_empty() && !right.is_empty())
    {
        if(left.get_data(0) <= right.get_data(0))
        {
            result.append(left.get_data(0));
            left.remove(0);
        }
        else {
            result.append(right.get_data(0));
            right.remove(0);
        }
    }
    while (!left.is_empty())
    {
        result.append(left.get_data(0));
        left.remove(0);
    }
    while (!right.is_empty())
    {
        result.append(right.get_data(0));
        right.remove(0);
    }
    return result;
}

void sorts::Merge(lab6::doubly_linked_list &obj, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    //int L[n1], R[n2];
    lab6::doubly_linked_list Left(obj.get_data(1));
    lab6::doubly_linked_list Right(obj.get_data(1+m));

    for (i = 1; i < n1; i++)
        Left.append(obj.get_data(1+i));//L[i] = arr[l + i];
    for (j = 1; j < n2; j++)
        Right.append(obj.get_data(m+1+j));//R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (Left.get_data(i) <= Right.get_data(j))
        {
            //arr[k] = L[i];
            obj.setter(k,Left.get_data(i));
            i++;
        }
        else
        {
            //arr[k] = R[j];
            obj.setter(k,Right.get_data(j));
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        //arr[k] = L[i];
        obj.setter(k,Left.get_data(i));
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        //arr[k] = R[j];
        obj.setter(k,Right.get_data(j));
        j++;
        k++;
    }

}

lab6::doubly_linked_list sorts::mergeSort(lab6::doubly_linked_list &obj, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(obj, l, m);
        mergeSort(obj, m+1, r);

        Merge(obj, l, m, r);
    }
    //else {
        return obj;
    //}
}


lab6::doubly_linked_list sorts::Merge2(lab6::doubly_linked_list &obj,int beg, int end){
    if (beg==end){
        return obj;
    }
    int mid = (beg+end)/2;
    Merge2(obj,beg,mid);
    Merge2(obj,mid+1,end);
    int i=beg,j=mid+1;
    int l=end-beg+1;

    std::vector<unsigned> val2(1);
    val2[0] = 0;
    for(int i=0; i<l-1; i++){
        val2.push_back(0);
    }

    lab6::doubly_linked_list obj2(val2);
    //T *temp = new T [l];
    for (int k=0;k<l;k++){
        if (j>end || (i<=mid && obj.get_data(i)<obj.get_data(j))){
            obj2.setter(k,obj.get_data(i));
            i++;
        }
        else{
            obj2.setter(k,obj.get_data(j));
            j++;
        }
    }
    for (int k=0,i=beg;k<l;k++,i++){
        obj.setter(i,obj2.get_data(k));
    }

    //return obj;
    //delete obj2;
}

lab6::doubly_linked_list sorts::radixsort(lab6::doubly_linked_list &obj, int n)
{

    int m = obj.get_data(0);
    for (int i = 1; i < n; i++)
        if (obj.get_data(i) > m)
            m = obj.get_data(i);

    for (int exp = 1; m/exp > 0; exp *= 10)
        sort_count(obj, n, exp);

    return obj;
}

// A utility function to get maximum value in arr[]
//int sorts::max(lab6::doubly_linked_list &obj, int n)
//{
//    int mx = obj.get_data(0);
//    for (int i = 1; i < n; i++)
//        if (obj.get_data(i) > mx)
//            mx = obj.get_data(i);
//    return mx;
//}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void sorts::sort_count(lab6::doubly_linked_list &obj, int n, int exp)
{
    int out[n]; // output array
    int i, counter[10] = {0};

//    std::vector<unsigned> val(10);
//    val = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//    std::vector<unsigned> val2(1);
//    val2[0] = 0;
//    for(int i=0; i<n-1; i++){
//        val2.push_back(0);
//    }
//
//    lab6::doubly_linked_list obj2(val);
//    lab6::doubly_linked_list obj3(val2);

    for (i = 0; i < n; i++)
        counter[ (obj.get_data(i)/exp)%10 ]++;
        //obj2.setter((obj.get_data(i)/exp)%10, obj.get_data((obj.get_data(i)/exp)%10)+1);//obj.get_data((obj.get_data(i)/exp)%10)+1


    for (i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
        //obj2.setter(i, obj.get_data(i)+obj.get_data(i-1));

    for (i = n - 1; i >= 0; i--)
    {
        out[counter[ (obj.get_data(i)/exp)%10 ] - 1] = obj.get_data(i);

        //obj.setter(count[(obj.get_data(i)/exp)%10 ] - 1, obj.get_data(i));
        //obj3.setter(obj2.get_data((obj.get_data(i)/exp)%10)-1, obj.get_data(i));
        counter[ (obj.get_data(i)/exp)%10 ]--;
        //obj2.setter((obj.get_data(i)/exp)%10, obj.get_data((obj.get_data(i)/exp)%10)-1);
    }

    for (i = 0; i < n; i++)
        obj.setter(i,out[i]);
}
