template <class T>
T DLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= this->count) {
        throw std::out_of_range("Index is out of bounds");
    }

    // Navigate to the node to remove
    Node* current = this->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    // Update links and delete the node
    if(current->previous) current->previous->next = current->next;
    if(current->next) current->next->previous = current->previous;

    // Update head and tail if needed
    if(index == 0) this->head = current->next;
    if(index == this->count - 1) this->tail = current->previous;

    T removedData = current->data;
    delete current;
    this->count--;

    return removedData;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item) {
    Node* current = this->head;
    int index = 0;

    // Search for the item
    while (current != NULL) {
        if (current->data == item) {
            removeAt(index);
            return true;
        }
        current = current->next;
        index++;
    }

    return false; // Item not found
}

template<class T>
void DLinkedList<T>::clear(){
    while (this->head != NULL) {
        Node* current = this->head;
        this->head = this->head->next;
        delete current;
    }
    this->tail = NULL;
    this->count = 0;
}
