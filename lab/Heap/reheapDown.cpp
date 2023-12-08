void reheapDown(int maxHeap[], int numberOfElements, int index)
{   
    
    if (index < 0||index*2 + 1 >= numberOfElements) return;
    if (maxHeap[index] < maxHeap[(index*2) + 1] && maxHeap[index] < maxHeap[(index*2) + 2]){
        if (maxHeap[(index * 2) + 1] > maxHeap[(index * 2) + 2]){
            swap(maxHeap[index], maxHeap[(index*2) + 1]);
            reheapDown(maxHeap, numberOfElements, (index*2) + 1);
        } else {
            swap(maxHeap[index], maxHeap[(index*2) + 2]);
            reheapDown(maxHeap, numberOfElements, (index*2) + 2);
        }
    } else if (maxHeap[index] < maxHeap[(index*2) + 1]){
        swap(maxHeap[index], maxHeap[(index*2) + 1]);
        reheapDown(maxHeap, numberOfElements, (index*2) + 1);
    } else if (maxHeap[index] < maxHeap[(index*2) + 2]){
        swap(maxHeap[index], maxHeap[(index*2) + 2]);
        reheapDown(maxHeap, numberOfElements, (index*2) + 2);
    }
    
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if ((index - 1)/2  < 0) return;
    
    while (maxHeap[index] > maxHeap[(index - 1)/2]){
        swap(maxHeap[index],maxHeap[(index - 1)/2]);
        index = (index - 1)/2; 
    }
}
