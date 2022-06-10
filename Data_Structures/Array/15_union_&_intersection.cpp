//  ------------------------------------------ UNION AND INTERSECTION OF ARRAYS -----------------------------------------------

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
     
    //set  s
    set<int> s;
   
    
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
   
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements are: " << s.size() << endl;
      cout << "The union is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr<< " "; 
        cout<<endl;
 
}
void intersection(int a[], int n, int b[], int m)
{
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            j++;
        }
        else if (b[j] > a[i]) {
            i++;
        }
        else {
             
            // when both are equal
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}
// Driver Code
int main()
{
    int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    getUnion(a, 9, b, 10);
    sort(a, a + n);
    sort(b, b + m);
    intersection(a, n, b, m);
}