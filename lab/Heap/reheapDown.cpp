void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int lChild = index*2 + 1;
    int rChild = index*2 + 2;
    if (index < 0 || lChild > numberOfElements) return;
    if (maxHeap[index] < maxHeap[lChild] && maxHeap[index] < maxHeap[rChild]){
        if (lChild > rChild) {
            swap(maxHeap[lChild], maxHeap[index]);
            reheapDown(maxHeap, numberOfElements, lChild);
        } else {
            swap(maxHeap[rChild], maxHeap[index]);
            reheapDown(maxHeap, numberOfElements, rChild);
        }
    } else if (maxHeap[index] < maxHeap[lChild]){
        swap(maxHeap[lChild], maxHeap[index]);
        reheapDown(maxHeap, numberOfElements, lChild);
    } else if (maxHeap[index] < maxHeap[rChild]){
        swap(maxHeap[rChild], maxHeap[index]);
        reheapDown(maxHeap, numberOfElements, rChild);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    while ((index - 1)/2 >= 0 && maxHeap[index] > maxHeap[(index - 1)/2]){
        swap(maxHeap[index], maxHeap[(index - 1)/2]);
        index = (index - 1)/2;
    }
}
