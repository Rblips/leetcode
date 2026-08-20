class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j)
        {
            int w=j-i;
            int h=min(height[i],height[j]);
            int area=w*h;https://leetcode.com/_next/static/images/light-pending-9c28f1f18993ec103b273778b5f6a648.gif$0
            ans=max(ans,area);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            j--;
        }
        return ans;
    }
};