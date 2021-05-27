// Time Complexity : O(n^2)
//  ------------------------------------------ INSERTION SORT -----------------------------------------------

#include <iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j]; // shifting no.s towards left if greater than current
            j--;
        } 
        arr[j+1] = current;   // inserting no. before shifted no.s
            
        
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
            
    }


    
    return 0;
}