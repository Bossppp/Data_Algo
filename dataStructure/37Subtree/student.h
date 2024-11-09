#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >

size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if(n == NULL) return 0;
  return 1+ process(n->left) + process(n->right);
  //size config
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  if(mRoot == NULL) return std::pair<KeyT,MappedT>();

  //clear lf rt before
  left.clear();
  right.clear();
  //assign lf rt
  left.mRoot = mRoot->left;
  right.mRoot = mRoot->right;
  //size config
  left.mSize = process(left.mRoot);
  right.mSize = process(right.mRoot);
  mSize = 1;
  //clear root
  mRoot->left = NULL;
  mRoot->right = NULL;
  return mRoot->data;
}

#endif

