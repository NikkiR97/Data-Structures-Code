#include "../inc/doubly_linked_list.h"
#include <iostream>
/*
 * You will be writing all of the code for each of these functions.
 * Remember, this is a doubly linked list, not an array. You need to
 * be using pointers, and not overwriting your values like you would
 * in an array.
 *
 * If you need to write auxiliary functions, you are more than welcome
 * to, but you can't change the signature of any of the functions we
 * have written.
 *
 * Information on doubly linked lists can be found at
 * https://en.wikipedia.org/wiki/Doubly_linked_list
 *
 * Hints: - Keep track of size. If you add or delete something, you
 *          need to change size.
 *        - This isn't an array, so moving things around is actually
 *          a lot easier. Just change the pointers to the objects.
 *        - Keep track of your edge cases; empty, 1 item, and 2 items
 *        - Some of these functions are basically the same thing,
 *          with the index shifted or return ignored. Don't rewrite
 *          code, just call the function with the 'correct' inputs.
 *        - Test your doubly linked list by itself before testing it
 *          in the deck class. It will make it easier to find any bugs
 *        - Use your debugger. It is your best friend for finding
 *          issues!
 *        - Don't forget to ask for help on Slack!
 *
 * We will be making changes throughout the week to the deck.cpp as
 * well as adding testing into the project. Make sure to pull and
 * merge frequently.
 */

namespace lab6 {
// Default constructor
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

// Take in a vector of inputs and construct a doubly linked list from them
    doubly_linked_list::doubly_linked_list(std::vector<unsigned> values) {
//std::vector <int> obj(10);
        int length = values.size();
        size = length;

        node *temp = head;
        node *before = head;

        head = new node(values[0]);
        //temp->prev = nullptr; //already set to nullptr

        temp = head;

        for (int i = 1; i < length; i++) {
            before = temp;
            temp->next = new node(values[i]);
            temp = temp->next;
            temp->prev = before;
        }

        tail = temp;
        tail->next = nullptr;
    }

// Copy constructor
    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        node *temp; // the temp of the new doubly object
        node *before;

        size = original.size; //initializing the size variable

        node *temp2 = original.head;

        head = new node(temp2->data); //initializing the head with the first data element

        temp = head; //temp points to where head is pointing to

        temp2 = temp2->next;

        for (int i = 1; i < size; i++) {
            before = temp;
            temp->next = new node(temp2->data); //seg fault
            temp = temp->next;
            temp->prev = before;

            temp2 = temp2->next;
        }

        tail = temp;
        tail->next = nullptr;
    }

// Create doubly linked linked list with one input value
    doubly_linked_list::doubly_linked_list(unsigned input) {
        head = new node(input);
        tail = head;
        size = 1;
    }

// Default destructor
    doubly_linked_list::~doubly_linked_list() {
        /*for(node*current=head,*next; current!=nullptr ; current=next)
        {
            next=current->next;
            delete current;
            size--;
        }*/


//    node *temp;
//    temp = head;
//    while (head != nullptr) {
//        temp = head->next;
//        delete head;
//        head = temp;
//        size--;
//    }

    }

// return the value inside of the node located at position
    unsigned doubly_linked_list::get_data(unsigned position) {
        node *temp = head;
        unsigned temploc = 0;

        while(temp!=nullptr && temploc++ != position){
            temp = temp->next;
        }
//        for (int i = 0; i < position; i++) {
//            temp = temp->next;
//        }
//        temp = temp->next;

        return temp->data;
    }

// Get a set of values between position_from to position_to
    std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        //get all the values and put them into vector
        node *temp = head;

        std::vector<unsigned> set;
        for (int i = 0; i < position_from; i++) {
            temp = temp->next;
        }

        for (int i = position_from; i <= position_to; i++) {
            set.push_back(temp->data);
            temp = temp->next;
        }

        return set;
    }

