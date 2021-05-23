// (Simple Linear Search) 
// Initialize values of min and max as minimum and maximum of the first two elements respectively. Starting from 3rd, compare each element with max and min, and change max and min accordingly (i.e., if the element is smaller than min then change min, else if the element is greater than max then change max, else ignore the element) 

#include <iostream>
using namespace std;
struct Pair{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n){
    struct Pair minmax;
    

// if only one element in array
    if(n==1){
        minmax.max = arr[0];
        minmax.min = arr[0];

    }

// if more that one elements
if (arr[0]>arr[1]){
    minmax.max = arr[0];
    minmax.min = arr[1];
}
else{
    minmax.max = arr[1];
    minmax.min = arr[0];
}

for(int i=2;i<n;i++){
    if (arr[i] > minmax.max)
        minmax.max=arr[i];
    else if (arr[i] < minmax.min)
        minmax.min = arr[i];
}
return minmax;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++){
        cin>>arr[j];
    }    
    
    struct Pair minmax = getMinMax(arr, n);
    cout << "Minimum is "
         << minmax.min << endl;
    cout << "Maximum is "
         << minmax.max<< endl;

return 0;

}

