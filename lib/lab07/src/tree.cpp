#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);

    void node_print_gtl(node *to_print);

// Construct an empty tree
    tree::tree() {
        root = nullptr;
    }

// Deconstruct tree
    tree::~tree() {
        clear(root);
    }

// Insert
    void tree::insert(int value) {
        //insert a node at the end of the tree (create a new leaf)
        //need to compare the values going into the tree to determine where to insert
        //compare with root, if smaller -> go left, if bigger -> go right
        //compare with all other nodes -> insert when you find a node pointing to nullptr
        //will not insert duplicates

        /*
        node *temp = root;

        if (!root) {
            root = new node(value);
        } else {
            while (temp->left != nullptr && temp->right != nullptr) {
                if (value < temp->data) {
                    temp = temp->left;
                } else if (value > temp->data) {
                    temp = temp->right;
                }
            }

            if (value > temp->data) {
                temp->right = new node(value);
            } else if (value < temp->data) {
                temp->left = new node(value);
            } else { //will enter if value == temp->data; -> then increment the frequency
                //std::cout << temp->data << "could not be inserted into the tree because it is a duplicate " << std::endl;
                temp->frequency++;
            }
        }
        */

        node *pointer = root;

        insertHelp(root,value);

        return;
    }

// Remove key
    bool tree::remove(int key) {
        //traverse through the list and find key
        //remove the node and make links

        //if node to be removed has a child

        node *prev, *temp = root;
        int dir;

        if (!root) {
            std::cout << "No nodes exist to remove." << std::endl;
            return false;
        }
        if (in_tree(key) == false) {
            std::cout << "No key in the tree. No nodes to remove" << std::endl;
            return false; //need to exit the function if the key does not exist on the tree
        } else {
            while (temp->left != nullptr && temp->right != nullptr && temp->data != key) {
                if (key < temp->data) {
                    prev = temp;
                    temp = temp->left;
                    dir = 1;
                } else if (key > temp->data) {
                    prev = temp;
                    temp = temp->right;
                    dir = 0;
                }
            }
            //after finding key, need to traverse through until you reach the end of that subtree in order to make the correct replacements
            //when ever you plan to remove a node, make the replace and again traverse to the end
            //when removing the node, replace with the left side (if exists, else with right side) or left side of the child

            node *to_remove = temp;
            //int to_dir;

            while (temp != nullptr) {
                if (temp->left != nullptr) {
                    prev = to_remove;
                    dir = 1;
                    to_remove = temp->left;

                    if (to_remove->left != nullptr) {
                        prev = to_remove;
                        to_remove = to_remove->left;
                        dir = 1;
                    } else if (to_remove->right != nullptr) {
                        prev = to_remove;
                        to_remove = to_remove->right;
                        dir = 0;
                    }
                    //at this point, make the replacement of temp's content with to_remove's and then call the function again if to_remove has any children
                    temp->data = to_remove->data;
                    temp = to_remove; //temp now points to where to_remove is
                    //remove(to_remove->data); //cannot do that, will go infinitely because it will never reach to_remove's node but temp's node
                } else if (temp->right != nullptr) {
                    prev = to_remove;
                    dir = 0;
                    to_remove = temp->right;

                    if (to_remove->left != nullptr) {
                        prev = to_remove;
                        dir = 1;
                        to_remove = to_remove->left;
                    } else if (to_remove->right != nullptr) {
                        prev = to_remove;
                        dir = 0;
                        to_remove = to_remove->right;
                    }
                    temp->data = to_remove->data;
                    temp = to_remove; //temp now points to where to_remove is
                    //remove(to_remove->data);
                } else {
                    if (dir == 1) {
                        prev->left = nullptr;
                    } else if (dir == 0) {
                        prev->right = nullptr;
                    }
                    return true;
                }
            }
        }
    }

// What level is key on?
    int tree::level(int key) {
        //every level has maximum 2 to the n nodes
        //every time I need use the point to change the location of temp, need to increment level_count;

        /*
        node *temp = root;
        int level_count=0; //the first level (root) is at level 0

        if(!root){
            std::cout << "No nodes exist in the tree." << std::endl;
        }
        if(in_tree(key) == false){
            std::cout << "No key in the tree. Cannot identify the level." << std::endl;
            return false; //need to exit the function if the key does not exist on the tree
        }
        else {
            while (temp->left != nullptr && temp->right != nullptr && temp->data!=key) {
                if (key < temp->data) {
                    temp = temp->left;
                    level_count++;
                } else if (key > temp->data) {
                    temp = temp->right;
                    level_count++;
                }
            }
        }*/

        //use preorder

        int level_count = 0;
        node *pointer = root;

        level_count = getLevel(pointer, key, level_count);

        return level_count;
    }

