template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    if (count == 0) return true;
    else return false;
}

template<class T>
T Heap<T>::peek(){

    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < count; i++ ){
        if (elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (count == 0){
        return false;
    } 
    
    //swap
    swap (elements[0], elements[count - 1]);
    
    count--;
    
    reheapDown(0);
    return true;
}
