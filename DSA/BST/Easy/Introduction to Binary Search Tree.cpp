bool isBSTTraversal(vector<int>& nums) {
        // your code here
        for(int i=0;i<nums.size()-1;i++)
           {
           if(nums[i+1] <=  nums[i])
           return false;
           }
           return true;
    }