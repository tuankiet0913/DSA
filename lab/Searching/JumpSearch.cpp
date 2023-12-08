int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int index = 0;
    for (int i = 0; i < n; i+=step){
        cout<< i << " ";
        if (arr[i]==x) return i;
        if (i + step < n){
        if (x < arr[i + step] && x > arr[i]){
            cout << i + step<< " ";
            for (int j = i + 1; j < i + step; j++){
                cout << j<< " ";
                if (arr[j]==x) return j;
            } 
            return -1;
        }
        }
        index = i;
    }
    
    while (index < n ){
        index++;
        cout << index << " ";
        if (arr[index] == x) return index;
    }
    
    return -1;
}
