#include "header.h"
#include <list>

int main(int argc, char *argv[])
{
    tree_t tree1 = tree_make(1, 
                            tree_make(2, 
                                      tree_make(4,
                                                tree_make(5,
                                                          tree_make(),
                                                          tree_make()
                                                         ),
                                                tree_make(6,
                                                          tree_make(),
                                                          tree_make()
                                                         )
                                               ),
                                      tree_make()
                                     ),
                            tree_make(3,
                                      tree_make(),
                                      tree_make()
                                      )
                            );
    tree_print(tree1);
    
    tree_t tree2 = tree_make(2, tree_make(4, tree_make(), tree_make()), tree_make());
    tree_print(tree2);
    //std::list<int> res_list;
    //res_list = traversal(tree1);
    //print_list(res_list);
    cout<<contained_by(tree2, tree1)<<endl;
    return 0;
}
