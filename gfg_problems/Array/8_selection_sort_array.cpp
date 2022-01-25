// Time Complexity : O(n^2)
//  ------------------------------------------ SELECTION SORT -----------------------------------------------

#include <iostream>
using namespace std;

int SortArray(int arr[], int n){
    for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
           if (arr[j]<arr[i]){
               int s = arr[i];
               arr[i] = arr[j];
               arr[j] = s;
           }
       }
    }
    return -1;
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    SortArray(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}