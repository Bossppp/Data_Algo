#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &edge){
	if(n == NULL) return 0;
    if(n->left == NULL && n->right == NULL) return 1;

    int leftpath = my_recur(n->left,edge);
    int rightpath = my_recur(n->right,edge);

    edge = std::max(edge,leftpath+rightpath);

    return std::max(leftpath,rightpath) + 1;

	
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	if(mRoot == NULL) return -1;
    if(mRoot->left == NULL && mRoot->right == NULL) return 0;
    int max = -1;
    my_recur(mRoot,max);
    return max;
	
}

#endif
