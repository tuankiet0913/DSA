int mid = 0;
int binarySearch(int arr[], int left, int right, int x)
{   
    
    if (left > right) return -1;
    mid = left + (right - left)/2;
    
    cout << "We traverse on index: " <<mid <<endl;
    
    if (arr[mid] == x ){return mid;} 
    else if (x > arr[mid]){
        return binarySearch(arr, mid + 1, right, x); 
    } else if (x < arr[mid]){
        return binarySearch(arr, left, mid - 1, x);
    }
    return -1;
}
