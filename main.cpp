#include "lib/lab06/inc/deck.h"

int main() {
    //deck newdeck;

    std::vector <unsigned> val(10);
    val = {1,2,3,4,5,6,7,8,9,10};
   // doubly_linked_list a(val);
   // a.swap_set(2,4,6,8);
   // a.print();

    std::cout <<"The current list:" <<std::endl;
    doubly_linked_list obj(val);
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
    doubly_linked_list obj2(obj);
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

    std::cout <<"Sets 8-10 and 15-17 are swapped for obj1:" <<std::endl;
    obj.swap_set(8,10,15,17);
    obj.print();

    std::cout <<"Splitting obj1 before position 10, new object(3):" << std::endl;
    doubly_linked_list obj3(obj.split_before(10));
    obj3.print();

    std::cout <<"Current obj1:" << std::endl;
    obj.print();

    std::cout <<"Splitting obj1 after position 5, new object(4):" << std::endl;
    doubly_linked_list obj4(obj.split_after(5));
    obj4.print();

    std::cout <<"Current obj1, again:" << std::endl;
    obj.print();

    std::cout <<"Splitting obj3 between pos 3 and 6, new object(5)" <<std::endl;
    doubly_linked_list obj5(obj3.split_set(3,6));
    obj5.print();

    std::cout <<"New object (6) created with equal operator to obj1." <<std::endl;
    doubly_linked_list obj6 = obj;
    obj6.print();

    std::cout <<"Obj6 is merged with obj3 to create a new object(7)." <<std::endl;
    doubly_linked_list obj7 = obj6 + obj3; //has an issue
    obj7.print();

    std::cout <<"Obj4 is appended unto Obj7." <<std::endl;
    obj7 += obj4; //has an issue
    obj7.print();

    return 0;
}