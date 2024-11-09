// Your code here
int MAX = 0;
KeyT x;
int processIm (node* n){
    if(n == NULL) return 0;
    int left = processIm(n->left);
    int right = processIm(n->right);
    
    //กรณีปกติ
    if(std::abs(left-right) > MAX){
        MAX = std::abs(left-right);
        x = n->data.first;
    }
    //กรณีตัว max เท่า ให้เอาตัวที่ค่่าน้อยกว่า
    if(std::abs(left-right) == MAX && mLess(n->data.first,x)){
        x = n->data.first;
    } 
    return std::max(left,right)+1;

}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    processIm(mRoot);
    return x;
}
