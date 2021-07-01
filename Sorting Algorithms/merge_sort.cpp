#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;



void merge(int A[], int low, int high, int mid){

    int i, j, k, S[100];
    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            S[k] = A[i];
            i++;
        }
        else{
            S[k] = A[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        S[k] = A[i];
        i++;k++;
    }
    while(j<=high){
        S[k] = A[j];
        j++;k++;
    }   
    
    for(int i = low; i < high; i++){
        A[i] = S[i];
        // cout<<S[i]<<" ";
    }
} 

void mergeSort(int A[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, high, mid);
    }    
}


void printArray(int A[],int n){
    for(int i=0;i<n;i++){
        cout<< A[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = { 6, 7, 2, 3, 55, 98, 11, 3};
    int n = 8;
    printArray(arr,n);
    mergeSort(arr,0, n);
    cout<<"Sorted : ";
    printArray(arr,n);
    return 0;
}