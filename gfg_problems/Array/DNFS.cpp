#include<bits/stdc++.h>  
using namespace std;  

void DNFS(int arr[], int arr_size)  {

    int high = arr_size-1;
    int low = 0;
    int mid = 0;

    while(mid<=high){
        switch(arr[mid]){
            
            case 0: 
            swap(arr[low++], arr[mid++]);
            break;

            case 1:
            mid++;
            break;

            case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()  
{  
    int arr[] = {0,0,1,2,0,1,2};  
    int n = sizeof(arr)/sizeof(arr[0]);  

    cout << "Array before running the algorithm: ";  
      
    printArray(arr, n);   
    
    DNFS(arr, n);  
  
    cout << "\nArray after DNFS algorithm: ";  
      
    printArray(arr, n);  
  
    return 0;  
} 