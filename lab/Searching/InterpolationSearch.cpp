int interpolationSearch(int arr[], int left, int right, int x)
{   
    if (left == right){
        if (arr[left] == x) return right;
        return -1;
    } 
    
    if (x < arr[left]|| x > arr[right]) return -1;
    double midi = static_cast<double>(((x - arr[left])*(right-left))/(arr[right]-arr[left])+left);
    int mid = static_cast<int>(midi);
    if (mid < left || mid > right) return -1;
    if (mid < 0) return -1;
    cout << "We traverse on index: "<< mid<<endl;
    if (arr[mid]==x){
        return mid;
    } else if (arr[mid] < x) {
        return interpolationSearch(arr, mid + 1, right, x);
    } else if (arr[mid]> x){
        return interpolationSearch(arr, left, mid - 1, x);
    }
    return -1;
}
