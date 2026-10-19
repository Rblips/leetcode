class Solution:
    def majorityElement(self, nums):
        candidate = 0
        count = 0

        for x in nums:
            if count == 0:
                candidate = x

            if x == candidate:
                count += 1
            else:
                count -= 1

        return candidate