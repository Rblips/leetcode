class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current=0,maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                current++;
                maxi=max(maxi,current);
            }
            else{
                current=0;
            }

        }
        return maxi;
        
    }
};