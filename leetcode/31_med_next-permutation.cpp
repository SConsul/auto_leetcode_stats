class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return;
        else{
            for(int i = n-1; i>0; i--){
                if(nums[i] > nums[i-1]){
                    // find the element from the back greater than i-1 and swap
                    for(int j=n-1; j>=i; j--){
                        if(nums[j] > nums[i-1]){
                            swap(nums, j, i-1);
                            break;
                        }
                    }
                    // from  ith position make ascending by flipping
                    int mid = (n - i)/2;
                    for(int j=0; j<mid; j++)
                        swap(nums, j+i, n-j-1); 
                    return;
                }  
            }
            //if here means list is completely in descending order and needs to be flipped
            for(int i=0; i< n/2; i++)
                swap(nums, i, n-i-1);
            }  
        }
    
    void swap(vector<int>&nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return;
    }
};