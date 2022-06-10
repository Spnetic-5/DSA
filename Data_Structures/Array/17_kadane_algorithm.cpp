// ------------------------------------------------------------------KADANE'S ALGORITHM---------------------------------------------------------------
// Initialize:
//     max_so_far = 0
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far

#include <iostream>
using namespace std;
int maxSubarraySum(int arr[], int n){
        
    // Your code here
    int max_so_far = 0;
    int max_ending_here = 0;
    for(int i=0;i<n;i++){
        max_ending_here = max_ending_here + arr[i];    
    if(max_so_far < max_ending_here)
        max_so_far = max_ending_here;
    else if(max_ending_here < 0)
        max_ending_here = 0;
            
    }
    return max_so_far;    
}

int main() {
     int arr[] = {1, 2, 3, -2, 5};
    int n = sizeof(arr) /
            sizeof(arr[0]);
    cout<<maxSubarraySum(arr, n)<<endl;


    return 0;
}