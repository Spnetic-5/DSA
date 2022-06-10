#include <bits/stdc++.h>
using namespace std;



int findPivot(int arr[], int n){
    int l = 0, r = n-1;
    

    while(l<=r){
        int mid = (l+r)/2;
        if (arr[mid]>arr[mid+1] &&  mid<n+1){
            return mid;
        }
        if (arr[mid] < arr[0]){
        r = mid -1;
        }
        else{
        l = mid + 1;
        }

    }
    return -1;
}


int binarySearch(int arr[], int x, int l, int r){
    
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]< x){
            l = mid+1;
        }
        else if(arr[mid]>x){
            r = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int search(int arr[], int n, int x){
    int pivot = findPivot(arr, n);
    if (pivot==-1){
        return binarySearch(arr, x, 0, n-1);
    }
    if (x<arr[0]){
        return binarySearch(arr, x, pivot+1, n-1);
    }
    
    return binarySearch(arr, x, 0, pivot);   

}



int main(){

    int arr[] = {4,5,6,7,8,9,1,2,3};
    cout<<search(arr,9,8)<<endl;
    return 0 ; 
}