// Add a value to the end of the list
    void doubly_linked_list::append(unsigned data) {
        node *temp;
        temp = head;

        if (!head) {
            head = new node(data);
            temp = head;
            tail = head;
        } else {
            while (temp->next != nullptr) {
                temp = temp->next; //temp will equal wherever next is now pointing to
            }
            temp->next = new node(data); //temp will point to where the 'next' of the newly created node will point to
            temp->next->prev = temp;
            tail = temp->next;
        }

        size++;
    }

// Merge two lists together in place, placing the input list at the end of this list
    void doubly_linked_list::merge(doubly_linked_list rhs) {
        //the next of the last node or the node pointed to by tail should have its next point to the head of the input list
        //the prev of the first node of the input list or the node pointed to by the head should have its prev point to the tail of the previous list

        tail->next = rhs.head;
        rhs.head->prev = tail;

        tail = rhs.tail;

        size = size + rhs.size;
    }

// Allow for the merging of two lists using the + operator.
    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        doubly_linked_list obj(*this);
        doubly_linked_list obj1(rhs);

        obj.merge(obj1);

        return obj;
//    return ;
    }

// Insert a node before the node located at position
    void doubly_linked_list::insert_before(unsigned position, unsigned data) {
        node *temp;
        node *temp1 = new node(data);
        temp = head;

        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }

        temp1->next = temp;
        temp1->prev = temp->prev;
        temp->prev->next = temp1;
        temp->prev = temp1;

        size++;
    }

// Insert a node after the node located at position
    void doubly_linked_list::insert_after(unsigned position, unsigned data) {
        node *temp;
        node *temp1 = new node(data);
        temp = head;

        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }

        temp1->next = temp->next;
        temp->next->prev = temp1;
        temp->next = temp1;
        temp1->prev = temp;

        size++;
    }

// Remove the node located at position from the linked list
    void doubly_linked_list::remove(unsigned position) {
        if(position!=0) {
            node *temp = head;

            for (int i = 0; i < position; i++) {
                if (temp != nullptr) {
                    temp = temp->next;
                }
            }
            if (!head) { // same as !temp
                std::cout << "No nodes to remove. " << std::endl;
            } else if (temp == head && !(temp->next)) { //there is only one node
                head = nullptr;
                tail = nullptr;
                delete temp;
            } else if (temp == head) {
                temp->next->prev = nullptr;
                delete temp;
            } else if (temp == tail) {
                temp->prev->next = nullptr;
                delete temp;
            }
                /*else if(temp->next == nullptr){
                    temp->prev->next = nullptr;
                    delete temp;
                }
                else if(temp->prev == nullptr){
                    temp->next->prev = nullptr;
                    delete temp;
                }*/

            else if (temp->next != nullptr &&
                     temp->prev != nullptr) { //if there is a node in the front and the back of perspective removed node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            } else if (temp->next == nullptr && temp->prev == nullptr) { //there is only one node
                //temp=tail;
                //tail = temp->prev;
                delete temp;
            }
            size--;
        }
        else{
            node *temp = head ->next;
            delete head;
            head= temp;
            size--;
        }
    }

// Split the list with the node being split on being included in the returned list
    doubly_linked_list doubly_linked_list::split_before(unsigned position) {
        //the node before positiion will have its next point to nullptr
        //the node at the position will have its prev point to nullptr
        node *temp = head;
        node *newtemp;

        /*
        doubly_linked_list obj(temp->data); //initialize a new doubly object using the first element of the current array
        newtemp = obj.head;
        newtemp = newtemp->next;
        temp = temp->next;

        for (int i = 1; i < position; i++) {

           obj.append(temp->data);
//            newtemp = new node(temp->data);
//            newtemp = newtemp->next;
//            obj.size++;

            temp = temp->next;
            size--;
        }
        temp->prev->next = nullptr;
        temp->prev = nullptr;
        head = temp; //correct

        */

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //temp->prev->next = nullptr;
        //temp->prev = nullptr;

        //newtemp = temp;
        //tail = temp;

        /*
        doubly_linked_list obj(newtemp->data);
        obj.head = newtemp;
        newtemp = newtemp->next;

        for (int i = position + 1; i < size; i++) {
            obj.append(newtemp->data);
            newtemp = newtemp->next;
        }

        obj.size = size - position;
        size = position;*/

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        for (int i = 0; i < position; i++) {
            newtemp = temp;
            temp = temp->next;
        }
        tail = temp; //the head of the current object remains the same

        doubly_linked_list obj(temp->data);
        //obj.head = newtemp;
        temp = temp->next;


        for (int i = position + 1; i < size; i++) {
            obj.append(temp->data);
            temp = temp->next;
        }

        newtemp->next->prev = nullptr;
        newtemp->next = nullptr;
        size = position;

        return obj;
//    return ;
    }

