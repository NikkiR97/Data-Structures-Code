#include "node.h"
#include <iostream>

namespace lab4 {
// Take in value and create a node
    node::node(int input) {
        next = nullptr; //pointing to the next node
        data = input; //data goes into the first node
    }

// Takes in an array of values and creates the appropriate nodes
    node::node(int values[], int length) {
//        next = nullptr;
//        data = values[0];
//
//        node *temp = next;
//
//        for(int i=1; i<length; i++){
//            temp = new node(values[i]);
//            temp = temp->next;
//        }

        node* temp = this;
        node* prev = temp;
        temp->data = values[0];
        temp->next = nullptr;

        for(int i=1; i<length; i++){
            temp->next = new node(values[i]);
            temp = temp->next;
        }
    }

// Default destructor
    node::~node() {
        //delete next;
        // Hint: You don't want to just delete the current node. You need to keep track of what is next
    }

// Add a value to the end node
    void node::append(int input) {
        node *temp;
        temp = this;
        if(temp == nullptr){
         temp = new node(input);
        }
        else {
            while (temp->next != nullptr) {
                temp = temp->next; //temp will equal wherever next is now pointing to
            }
            temp->next = new node(input); //temp will point to where the 'next' of the newly created node will point to
        }
    }

// Add an array of values to the end as separate nodes
    void node::append(int inputs[], int length) {
        node *temp;
        temp = this;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        for (int i = 0; i < length; i++) {
            temp->next = new node(inputs[i]);
            temp = temp->next;
        }

        //temp->next = new node(inputs, length);
    }

// Insert a new node after the given location
    node *node::insert(int location, int value) {
        node *temp;
        node *newnode = new node(value);
        int temploc = 0;

        temp=this;

        if (this != nullptr) {
            while (temp != nullptr && temploc++ != location) {
               // prev = temp;
                temp = temp->next;
            }
            if(temp) {
                newnode -> next = temp->next;
                temp->next = newnode;
            }
        } else {
            temp = new node(value);
        }

        return this; //to make sure the head pointer is not left floating then we just return 'this'
    }

// Remove a node and link the next node to the previous node
    node *node::remove(int location) {
        node *temp;
        node *prev;
        int temploc = 0;
        temp = this;

        int checker = 0;

        if (this != nullptr) {

            while (temp->next != nullptr && temploc++ != location) {
                prev = temp;
                temp = temp->next;

                checker = 1;
            }
            if(temp != this) {
                //if (temp->next != nullptr) {
                //temp points to the next (which is pointing to the following node)
                prev->next = temp->next; //prev now points to the old node at location
                //temp->next = new node(value); //a new node is added at location and temp is changed to point whereever next is pointing to
                temp->next = prev->next; //next is now reasigned to point to the node that used to be at that location
                //}
                delete temp;
            }
            else if(temp->next = nullptr){
                prev->next = nullptr;
                delete temp;
            }
            else{ // the node to remove is at head
                //swap the data, then remove the next node
                if(temp->next) {
                    temp->data = temp->next->data;
                    prev = temp;
                    temp = temp->next;
                    prev->next = temp->next;
                    delete temp;
                    checker=1;
                }
            }
        }

        if (checker == 0) {
            std::cout << "There are no nodes to remove." << std::endl;
        }

        return this;
    }

// Print all nodes
    void node::print() {
        node *temp = this;

        int checker = 0;
        while (temp != nullptr) { //-> next
            std::cout << temp->data << " " << "->" << " ";
            temp = temp->next;
            checker = 1;
        }
        std::cout << "null";
        if (checker != 1) {
            std::cout << "There are no nodes to print the contents of." << std::endl;
        }
    }

//Print the middle node
    void node::print_middle() {
        node *r1 = this;
        node *r2 = this;

        int checker = 0;

        if(r1){
            checker=1;
        }

            while (r2->next != nullptr) {
                if (r2->next->next == nullptr) {//even number length for linked list
                    r2 = r2->next;
                } else { //odd number length for linked list
                    r1 = r1->next;
                    r2 = r2->next->next;
                }
                checker = 1;
            }

        if (checker == 1) {
            std::cout << r1->data;
        } else {
            std::cout << "There are no nodes to find a middle from." << std::endl;
        }
        // HINT: Use a runner to traverse through the linked list at two different rates, 1 node per step
        //       and two nodes per step. When the faster one reaches the end, the slow one should be
        //       pointing to the middle

    }

// Get the value of a given node
    int node::get_value(int location) {
        node *temp = this;
        int temploc = 0;
        int recValue = 0;

        while (temp->next != nullptr && temploc++ != location) {
            temp = temp->next;
        }
        recValue = temp->data;

        return recValue; //if there are no contents due to no nodes, a value of zero will be returned.
    }

// Overwrite the value of a given node
    void node::set_data(int location, int value) {
        node *temp = this;
        int temploc = 0;
        int recValue;

        int checker = 0;

        while (temp != nullptr && temploc++ != location) {
            temp = temp->next;
            checker = 1;
        }

        if (checker == 1) {
            temp->data = value;
        } else {
            std::cout << "There is no node at the given location, so a value cannot be set." << std::endl;
        }
    }
}