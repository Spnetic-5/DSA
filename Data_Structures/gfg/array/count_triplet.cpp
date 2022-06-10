// CPP program to find three numbers
// such that sum of two makes the
// third element in array
#include <bits/stdc++.h>
using namespace std;


void findTriplet(int arr[], int n)
{
    int count = 0;
    sort(arr, arr + n);

    
    for (int i = n - 1; i >= 0; i--) {
        int j = 0;
        int k = i - 1;
        
        while (j < k) {

            
            if (arr[i] == arr[j] + arr[k]) {

                // pair found
                count++;
                cout << count;
                return;
                // cout << count<< endl;
                // return;
            }

            else if (arr[i] > arr[j] + arr[k])
                j += 1;

            else
                k -= 1;
        }
    }

    
}

// driver program
int main()
{
    int arr[] = { 1, 2, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    findTriplet(arr, n);
    return 0;
}
