#include "header.h"
#include <cassert>
#include <iostream>
#include <new>

const unsigned int tree_node_id=114514;
const unsigned int tree_empty_id=191981;

struct tree_node;
typedef struct tree_node *tree_t;




static tree_t tree_checkValid(tree_t tnp){
    if ((tnp->tn_ip!=tree_node_id)&(tnp->tn_ip!=tree_empty_id)){
        std::cerr<<"Error: user passed invalid tree"<<endl;
        assert(0);
    }
    return tnp;
}

static void tree_checkNonEmpty(tree_t tnp){
    if (tree_isEmpty(tnp)){
        std::cerr<<"Error,empty"<<endl;
        assert(0);
    }
}

bool tree_isEmpty(tree_t tnp){
    return (tnp->tn_ip==tree_empty_id);
}

tree_t tree_make(){
    tree_t tnp=NULL;
    try{
        tnp = new struct tree_node;
    }catch(std::bad_alloc &a){
        throw "Not allocated";
    }

    tnp->tn_ip=tree_empty_id;
    tnp->tn_elt=0;
    tnp->tn_l=NULL;
    tnp->tn_r=NULL;
    return tnp;
}

tree_t tree_make(int elt, tree_t left, tree_t right){
    tree_t tnp = 0;
    try{
        tnp = new struct tree_node;
    }catch(std::bad_alloc &a){
        throw "Not allocated";
    }
    if(tree_isEmpty(left)){
        tree_checkValid(left);
    }
    if(tree_isEmpty(right)){
        tree_checkValid(right);
    }
    tnp->tn_ip = tree_node_id;
    tnp->tn_elt = elt;
    tnp->tn_l = left;
    tnp->tn_r = right;
    return tnp;
    
}

int tree_elt(tree_t tnp){
    return tnp->tn_elt;
}

tree_t tree_left(tree_t tnp){
    tree_checkNonEmpty(tnp);
    tree_t tree=tree_checkValid(tnp);
    return tree->tn_l;
}

tree_t tree_right(tree_t tnp){
    tree_checkNonEmpty(tnp);
    tree_t tree = tree_checkValid(tnp);
    return tree->tn_r;
}

static void
print_spaces(int spaces)
    // MODIFIES: cout
    // EFFECTS: prints n spaces
{
    while (spaces--) {
        cout << "  ";
    }
}

static void
tree_print_internal_old(tree_t tree, int spaces)
    // MODIFIES: cout
    // EFFECTS: prints tree contents recursively, with newlines 
    //          for each node, with each level indented
{
    print_spaces(spaces);
    if (tree_isEmpty(tree)) {
        cout << "( )\n";
    } else {
        cout << "(" << tree_elt(tree) << "\n";
        tree_print_internal_old(tree_left(tree), spaces+1);
        tree_print_internal_old(tree_right(tree), spaces+1);
        print_spaces(spaces);
        cout << " )\n";
    }
}

static void
tree_print_internal(tree_t tree, int spaces)
    // MODIFIES: cout
    // EFFECTS: prints tree contents recursively, with newlines 
    //          for each node, with each level indented
{
    if(tree_isEmpty(tree))
        return;
    else
    {
        tree_print_internal(tree_left(tree), spaces+2);
        print_spaces(spaces+1);
        cout << "/" << endl;
        print_spaces(spaces);
        cout << tree_elt(tree) << endl;
        print_spaces(spaces+1);
        cout << "\\" << endl;
        tree_print_internal(tree_right(tree), spaces+2);
    }
}

void
tree_print(tree_t tree)
{
    //tree_print_internal_old(tree, 0);
    tree_print_internal(tree, 0);
}











