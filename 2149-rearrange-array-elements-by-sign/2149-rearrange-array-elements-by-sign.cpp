class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos(nums.size()/2);
        vector<int> neg(nums.size()/2);
        vector<int> arr(nums.size());

        int p = 0;
        int n = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                pos[p] = nums[i];
                p++;
            }
            else
            {
                neg[n] = nums[i];
                n++;
            }
        }

        for(int i = 0; i < nums.size()/2; i++)
        {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        return arr;
    }
};