template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for (int i = 0; i < count; i++){
        if (elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    if (count == 0) return;
    int pos = getItem(item);
    if (pos != -1){
        swap(elements[pos], elements[count - 1]);
        count--;
        reheapDown(pos);
        reheapUp(pos);
    }    
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete [] elements;
    //    then reallocate memory as initial state
    count = 0;
    capacity = 10;
    elements = new T[capacity];

}
