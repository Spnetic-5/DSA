// Time Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int val){

    for(int i = 0 ; i < n ; i ++ ){
        if(arr[i]==val)return i;
    }

    return -1;
}

int main(){

    int arr[] = {12,3,4,67,54,23,43};

    cout<<LinearSearch(arr,7,54)<<endl;
 
    return 0 ; 
}