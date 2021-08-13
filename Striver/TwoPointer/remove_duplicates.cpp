// Brute Approach using HashMap 
// Time Complexity:  O(n)
// Space Complexity: O(n)

int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1)
        return n;
        
        int temp[n];
        
        int j = 0;
        for (int i=0; i<n-1; i++){

            if (nums[i] != nums[i+1]){
                temp[j++] = nums[i];
                }
             }
            temp[j++] = nums[n-1];
        for (int i=0; i<j; i++){
            nums[i] = temp[i];
            }
    return j;
    }

// Optimal Approach using 2 pointers
// Time Complexity:  O(n)
// Space Complexity: O(1)
int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0 || n==1)
        return n;
        
        int i = 0;
       
        for(int j=1; j<n; j++){
            
            if (nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            } 
        }    
        
    return i+1;
    }