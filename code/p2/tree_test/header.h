#ifndef ADD_H
#define ADD_H
#include <initializer_list>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <list>
using std::cin;
using std::cout;
using std::endl;
struct tree_node;
typedef struct tree_node *tree_t;
struct tree_node{
    int tn_ip;
    int tn_elt;
    struct tree_node *tn_l;
    struct tree_node *tn_r;
};

typedef struct tree_node *tree_t;


bool tree_isEmpty(tree_t tnp);
tree_t tree_make();
tree_t tree_make(int elt, tree_t left, tree_t right);
int tree_elt(tree_t tnp);
tree_t tree_left(tree_t tnp);
tree_t tree_right(tree_t tnp);
void print_tree(tree_t tnp);
void tree_print(tree_t tree);
int sum(tree_t tree);
bool tree_search(tree_t tree, int key);
int depth(tree_t tree);
int tree_min(tree_t tree);
std::list<int> traversal(tree_t tree);
bool tree_hasPathSum(tree_t tree, int sum);
bool covered_by(tree_t A, tree_t B);
bool contained_by(tree_t A,tree_t B);

void print_list(std::list<int> mylist);



#endif

