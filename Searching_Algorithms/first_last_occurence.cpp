
// Time Complexity: O(logn)

#include<bits/stdc++.h>
using namespace std;

int first(int arr[], int n, int val){

    int l = 0;
    int r = n-1;
    int res= -1;
    
    while(l<=r){
        
        int mid = (l+r)/2;

        if (arr[mid]>val){
            r = mid-1;
        }

        else if(arr[mid]<val){
            l = mid+1;
        }
        else{
            res= mid;
            r = mid -1;
            
        }

    }
    return res;
}
int second(int arr[], int n, int val){

    int l = 0;
    int r = n-1;
    int res = -1;
    
    while(l<=r){
        
        int mid = (l+r)/2;
    

        if (arr[mid]>val){
            r = mid-1;
        }

        else if(arr[mid]<val){
            l = mid+1;
        }
        else{
            res= mid;
            l = mid +1;
            
        }

    }
    return res;
}

int main(){

    int arr[] = {4,32,54,54,54,54,80,92,175,200};

    cout<<first(arr,7,54)<<" ";
    cout<<second(arr,7,54)<<endl;
 
    return 0 ; 
}