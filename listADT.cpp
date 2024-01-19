#include <iostream>
//incomplete

class List {

private:
  int* data;
  int size;

public:
  List() {
    //fixed length (more flexible approach later)
    data = new int[100];
    size = 0;
  }
  ~List() {
    delete[] data; //release memory to free storage
  }

  void cons(int item) {
    data[size++] = item;
  }

  int car() {
    return data[size-1];
  }

  List cdr() {
    List result;
    for(int i=0; i<size-1; ++i)
      result.cons(data[i]);
    return result;
  }
}
