// Time Complexity : O(N)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> subarraySum(int arr[], int n, int s)
    {
        int curr_sum = arr[0], start = 0, i;
        vector<int> A;
    for (i = 1; i <= n; i++) {
        
        while (curr_sum > s && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }
    
        if (curr_sum == s) {
            A.push_back(start+1);
            A.push_back(i);
            return A;
        }
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
    A.push_back(-1);
    return A;
    }
 
int main()
{
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}