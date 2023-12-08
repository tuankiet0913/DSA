template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count + 1);
    elements[count] = item;
    count++;
    reheapUp(count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > capacity){
        capacity = capacity*2;
        T* newElements = new T[capacity];
        for (int i = 0; i < minCapacity; i++){
            newElements[i] = elements[i];
        }
        delete [] elements;
        elements = newElements;
    } 
    
}

template<class T>
void Heap<T>::reheapUp(int position){
    while (position > 0 && elements[position] > elements[(position - 1)/2]){
        swap(elements[position], elements[(position - 1)/2]);
        position = (position - 1)/2;
    }
}
