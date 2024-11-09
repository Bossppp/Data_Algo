void replace(const T& x, list<T>& y) {
  auto itr = begin();

  while(itr != end()){
      if(*itr == x){
          for(auto e : y){
            insert(itr,e);
          }
          itr = erase(itr);
      }else{
        itr++;
      }
  }

}