// Split the list with the node being split on being included in the retained list
    doubly_linked_list doubly_linked_list::split_after(unsigned position) {
        node *temp = head;
        node *newtemp;

        for (int i = 0; i <= position; i++) {
            newtemp = temp;
            temp = temp->next;
        }
        //move to the node after position

        tail = temp; //the head of the current object remains the same
        doubly_linked_list obj(temp->data);
        //obj.head = newtemp;
        temp = temp->next;

        for (int i = position + 3; i < size; i++) {
            obj.append(temp->data);
            temp = temp->next;
        }

        newtemp->next->prev = nullptr;
        newtemp->next = nullptr;

        //obj.size = size - position - 1;
        size = position+1;

        return obj;
//    return ;
    }

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
    doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {
        //case 1: both from and to exist somewhere within the linked list
        //case 2: both from and to exist at the ends of the linked list
        //case 3: to exists before from
        //case 4: to and from are at the same position

        node *temp = head;
        node *temp1 = head;
        node *temp2 = head;
        doubly_linked_list obj;


        if (position_to - position_from + 1 == size || position_from == position_to || position_to>size) {
            std::cout << "Cannot split list within this range." << std::endl;
        }

        else if (position_from < position_to) {
            //split before position
            for (int i = 0; i < position_from; i++) {
                temp1 = temp; //refers to the node right before position from
                temp = temp->next;
            }

            temp->prev->next = nullptr; //temp1->next=nullptr
            temp->prev = nullptr;

            doubly_linked_list obj(temp->data);
            temp = temp->next;


            for (int i = position_from + 1; i < position_to; i++) {
                obj.append(temp->data);
                temp = temp->next;
            }
            obj.append(temp->data);

            temp2 = temp->next; //temp2 refers to the node after position_to
            //obj.append(temp->data);
            temp->next->prev = nullptr; //temp2->prev=nullptr
            temp->next = nullptr;

            //merging the ends of the list
            obj.tail = temp2;

            temp1->next = temp2;
            temp2->prev = temp1;

            obj.size = (position_to - position_from) + 1;
            size = size - obj.size;

            return obj;
        } else {//'from' to tail and then head to 'to' and then
            for (int i = 0; i < position_from; i++) {
                temp1 = temp1->next;
            }

            doubly_linked_list obj(temp->data);
            temp = temp->next;

            while (temp1 != nullptr) {
                obj.append(temp1->data);
                temp1 = temp1->next;
            }

            for (int i = 0; i <= position_to; i++) {
                obj.append(temp2->data);
                temp2 = temp2->next;
            }

            obj.size = position_to + (size - position_from) + 2;
            size = size - obj.size;

            return obj;
        }

        //return obj;
//    return ;
    }

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
    /*void doubly_linked_list::swap(unsigned position1, unsigned position2) { //orginal swap function
        node *curr = head;
        node *curr2 = head;
        node *mynext, *myprev, *mynext2, *myprev2;

        for (int i = 0; i < position1; i++) {
            if(curr!=nullptr) {
                myprev = curr;
                curr = curr->next;
            }
        }

        mynext = curr->next;

        for (int j = 0; j < position2; j++) {
            if(curr2!=nullptr) {
                myprev2 = curr2;
                curr2 = curr2->next;
            }
        }

        mynext2 = curr2->next;

//        curr->next = mynext2;
//        curr->prev = myprev2;
//        curr2->next = mynext;
//        curr2->prev = myprev;
//
//        myprev->next = curr2;
//        mynext->prev = curr2;
//        myprev2->next = curr;
//        mynext2->prev = curr;


        if(position1== 0 && position2 == size-1){ //both sets are exactly at the beg and the end
            curr->next = nullptr;
            curr->prev = myprev2;
            curr2->next = mynext;
            curr2->prev = nullptr;

            mynext->prev = curr2;
            myprev2->next = curr;

            head = curr2;
            tail = curr;
        }
        else if(position1 == 0){ //first set is at the beg of the list
            curr->next = mynext2;
            curr->prev = myprev2;
            curr2->next = mynext;
            curr2->prev = nullptr;

            mynext->prev = curr2;
            myprev2->next = curr;
            mynext2->prev = curr;

            head = curr2;
        }
        else if(position2 == size-1){ //second set is at the end of the list
            curr->next = nullptr;
            curr->prev = myprev2;
            curr2->next = mynext;
            curr2->prev = myprev;

            myprev->next = curr2;
            mynext->prev = curr2;
            myprev2->next = curr;

            tail = curr;
        }
        else {
            curr->next = mynext2;
            curr->prev = myprev2;
            curr2->next = mynext;
            curr2->prev = myprev;

            myprev->next = curr2;
            mynext->prev = curr2;
            myprev2->next = curr;
            mynext2->prev = curr;
        }
    }*/

   /* void doubly_linked_list::swap(unsigned position1, unsigned position2) {
        node *temp = head;
        node *temp1 = head;
        node *n1;
        for (int i = 0; i < position1; i++) {
            temp = temp->next;
        }
        for (int j = 0; j < position2; j++) {
            temp1 = temp1->next;
        }
        n1->next = temp->next;
        n1->prev = temp->prev;

        temp->prev = temp1->prev;
        temp->next = temp1->next;

        temp1->prev = n1->prev;
        temp1->next = n1->next;

        if (temp->next != nullptr)
            temp->next->prev = temp; // n2;
        if (temp->prev != nullptr)
            temp->prev->next = temp; // n2;
        if (temp1->next != nullptr)
            temp1->next->prev = temp1; // n1;
        if (temp1->prev != nullptr)
            temp1->prev->next = temp1; // n1;
    }*/

    void doubly_linked_list::swap(unsigned position1, unsigned position2) {
        node *temp1 = head;
        node *temp2 = head;
        node *prev1=nullptr;
        node *next1=nullptr;
        node *prev2=nullptr;
        node *next2=nullptr;

        for(int i=0; i<position1; i++) {
            if (temp1 != nullptr) {
                prev1 = temp1;
                temp1 = temp1->next;
            }
        }
        next1 = temp1->next;

        for(int i=0; i<position2; i++){
            if(temp2 != nullptr){
                prev2 = temp2;
                temp2 = temp2->next;
            }
        }
        next2 = temp2->next;


        if(position2 == position1+1){ //temp1 and temp2 are next to each other

            if (position1== 0 && position2 == size-1) { //only two nodes
                temp1->next = nullptr;
                temp1->prev = temp2;

                temp2->next = temp1;
                temp2->prev = nullptr;

                head = temp2;
                tail = temp1;
            }
            else if (position1 == 0){ //first node is at the beginning of the list
                temp1->next = next2;
                temp1->prev = temp2;
                next2->prev = temp1;

                temp2->next = temp1;
                temp2->prev = nullptr;

                head = temp2;
            }
            else if (position2 == size-1) { //second node is at the end of the list
                temp1->next = nullptr;
                temp1->prev = temp2;

                temp2->next = temp1;
                temp2->prev = prev1;
                prev1->next = temp2;

                tail = temp1;
            }
            else {
                temp1->next = next2;
                temp1->prev = temp2;
                next2->prev = temp1;

                temp2->next = temp1;
                temp2->prev = prev1;
                prev1->next = temp2;
            }
        }
        else {
            if(position1== 0 && position2 == size-1){ //both nodes are exactly at the beg and the end
                temp1->next = nullptr;
                temp1->prev = prev2;
                temp2->next = next1;
                temp2->prev = nullptr;

                next1->prev = temp2;
                prev2->next = temp1;

                head = temp2;
                tail = temp1;
            }
            else if(position1 == 0){ //first node is at the beg of the list
                temp1->next = next2;
                temp1->prev = prev2;
                temp2->next = next1;
                temp2->prev = nullptr;

                next1->prev = temp2;
                prev2->next = temp1;
                next2->prev = temp1;

                head = temp2;
            }
            else if(position2 == size-1){ //second node is at the end of the list
                temp1->next = nullptr;
                temp1->prev = prev2;
                temp2->next = next1;
                temp2->prev = prev1;

                prev1->next = temp2;
                next1->prev = temp2;
                prev2->next = temp1;

                tail = temp1;
            }
            else {
                temp1->next = next2;
                temp1->prev = prev2;
                temp2->next = next1;
                temp2->prev = prev1;

                prev1->next = temp2;
                next1->prev = temp2;
                prev2->next = temp1;
                next2->prev = temp1;
            }

        }

    }

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
 /*   void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                      unsigned position2_to) {
        node *temp = head;
        node *mynext, *myprev, *start1, *end1, *mynext2, *myprev2, *start2, *end2;
        int count1, count2;
        count1 = 0;
        count2 = 0;

        while (temp->next != nullptr && count1++ != position1_to) {
            if (count1 == position1_from-1) {
                myprev = temp;
                start1 = temp->next;
            }
            temp = temp->next;
        }
        end1 = temp;
        mynext = end1->next;

//
//        // traversing through the list backwards
//        temp = tail;
//
//        while(temp -> prev != nullptr && count2++ != (size - position2_from)){
//            if(count2 < (size - position2_to)){
//                mynext2 = temp;
//                end2 = temp -> prev;
//            }
//            temp = temp->prev;
//        }
//        start2 = temp;
//        myprev2 = start2 -> prev;
        temp = head;

        while (temp->next != nullptr && count2++ != position2_to) {
            if (count2 == position2_from-1) {
                myprev2 = temp;
                start2 = temp->next;
            }
            temp = temp->next;
        }
        end2 = temp;
        mynext2 = end2->next;

//        end1->next = mynext2;
//        start1->prev = myprev2;
//        end2->next = mynext;
//        start2->prev = myprev;
//
//        myprev->next = start2;
//        mynext->prev = end2;
//        myprev2->next = start1;
//        mynext2->prev = end1;
        if(position1_from == 0 && position2_to == size-1){ //both sets are exactly at the big and the end
            start2->prev = nullptr;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            end1->next = nullptr;
        }
        else if(position1_from == 0){ //first set is at the beg of the list
            start2->prev = nullptr;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            mynext2->prev = end1;
            end1->next = mynext2;
        }
        else if(position2_to == size-1){ //first set is at the end of the list
            myprev->next = start2;
            start2->prev = myprev;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            end1->next = nullptr;
        }
        else {

            myprev->next = start2;
            start2->prev = myprev;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            mynext2->prev = end1;
            end1->next = mynext2;

        }
    }
*/

    void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from, unsigned position2_to) {
        node *temp = head;
        node *mynext=head;
        node *myprev=head;
        node *start1=head;
        node *end1=head;
        node *mynext2=head;
        node *myprev2=head;
        node *start2=head;
        node *end2=head;

        for(int i=0; i<position1_to; i++){
            if(temp->next!=nullptr){
                if(i<=position1_from) {
                    myprev = start1;
                    start1 = temp;
                }
                temp = temp->next;
            }
        }
        end1 = temp;
        mynext = end1->next;

        temp = head;

        for(int i=0; i<position2_to; i++){
            if(temp->next!=nullptr){
                if(i<=position2_from) {
                    myprev2 = start2;
                    start2 = temp;
                }
                temp = temp->next;
            }
        }

        end2 = temp;
        mynext2 = end2->next;

        if(position1_from == 0 && position2_to == size-1){ //both sets are exactly at the beg and the end
            start2->prev = nullptr;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            end1->next = nullptr;

            head = start2;
            tail = end1;
        }
        else if(position1_from == 0){ //first set is at the beg of the list
            start2->prev = nullptr;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            mynext2->prev = end1;
            end1->next = mynext2;

            head = start2;
        }
        else if(position2_to == size-1){ //second set is at the end of the list
            myprev->next = start2;
            start2->prev = myprev;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            end1->next = nullptr;

            tail = end1;
        }
        else {
            myprev->next = start2;
            start2->prev = myprev;
            mynext->prev = end2;
            end2->next = mynext;

            myprev2->next = start1;
            start1->prev = myprev2;
            mynext2->prev = end1;
            end1->next = mynext2;
        }
    }

