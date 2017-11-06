#ifndef CMPE126F17_LABS_TREE_H
#define CMPE126F17_LABS_TREE_H
#include "node.h"

class tree {
    node* root;
public:
    tree();
    ~tree();
    void insert(int value);
    bool remove(int key);
    bool in_tree(int key);
    int get_frequency(int key);
    int level(int key);
    void path_to(int key);
    unsigned size();
    unsigned depth();
    void print();
    void print_gtl();
    void node_print_gtl(node* to_print);
};

#endif //CMPE126F17_LABS_TREE_H
