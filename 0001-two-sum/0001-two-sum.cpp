class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=0,sum=0;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                sum=nums[i]+nums[j];
                if(sum==target)
                {
                   return {i,j};
                }
               
            }
        }
        return {};
    } 
};