// Print the path to the key, starting with root
    void tree::path_to(int key) {

        node *temp = root;

        if(!root){
            std::cout << "No nodes exist on the tree" << std::endl;
        }
        if(in_tree(key) == false){
            std::cout << "No key in the tree, no path to print out. " << std::endl;//need to exit the function if the key does not exist on the tree
        }
        else {
            while (temp->left != nullptr && temp->right != nullptr) {
                if (key < temp->data) {
                    std::cout << temp->data << " ";
                    temp = temp->left;
                } else if (key > temp->data) {
                    std::cout << temp->data << " ";
                    temp = temp->right;
                }
            }
            std::cout << temp->data << std::endl;
        }


        //Below is the recursive version but it doesn't seem to work to well
        //node *pointer = root;
        //path2key(pointer, key);

    }

// Number of items in the tree
    unsigned tree::size() {
        //traverse through the similar way you would when printing but don't print, just keep count;

        /* This is not my code, have only tried to implement it into my own
        node *current,*prev;
        int size = 0;

        if(root == nullptr) {
            return 0;
        }
        current = root;
        while(current != nullptr)
        {
            if(current->left == nullptr)
            {
                size++;
                current = current->right;
            }
            else
            {
                prev = current->left;
                while(prev->right != nullptr && prev->right != current) {
                    prev = prev->right;
                }
                if(prev->right == nullptr)
                {
                    prev->right = current;
                    current = current->left;
                }
                else
                {
                    prev->right = nullptr;
                    size++;
                    current = current->right;
                }
            }
        }*/
        unsigned size = 0;
        node *findNode = root;

        size = retSize(findNode, size);
        //WILL BE PROVIDED FOR YOU

        return size;
    }

// Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        //there can be more than one longest path
        //means to find the diameter of the tree
        //try the depth first search
        //compare the left and right sides to each other

        unsigned depth;
        node *pointer = root;

        depth = findDepth(pointer, depth);

        return depth;
    }

// Determine whether the given key is in the tree
    bool tree::in_tree(int key) { //need to fix
        //find the key in the tree and if it exists then return true, else return false

        /*
        node *temp = root;
        int dir;

        if(!root){
            std::cout << "No nodes exist to find key on." << std::endl;
            return false;
        }
        else {
            while (temp->left != nullptr && temp->right != nullptr && temp->data != key) {
                if (key < temp->data) {
                    temp = temp->left;
                    dir = 1;
                } else if (key > temp->data) {
                    temp = temp->right;
                    dir = 0;
                }
            }
            if (temp->data != key) {
                std::cout << "No nodes exist with that key." << std::endl;
                return false;
            }
            else{
                return true;
            }
        }*/

        bool truth;
        node *pointer = root;

        truth = findKey(pointer, key);

        return truth;
    }

// Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        //tree is already in order, only need to find how many times the key occurs in the tree by traversing through small and big.
        //if there are any copies of the same number than it is probably in the same level and has the same parent.
        // can only occur one time or two times
        int freq;
        node *pointer = root;

        freq = getFreq(pointer, key);

        return freq;
    }

