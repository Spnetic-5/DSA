
// Time Complexity: O(logn)

#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int val){

    int l = 0;
    int r = n-1;
    
    
    while(l<=r){
        
        int mid = (l+r)/2;
        // cout<<"l: "<<l<<" r: "<<r<<" mid: "<<mid<<" arr[mid]: "<<arr[mid]<<endl;

        if (arr[mid]>val){
            r = mid-1;
        }

        else if(arr[mid]<val){
            l = mid+1;
        }
        else{
            return mid;
        }

    }

    
    return -1;
}

int main(){

    int arr[] = {4,32,54,80,92,175,200};

    cout<<BinarySearch(arr,7,54)<<endl;
 
    return 0 ; 
}