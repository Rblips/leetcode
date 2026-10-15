class Solution:
    def sumCounts(self, nums):
        ans = 0

        for i in range(len(nums)):
            distinct = set()

            for j in range(i, len(nums)):
                distinct.add(nums[j])
                ans += len(distinct) ** 2

        return ans