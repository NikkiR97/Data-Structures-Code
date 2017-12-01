#ifndef CMPE126F17_LABS_TREE_H
#define CMPE126F17_LABS_TREE_H
#include "node.h"
namespace lab7 {
    class tree {
        lab7::node *root;
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

        void node_print_gtl(node *to_print);

        //node* insertHelp(node *pointer, int val);

        node* insertHelp2(node *prev, node *pointer, int val);

        unsigned retSize(node *pointer, unsigned size);

        int getFreq(node *pointer, int key);

        int getLevel(node *pointer, int key, int level);

        bool findKey(node *pointer, int key);

        unsigned findDepth(node *pointer, unsigned size);

        void path2key(node *pointer, int key);

        void node_print(node *to_print);

    };
}

#endif //CMPE126F17_LABS_TREE_H
