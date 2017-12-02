//
// Created by Bryan on 9/29/2017.
//

#include "stack.h"
#include <iostream>

namespace lab5{

stack::stack():head(nullptr), size(0) {}

stack::stack(std::string &data) {
    head = new node(data);
    size =1;
}

stack::stack(const stack &original) {
    if (original.head!= nullptr) {
        node *original_tmp = original.head;
        node *tmp = head = new node(original_tmp->data);

        original_tmp = original_tmp->next;
        while (original_tmp != nullptr) {
            tmp->next = new node(original_tmp->data);
            tmp = tmp->next;
            original_tmp = original_tmp->next;
        }
    }
}

stack::~stack() {
    //step 1 create destructor similar to linked list
    for(node*current=head, *next; current!= nullptr ; current=next )
    {
        next=current->next;
        delete current;
    }
}

stack &stack::operator=(const stack &RHS) {

    if(this != &RHS)
    {
        if (head!= nullptr)
            delete this;
        if (RHS.head!= nullptr) {

            node *RHS_tmp = RHS.head;
            node *tmp = head = new node(RHS_tmp->data);

            RHS_tmp = RHS_tmp->next;
            while (RHS_tmp != nullptr) {
                tmp->next=new node(RHS_tmp->data);
                tmp=tmp->next;
                RHS_tmp = RHS_tmp->next;
            }
        }
    }
    return *this;
}

bool stack::isEmpty() const {
    return size==0;
}

unsigned int stack::stackSize() const {
    return size;
}

std::string stack::top() const {
    //step 1 Write this function to return the data from the top node on the stack
    return head -> data;
}

void stack::push(std::string &data) {
    if(head != nullptr) {

        //step 1 store address of current top node (pointed to by head) in a node*
        node *temp;
        temp = head;

        //step 2 create a new node with the incoming data variable, storing the address of this node in head pointer
        node *newnode = new node(data);
        head = newnode;

        //step 3 update new nodes next pointer with the address stored in step 1
        newnode->next = temp;

        //step 4 update size of stack variable
        size++;
        // make sure to check if head is pointing to something
    }
    else{
        head = new node(data);
        size++;
    }
}

void stack::pop() {
    if(head != nullptr) {
        //step 1 store address of current top node (pointed to by head) in a node*
        node *temp;
        temp = head;

        //step 2 update head with address of second node
        head = head->next;

        //step 3 delete node pointed to by address stored in step 1
        delete temp;

        //step 4 update size of stack variable
        size--;

        // make sure to check if head is pointing to something
    }
}

void stack::printstack(){
    node *temp = head ;

    int checker=0;

    while(temp != nullptr){ //-> next
        std::cout << temp -> data << " ";
        temp = temp ->next;
        checker=1;
    }
    std::cout << std::endl;
    if(checker != 1) {
        std::cout << "There are no nodes to print the contents of." << std::endl;
    }
}

node* stack::returnHead(){
    return head;
}

}