void splitList(list<T>& list1, list<T>& list2) {
    
    int num1 = ceil(mSize/2);
    int num2 = mSize-num1;
    if(num1 > 0){
        list1.mHeader->prev->next = mHeader->next;
        mHeader->next->prev = list1.mHeader->prev;
        node* n1 = mHeader->next; //ควรสร้างไว้กันแตก
        for(int i = 0; i < num1; i++){
            n1 = n1->next;
        }
        n1->prev->next = list1.mHeader;
        list1.mHeader->prev = n1->prev;

        if(num2 > 0){
            list2.mHeader->prev->next = n1;
            n1->prev = list2.mHeader->prev;
            mHeader->prev->next = list2.mHeader;
            list2.mHeader->prev = mHeader->prev;
        }
    }
    mHeader->prev = mHeader; //ให้ชี้ไปที่ตัวเอง
    mHeader->next = mHeader;
    mSize = 0;
    list1.mSize += num1;
    list2.mSize += num2;
}
