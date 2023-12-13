template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    
    Node* moveToPos=head;
    for (int i = 0; i < index; i++){
        moveToPos = moveToPos->next;
    }
    
    return moveToPos->data;
    
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
     Node* moveToPos=head;
    for (int i = 0; i < index; i++){
        moveToPos = moveToPos->next;
    }
    moveToPos->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (count == 0){
        return true;
    } else return false;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index whether item appears in list, otherwise return -1 */
    Node* moveToPos=head;
    int index = 0;
    while (moveToPos!=NULL){
        if(item == moveToPos->data){
            return index;
        } 
        moveToPos = moveToPos->next;
        index++;
    }
    return -1;
   
}