// Print the tree least to greatest, Include duplicates
    void tree::print() {
        //start from the leftmost node work towards right to rightmost node

        //node *temp = root;
        /*stack obj;

        while(temp -> left!=nullptr || temp -> right != nullptr){
            if(temp->left){
                temp = temp -> left;
            }
            else if (temp -> right){
                temp = temp -> right;
            }
            else{
                while(!obj.isempty()){
                    if(temp-> data >= obj.top()){
                        std::cout << obj.top() << " ";
                        obj.pop();
                    }
                }
                obj.push(temp->data);
                delete temp; // delete node to cancel link
                temp = root;
            }
      */

        node *temp = root;

        node_print(temp);

        std::cout << std::endl;
    }

    void tree::print_gtl() {
        //WILL BE PROVIDED FOR YOU
    }

    void tree::node_print_gtl(node *to_print) {
        //WILL BE PROVIDED FOR YOU
    }

    void tree::node_print(node *to_print) {
        //node *temp = root;
        int dataFreq = 0;

        if (to_print == nullptr)
            return;

        node_print(to_print->left);
        dataFreq = to_print->frequency;
        while(dataFreq>0) {
            std::cout << to_print->data << " "; // visit the node
            dataFreq--;
        }
        //print_gtl();
        node_print(to_print->right);

    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    unsigned tree::retSize(node *pointer, unsigned size) {
        //int size=0;
        //node *findNode = root;


//    if(pointer == NULL)
//        return size;
//    retSize(pointer->left, size);
//    size = size+pointer->frequency;
//    retSize(pointer->right, size);

//        if (pointer == nullptr)
//            return size;
//
//        //size = size+ pointer->frequency;
//
//        return retSize(pointer->left, size+pointer->frequency) + retSize(pointer->right, size+pointer->frequency)+1;

        if (pointer == nullptr)
            return size;
        else {
                size += pointer->frequency+1;
                retSize(pointer->left, size);
                retSize(pointer->right, size);
        }
    }

    int tree::getFreq(node *pointer, int key) {

        //if(pointer== nullptr)
        //   return pointer->frequency;
        /*if(pointer->data == key)
           return pointer->frequency;

       if(pointer -> left) {
           getFreq(pointer->left, key);
       }
       if(pointer -> right) {
           getFreq(pointer->right, key);
       }*/
        int next;

        if (pointer == nullptr)
            return 0;
        if (pointer->data == key)
            return pointer->frequency;

        next = getFreq(pointer->left, key);
        if (next != 0)
            return next;
        next = getFreq(pointer->right, key);

        //return next;
    }

    int tree::getLevel(node *pointer, int key, int level) {
        /*if(pointer== nullptr)
            return 0; //fail
        if(pointer->data == key)
            return level;

        level++;
        if(pointer -> left) {
            getLevel(pointer->left, key, level);
        }
        if(pointer -> right) {
            getLevel(pointer->right, key, level);
        }*/
        int nextlevel;

        if (pointer == nullptr)
            return 0;
        if (pointer->data == key)
            return level;

        nextlevel = getLevel(pointer->left, key, level + 1);
        if (nextlevel != 0)
            return nextlevel;

        nextlevel = getLevel(pointer->right, key, level + 1);
        return nextlevel;
    }

    bool tree::findKey(node *pointer, int key) {
        int next;

        if (pointer == nullptr)
            return false;
        if (pointer->data == key)
            return true;

        next = getFreq(pointer->left, key);
        if (next != 0)
            return next;
        next = getFreq(pointer->right, key);
    }

    unsigned tree::findDepth(node *pointer, unsigned size) {
        //need to find the depth of the left subtree and then the depth of the right subtree
        unsigned depthleft = 0;
        unsigned depthright = 0;

        if (pointer == nullptr)
            return 0;
        depthleft = findDepth(pointer->left, size);
        depthright = findDepth(pointer->right, size);

        if (depthleft >= depthright) {
            return depthleft + 1;
        } else {
            return depthright + 1;
        }
    }

    void tree::path2key(node *pointer, int key) {
        if (pointer == nullptr)
            return;
        if (pointer->data == key) {
            std::cout << pointer->data << std::endl;
            return;
        }

        if (pointer->data < key) {
            std::cout << pointer->data << std::endl; // visit the node
            path2key(pointer->left, key);
        }
        if (pointer->data > key) {
            std::cout << pointer->data << " "; // visit the node
            path2key(pointer->right, key);
        }
    }

    node* tree::insertHelp(node *pointer, int val){
/*
        if(pointer == nullptr){
            pointer = new node(val);
            return pointer;
        }
        else {
            if (val < pointer->data) {
                 insertHelp(pointer->left, val); //pointer->left =
            } else if (val > pointer->data) {
                 insertHelp(pointer->right, val); //pointer->right =
            } else {
                pointer->frequency++;
            }
        }*/

        if (root == nullptr) {
            root = new node(val);
        } else if (val == pointer->data) {
            pointer->frequency++;
        } else if (val < pointer->data) {
            if (pointer->left != nullptr)
                insertHelp(pointer->left, val);
            else {
                pointer->left = new node(val);
            }
        } else if (val > pointer->data) {
            if (pointer->right != nullptr)
                insertHelp(pointer->right,val);
            else {
                pointer->right = new node(val);
            }
        }
    }

}