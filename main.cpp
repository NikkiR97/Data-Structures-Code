#include "lib/lab06/inc/deck.h"
#include "lib/lab07/inc/tree.h"
#include "lib/lab07/src/tree.cpp"
#include <iostream>
#include <vector>


int main() {
    //deck newdeck;

    std::vector <unsigned> val(10);
    val = {1,2,3,4,5,6,7,8,9,10};
//   doubly_linked_list a(val);
//   a.swap_set(2,4,6,8);
//   a.print();

    std::vector <unsigned> val2(5);
    val2 = {1,2,3,4,5,};

    std::vector <unsigned> val3(5);
    val3 = {1,2,3};


//    std::cout <<"The current list1:" <<std::endl;
//    doubly_linked_list list1(val2);
//    list1.print();
//
//    std::cout <<"The current list2:" <<std::endl;
//    doubly_linked_list list2(val3);
//    list2.print();
//
//    std::cout <<"List2 = List1" <<std::endl;
//    list2=list1;
//    list2.print();


    std::cout <<"The current list:" <<std::endl;
    lab6::doubly_linked_list obj(val);
    obj.print();

    std::cout <<"Inserted zero before position 1:" <<std::endl;
    obj.insert_before(1,0);
    obj.print();

    std::cout <<"Inserted zero after position 3:" <<std::endl;
    obj.insert_after(3,0);
    obj.print();

    std::cout <<"Removed node at position 2:" <<std::endl;
    obj.remove(2);
    obj.print();

    std::cout<<std::endl;

    std::cout <<"New copied list (obj2):" <<std::endl;
    lab6::doubly_linked_list obj2(obj);
    obj2.print();

    std::cout <<"Merged two lists (obj1):" <<std::endl;
    obj.merge(obj2);
    obj.print();

    std::cout <<"0 appended to end of obj1:" <<std::endl;
    obj.append(0);
    obj.print();

    std::cout <<"Nodes at position 4 and 7 are swapped for obj1:" <<std::endl;
    obj.swap(4,7);
    obj.print();

    std::cout <<"Sets 2-5 and 8-10 are swapped for obj1:" <<std::endl;
    obj.swap_set(2,5,8,10);
    obj.print();

    std::cout <<"Splitting obj1 before position 10, new object(3):" << std::endl;
    lab6::doubly_linked_list obj3(obj.split_before(10));
    obj3.print();

    std::cout <<"Current obj1:" << std::endl;
    obj.print();

    std::cout <<"Splitting obj1 after position 5, new object(4):" << std::endl;
    lab6::doubly_linked_list obj4(obj.split_after(5));
    obj4.print();

    std::cout <<"Current obj1, again:" << std::endl;
    obj.print();

    std::cout <<"Splitting obj3 between pos 3 and 6, new object(5)" <<std::endl;
    lab6::doubly_linked_list obj5(obj3.split_set(3,6));
    obj5.print();

    std::cout <<"New object (6) created with equal operator to obj1." <<std::endl;
    lab6::doubly_linked_list obj6 = obj;
    obj6.print();

    std::cout <<"Obj6 is merged with obj3 to create a new object(7)." <<std::endl;
    lab6::doubly_linked_list obj7 = obj6 + obj3; //has an issue
    obj7.print();

    std::cout <<"Obj4 is appended unto Obj7." <<std::endl;
    obj7 += obj4;
    obj7.print();

    std::cout<<"Overwriting the obj1 with obj7, New obj 1:" << std::endl;
    obj = obj7;
    obj.print();

    std::cout << std::endl;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~lab 7~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<< std::endl;
   lab7::tree object;

    std::cout << "In this program, a tree will be created from a list of numbers: 8, 10, 5, 3, 14. " << std::endl;
    object.insert(8);
    object.insert(10);
    object.insert(5);
    object.insert(3);
    object.insert(14);
    object.insert(5);
    object.insert(3);

    object.print();

    object.remove(5); //will remove the node itself and all instances of 5 will disappear
    std::cout<<std::endl;
    object.print();

  //   object.remove(10);
  //   std::cout<<std::endl;
  //   object.print();

   //if(object.in_tree(14)){
   //    std::cout << "14 exists in the tree. " << std::endl;
   //}

    std::cout << std::endl;
    std::cout << "This is the size of the tree: " << object.size() << std::endl;
    std::cout << "Frequency of 5 is: " << object.get_frequency(5) << std::endl;
    std::cout << "The level of 14 in the tree is: " << object.level(14) << std::endl;
    std::cout << "The the largest depth (longest path) in the tree is: " << object.depth() << std::endl;
    std::cout << "This is the path to the key (10): ";
    object.path_to(10);
    std::cout << std::endl;

    return 0;
}