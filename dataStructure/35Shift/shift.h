void shift(int k) {
	//handle -k
	if(k<0){
		k+= mSize;
	}
	k %= mSize;

	node* newnode = mHeader->next;
	for(int i=0;i<k;i++){
		newnode = newnode->next;
	}
	
	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;
	// std::cout << mHeader->next->next->data << std::endl;
	// std::cout << newnode->prev->next->data << std::endl;
	
	newnode->prev->next = mHeader; 
	mHeader->prev = newnode->prev; 
	
	mHeader->next = newnode;
	newnode->prev = mHeader;
	
	
	




}
