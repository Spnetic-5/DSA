int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);
    int count = 1;
    int maxi = 1;
    int j = 0;
    int i = 1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            i++;
            count++;
        }
        else{
            count--;
            j++;
        }
        maxi = max(count, maxi); 
    }
return maxi;
    // Your code here
}