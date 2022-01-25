// Time Complexity : O(log(n))

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key){
    
    int start = 0;
    int end = n;
    while(start<=n){
        int mid = (start+end)/2;
        if (arr[mid]== key){
            return mid;
        }
        else if(arr[mid]<n){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;

}

int main(){
    int n;
    int key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    cout<<BinarySearch(arr, n, key)<<endl;


    return 0;
}