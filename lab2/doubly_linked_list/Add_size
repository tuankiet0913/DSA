template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* heh = new Node(e);
    if (!head){
        head = heh;
        tail = heh;
    } else {
        tail->next = heh;
        heh->previous = tail;
        tail = heh;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    Node* heh = new Node(e);
    Node* moveToPos = head;
    
    if(index > count || index < 0){
        return;
    }
    
    for (int i = 0; i < index; i++){
       
         moveToPos = moveToPos->next;
        
    }
    
    if (index == 0){
        heh->next = head;
        if(head){
            head->previous = heh;
        }
        head = heh;
        if (tail == NULL){
            tail =heh;
        }
    }
    else if(index == count){
        tail->next = heh;
        heh->previous = tail;
        tail = heh;
    } else {
        moveToPos->previous->next=heh;
        heh->previous = moveToPos->previous;
        moveToPos->previous = heh;
        heh->next = moveToPos;
    }
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
   
    return count;
}
