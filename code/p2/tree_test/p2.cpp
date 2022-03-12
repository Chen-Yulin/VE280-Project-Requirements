#include "header.h"
#include <algorithm>
#include <list>

int sum(tree_t tree){
    if (tree_isEmpty(tree->tn_l)&&tree_isEmpty(tree->tn_r)){
        return tree->tn_elt;
    }else if (tree_isEmpty(tree->tn_r)&&!tree_isEmpty(tree->tn_l)) {
        return (tree->tn_elt+sum(tree->tn_l));
    }else if (tree_isEmpty(tree->tn_l)&&!tree_isEmpty(tree->tn_r)) {
        return (tree->tn_elt+sum(tree->tn_r));
    }else{
        return (tree->tn_elt+sum(tree->tn_l)+sum(tree->tn_r));
    }
}
bool tree_search(tree_t tree, int key){
    if (tree_isEmpty(tree->tn_l)&&tree_isEmpty(tree->tn_r)){
        return (tree->tn_elt==key);
    }else if (tree_isEmpty(tree->tn_r)&&!tree_isEmpty(tree->tn_l)) {
        return (tree->tn_elt==key)||tree_search(tree->tn_l,key);
    }else if (tree_isEmpty(tree->tn_l)&&!tree_isEmpty(tree->tn_r)) {
        return (tree->tn_elt==key)||tree_search(tree->tn_r, key);
    }else{
        return (tree->tn_elt==key)||tree_search(tree->tn_r, key)||tree_search(tree->tn_l, key);
    }
}
int depth(tree_t tree){
    if (tree_isEmpty(tree->tn_l)&&tree_isEmpty(tree->tn_r)){
        return 1;
    }else if (tree_isEmpty(tree->tn_r)&&!tree_isEmpty(tree->tn_l)) {
        return 1+depth(tree->tn_l);
    }else if (tree_isEmpty(tree->tn_l)&&!tree_isEmpty(tree->tn_r)) {
        return 1+depth(tree->tn_r);
    }else{
        return 1+std::max(depth(tree->tn_l),depth(tree->tn_r));
    }
}
int tree_min(tree_t tree){
    if (tree_isEmpty(tree->tn_l)&&tree_isEmpty(tree->tn_r)){
        return tree->tn_elt;
    }else if (tree_isEmpty(tree->tn_r)&&!tree_isEmpty(tree->tn_l)) {
        return std::min(tree->tn_elt,tree_min(tree->tn_l));
    }else if (tree_isEmpty(tree->tn_l)&&!tree_isEmpty(tree->tn_r)) {
        return std::min(tree->tn_elt,tree_min(tree->tn_r));
    }else{
        int temp = std::min(tree_min(tree->tn_l),tree_min(tree->tn_r));
        return std::min(temp,tree->tn_elt);
    }
}
std::list<int> traversal(tree_t tree){
    
    if (tree_isEmpty(tree->tn_l)&&tree_isEmpty(tree->tn_r)){
        std::list<int> res_list;
        res_list.push_back(tree->tn_elt);
        return res_list;
    }else if (tree_isEmpty(tree->tn_r)&&!tree_isEmpty(tree->tn_l)) {
        std::list<int> res_list(traversal(tree->tn_l));
        res_list.push_back(tree->tn_elt);
        return res_list;
    }else if (tree_isEmpty(tree->tn_l)&&!tree_isEmpty(tree->tn_r)) {
        std::list<int> res_list(traversal(tree->tn_r));
        res_list.push_front(tree->tn_elt);
        return res_list;
    }else{
        std::list<int> l_list(traversal(tree->tn_l));
        std::list<int> r_list(traversal(tree->tn_r));
        l_list.push_back(tree->tn_elt);
        l_list.splice(l_list.end(),r_list);
        return l_list;
    }
}
bool tree_hasPathSum(tree_t tree, int sum){
    if (tree_isEmpty(tree->tn_l)&&tree_isEmpty(tree->tn_r)){
        return tree->tn_elt == sum;
    }else if (tree_isEmpty(tree->tn_r)&&!tree_isEmpty(tree->tn_l)) {
        return tree_hasPathSum(tree->tn_l, sum-tree->tn_elt);
    }else if (tree_isEmpty(tree->tn_l)&&!tree_isEmpty(tree->tn_r)) {
        return tree_hasPathSum(tree->tn_r, sum-tree->tn_elt);
    }else{
        return tree_hasPathSum(tree->tn_r, sum-tree->tn_elt)||tree_hasPathSum(tree->tn_l, sum-tree->tn_elt);
    }
}
bool covered_by(tree_t A, tree_t B){
    if (A->tn_elt!=B->tn_elt){
        return false;
    }else{
        if (!tree_isEmpty(A->tn_l)&&tree_isEmpty(A->tn_r)){
            if (!tree_isEmpty(B->tn_l)){
                return covered_by(A->tn_l, B->tn_l);
            }else{
                return false;
            }
        }else if (!tree_isEmpty(A->tn_r)&&tree_isEmpty(A->tn_l)){
            if (!tree_isEmpty(B->tn_r)){
                return covered_by(A->tn_r, B->tn_r);
            }else{
                return false;
            }
        }else if (!tree_isEmpty(A->tn_r)&&!tree_isEmpty(A->tn_l)){
            if (!tree_isEmpty(B->tn_r)&&!tree_isEmpty(B->tn_l)){
                return covered_by(A->tn_r, B->tn_r)&&covered_by(A->tn_l, B->tn_l);
            }else{
                return false;
            }
        }else{
            return A->tn_elt==B->tn_elt;
        }
    }
}
bool contained_by(tree_t A, tree_t B){
    if (covered_by(A, B)){
        return true;
    }else{
        if (!tree_isEmpty(B->tn_l)&&tree_isEmpty(B->tn_r)){
            return contained_by(A, B->tn_l);
        }else if (!tree_isEmpty(B->tn_r)&&tree_isEmpty(B->tn_l)) {
            return contained_by(A, B->tn_r);
        }else if (!tree_isEmpty(B->tn_l)&&!tree_isEmpty(B->tn_r)) {
            return contained_by(A, B->tn_r)||contained_by(A, B->tn_l);
        }else{
            return false;
        }
    }
}















