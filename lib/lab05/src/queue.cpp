//
// Created by Bryan on 9/30/2017.
//

#include "queue.h"
#include <iostream>

namespace lab5{

queue::queue() :head(nullptr),tail(nullptr),size(0){}

queue::queue(std::string &data) {
    head=tail=new node(data);
    size=1;
}

queue::queue(const queue &original) {
    if (original.head!= nullptr) {
        node *original_tmp = original.head;
        node *tmp = head = new node(original_tmp->data);

        original_tmp = original_tmp->next;
        while (original_tmp != nullptr) {
            tmp->next = new node(original_tmp->data);
            tmp = tmp->next;
            tail=tmp;
            original_tmp = original_tmp->next;
        }
    }
}

queue::~queue() {
    //step 1 create destructor similar to linked list
    for(node*current=head, *next; current!= nullptr ; current=next )
    {
        next=current->next;
        delete current;
    }
}

queue &queue::operator=(const queue &RHS) {
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
                tail=tmp;
                RHS_tmp = RHS_tmp->next;
            }
        }
    }
    return *this;
}

bool queue::isEmpty() const {
    return size==0;
}

unsigned queue::queueSize() const {
    return size;
}

std::string queue::top() const {
    //step 1 return top item of queue
    return head -> data;
}

void queue::enqueue(std::string &data) {
    //head and tail can be pointing to nothing
    if (head == nullptr || tail == nullptr) {
        head = tail = new node(data);
    } else {
        //step 1 create a new node
        node *temp = new node(data); //temp is pointing to the address of the new node

        //step 2 update next of node pointed to by tail with address of new node
        tail->next = temp; //next will point to whatever address the temp is pointing

        //step 3 update tail with address of new node
        tail = temp;

        //step 4 update size of stack variable
        size++;

        // make sure to check if head is pointing to something

        //if (head->next != nullptr) {
        //head = head->next;
        //}
    }
}

void queue::dequeue() {
    //step 1 store address of current top node (pointed to by head) in a node*
    if (head != nullptr || tail != nullptr) {

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

void queue::printqueue(){
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

node* queue::returnHead(){
    return head;
}

}