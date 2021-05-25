#include<iostream>
using namespace std;
int main ()
{
    int arr[10], n, i, max, min;
    cout << "Enter size ";
    cin >> n;
    cout << "Enter elements ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    min = arr[0];
    for (i = 0; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    cout << "Largest element : " << max<<endl;
    cout << "Smallest element : " << min<<endl;
    return 0;
}