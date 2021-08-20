void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset){
    if(ind==N){
        sumSubset.push_back(sum);
        return;
    }
        
    // pick
    func(ind+1, sum+arr[ind], arr, N, sumSubset);
    // Don't pick
    func(ind+1, sum, arr, N, sumSubset);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> sumSubset;
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}