// Overload operator=
    doubly_linked_list doubly_linked_list::operator=(const doubly_linked_list &RHS) {
//copies the contents of one linked list to another - can only up to length of either linked list
//if there are any excess nodes or are needed of other nodes, then they are either deleted or added

        int minsize = size;
        int maxsize = RHS.size;
        char choice = 'b'; //need to add extra nodes and fill data for those nodes or do nothing

        node *temp = head;
        node *temp1 = RHS.head;

        if (size > RHS.size) {
            minsize = RHS.size;
            maxsize = size;
            choice = 'a'; //need to remove excess nodes
        }

        for (int i = 0; i < minsize; i++) {
            temp->data = temp1->data;
            temp = temp->next;
            temp1 = temp1->next;
        }
//    temp->data = temp1->data;

        if (choice == 'a') { //size is greater
            for (int j = minsize; j < maxsize-1; j++) {
                remove(j);
            }
        } else if (choice == 'b') {//rhs.size is greater
            for (int j = minsize; j < maxsize; j++) {
                append(temp1->data);
                temp1 = temp1->next;
            }
        }

        size = RHS.size;

        return *this;
//    return <#initializer#>;
    }

// Append the rhs to the end of the this list
    doubly_linked_list doubly_linked_list::operator+=(const doubly_linked_list &RHS) {

        /*doubly_linked_list obj(*this);
        node *temp = RHS.head;
        node *temp1 = obj.tail;

        while(temp!=nullptr){
            temp1->next = new node(temp->data);
            temp1->next->prev = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }

        return obj;*/

        /*
        node *temp = RHS.head;

        while(temp!= nullptr){
            append(temp->data);
            temp = temp->next;
        }

        return *this;*/

        doubly_linked_list obj(*this);
        doubly_linked_list obj1(RHS);

        obj.merge(obj1);

        *this = obj;

        return obj;
//    return <#initializer#>;
    }

    unsigned doubly_linked_list::get_size() {
        return size;
    }

    bool doubly_linked_list::is_empty() {
        return !size;
    }

    void doubly_linked_list::print() {
        node *temp = head;

        while (temp != nullptr) { //-> next
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        if (is_empty()) {
            std::cout << "There are no nodes to print the contents of." << std::endl;
        }
    }

    std::string doubly_linked_list::to_string() {
        if(!head) return "";
        else {
            std::string output = "";
            output += std::to_string(head->data);
            node *to_return = head->next;
            while (to_return) {
                output += ", ";
                output += std::to_string(to_return->data);
                to_return = to_return->next;
            }
            return output;
        }
    }

    void doubly_linked_list::setter(int location, int value){
        node* temp= head;
        int temploc=0;

        while(temp!= nullptr && temploc++ != location){
            temp = temp->next;
        }

        temp->data = value;
    }

    void doubly_linked_list::swap_data(unsigned position1, unsigned position2){
        node *temp1 = head;
        node *temp2 = head;
        node *prev1=nullptr;
        node *next1=nullptr;
        node *prev2=nullptr;
        node *next2=nullptr;

        for(int i=0; i<position1; i++) {
            if (temp1->next != nullptr) {
                prev1 = temp1;
                temp1 = temp1->next;
            }
        }
        next1 = temp1->next;

        for(int i=0; i<position2; i++){
            if(temp2->next != nullptr){
                prev2 = temp2;
                temp2 = temp2->next;
            }
        }
        next2 = temp2->next;

        int temp;
        temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
    }

    void doubly_linked_list::swap2(unsigned position1, unsigned position2){
        swap_set(position1, position1, position2, position2);
    }
}