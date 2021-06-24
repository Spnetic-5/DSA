#include <iostream>
#include <unordered_map>
using namespace std;
 
// Function to find a pair in an array with a given sum using hashing
void findPair(int arr[], int n, int sum)
{
    // create an empty map
    unordered_map<int, int> map;
 
    // do for each element
    for (int i = 0; i < n; i++)
    {
        // check if pair `(arr[i], sum - arr[i])` exists
 
        // if the difference is seen before, print the pair
        if (map.find(sum - arr[i]) != map.end())
        {
            cout << "Pair found (" << arr[map[sum - arr[i]]] << ", " << arr[i] << ")";
            return;
        }
 
        // store index of the current element in the map
        map[arr[i]] = i;
    }
 
    // we reach here if the pair is not found
    cout << "Pair not found";
}
 
int main()
{
    int arr[] = { 8, 7, 2, 5, 3, 1 };
    int sum = 10;
 
    int n = sizeof(arr)/sizeof(arr[0]);
 
    findPair(arr, n, sum);
 
    return 0;
}