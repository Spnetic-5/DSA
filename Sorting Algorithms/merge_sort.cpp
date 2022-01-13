#include <iostream>
using namespace std;

void _merge(int *arr, int *temp, int left, int mid, int right){

   int i, j, k;
   i = left;
   j = mid+1;
   k = 0;

   while((i <= mid) && (j <= right)){
      if(arr[i]<=arr[j]){
         temp[k++] = arr[i++];
      }
      else{
         temp[k++] = arr[j++];
      }
   }

   while(i <= mid){
      temp[k++] = arr[i++];
   }

   while(j <= right){
      temp[k++] = arr[j++];
   }

   for(int i = left; i <= right; i++){
      arr[i] = temp[i-left];
   } 
}


void mergeSort(int *arr, int *temp, int left, int right){

   if(left < right){
      int mid = left + (right - left)/2;
      mergeSort(arr, temp, left, mid);
      mergeSort(arr, temp, mid+1, right);
      _merge(arr, temp, left, mid, right);
   }
}



int main(){
   
   int arr[] = {1,12,8,9,34,5,62,17,4,10};
   int n = sizeof(arr) / sizeof(arr[0]);
   int temp[n];
   mergeSort(arr, temp, 0, n-1);
   for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
   }
   return 0;
}

















































// #include<iostream>
// using namespace std;
// void swapping(int &a, int &b) {     //swap the content of a and b
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
// }
// void display(int *array, int size) {
//    for(int i = 0; i<size; i++)
//       cout << array[i] << " ";
//    cout << endl;
// }
// void merge(int *array, int l, int m, int r) {
//    int i, j, k, nl, nr;
//    //size of left and right sub-arrays
//    nl = m-l+1; nr = r-m;
//    int larr[nl], rarr[nr];
//    //fill left and right sub-arrays
//    for(i = 0; i<nl; i++)
//       larr[i] = array[l+i];
//    for(j = 0; j<nr; j++)
//       rarr[j] = array[m+1+j];
//    i = 0; j = 0; k = l;
//    //marge temp arrays to real array
//    while(i < nl && j<nr) {
//       if(larr[i] <= rarr[j]) {
//          array[k] = larr[i];
//          i++;
//       }else{
//          array[k] = rarr[j];
//          j++;
//       }
//       k++;
//    }
//    while(i<nl) {       //extra element in left array
//       array[k] = larr[i];
//       i++; k++;
//    }
//    while(j<nr) {     //extra element in right array
//       array[k] = rarr[j];
//       j++; k++;
//    }
// }
// void mergeSort(int *array, int l, int r) {
//    int m;
//    if(l < r) {
//       int m = l+(r-l)/2;
//       // Sort first and second arrays
//       mergeSort(array, l, m);
//       mergeSort(array, m+1, r);
//       merge(array, l, m, r);
//    }
// }
// int main() {
//    int n = 8;
//    int arr[] = { 6, 7, 2, 3, 55, 98, 11, 3};     //create an array with given number of elements
//    cout << "Array before Sorting: ";
//    display(arr, n);
//    mergeSort(arr, 0, n-1);     //(n-1) for last index
//    cout << "Array after Sorting: ";
//    display(arr, n);
// }