// Your code here
int MAX = 0;
KeyT x;
int processIm (node* n){
    if(n == NULL) return 0;
    int left = processIm(n->left);
    int right = processIm(n->right);
    if((std::abs(left-right) > MAX) || std::abs(left-right) == MAX && mLess(n->data.first,x)){
        MAX = std::abs(left-right);
        x = n->data.first;
    }
    return std::max(left,right)+1;

}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    processIm(mRoot);
    return x;
}
