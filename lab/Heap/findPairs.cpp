bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
   map<int, pair<int, int>> myMap;
   
   for (int i = 0; i < n; i++){
       for (int j = i + 1; j < n; j++){
           int sum = arr[i] + arr[j];
           
           //check sum is exist before
           if(myMap.find(sum) != myMap.end()){
                //foundSum check distinct
                pair<int, int> p = myMap[sum];
                if (p.first != i && p.second != j){
                    //Found distinct pairs
                    pair1 = make_pair(arr[p.first], arr[p.second]);
                    pair2 = make_pair(arr[i], arr[j]);
                    return true;
                }
                
            } else {
                //sum 
                myMap[sum] = make_pair(i,j);
            } 
           
       }
   }
   return false;
}
