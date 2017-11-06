#include "../inc/tree.h"
#include <iostream>

void clear(node* to_clear);
void node_print_gtl(node* to_print);

// Construct an empty tree
tree::tree(){
    root = nullptr;
}

// Deconstruct tree
tree::~tree(){
    clear(root);
}

// Insert
void tree::insert(int value){
    //insert a node at the end of the tree (create a new leaf)
    //need to compare the values going into the tree to determine where to insert
    //compare with root, if smaller -> go left, if bigger -> go right
    //compare with all other nodes -> insert when you find a node pointing to nullptr
    //will not insert duplicates

    node *temp = root;

    if(!root){
        root = new node(value);
    }
    else {
        while (temp -> left != nullptr && temp -> right != nullptr) {
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
        }
        else{
                std::cout << temp->data << "could not be inserted into the tree because it is a duplicate " << std::endl;
        }
    }

}

// Remove key
bool tree::remove(int key){
    //traverse through the list and find key
    //remove the node and make links

    //if node to be removed has a child

    node *prev, *temp = root;
    int dir;

    if(!root){
        std::cout << "No nodes exist to remove." << std::endl;
        return false;
    }
    else {
        while (temp -> left != nullptr && temp -> right != nullptr && temp -> data != key) {
            if (key < temp->data) {
                prev = temp;
                temp = temp->left; dir=1;
            } else if (key > temp->data) {
                prev = temp;
                temp = temp->right; dir=0;
            }
        }
        if(temp->data != key){
            std::cout << "No nodes exist with that key." << std::endl;
            return false;
        }
        //after finding key, need to traverse through until you reach the end of that subtree in order to make the correct replacements
        //when ever you plan to remove a node, make the replace and again traverse to the end
        //when removing the node, replace with the left side (if exists, else with right side) or left side of the child

        node *to_remove = temp;
        int to_dir;

        if(temp->left != nullptr){
            to_remove = temp->left;

             if (to_remove->left != nullptr){
                 to_remove = to_remove->left; to_dir=1;
             }
             else if(temp->right != nullptr){
                 to_remove = to_remove->right; to_dir=0;
             }
            //at this point, make the replacement of temp's content with to_remove's and then call the function again if to_remove has any children
            temp->data = to_remove->data;
            remove(to_remove->data);
        }
        else if(temp->right != nullptr){
            to_remove = temp->right;

            if (to_remove->left != nullptr){
                to_remove = to_remove->left;
            }
            else if(temp->right != nullptr){
                to_remove = to_remove->right;
            }
            remove(to_remove->data);
        }
        else{
             if(dir==1){
             prev -> left = nullptr;
             }
             else if(dir==0){
             prev -> right = nullptr;
             }
            return true;
        }
    }
}

// What level is key on?
int tree::level(int key){
    //every level has maximum 2 to the n nodes
    //every time I need use the point to change the location of temp, need to increment level_count;
    node *temp = root;
    int level_count=0; //the first level (root) is at level 0

    if(!root){
        std::cout << "No nodes exist to find the key on." << std::endl;
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
    }
}

// Print the path to the key, starting with root
void tree::path_to(int key){
    node *temp = root;

    if(!root){
        std::cout << "No nodes exist to find the key on." << std::endl;
    }
    else {
        while (temp->left != nullptr && temp->right != nullptr) {
            if (key < temp->data) {
                std::cout << temp->data << std::endl;
                temp = temp->left;
            } else if (key > temp->data) {
                std::cout << temp->data << std::endl;
                temp = temp->right;
            }
        }
    }
}

// Number of items in the tree
unsigned tree::size(){
    //traverse through the similar way you would when printing but don't print, just keep count;


}

// Calculate the depth of the tree, longest string of connections
unsigned tree::depth(){

}

// Determine whether the given key is in the tree
bool tree::in_tree(int key){
    //find the key in the tree and if it exists then return true, else return false


}

// Return the number of times that value is in the tree
int tree::get_frequency(int key){
    //tree is already in order, only need to find how many times the key occurs in the tree by traversing through small and big.
    //if there are any copies of the same number than it is probably in the same level and has the same parent.
    // can only occur one time or two times

}

// Print the tree least to greatest, Include duplicates
void tree::print(){
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

    node_print_gtl(temp);

}

void tree::print_gtl(){
    //WILL BE PROVIDED FOR YOU
}

void tree::node_print_gtl(node* to_print){
    //node *temp = root;
    if(to_print == NULL)
        return;

    node_print_gtl(to_print->left);
    std::cout << to_print->data << std::endl; // visit the node
    //print_gtl();
    node_print_gtl(to_print->right);
    //WILL BE PROVIDED FOR YOU
}

void clear(node* to_clear){
    if(to_clear == nullptr) return;
    if(to_clear->left != nullptr) clear(to_clear->left);
    if(to_clear->right != nullptr) clear(to_clear->right);
    delete to_clear;
}