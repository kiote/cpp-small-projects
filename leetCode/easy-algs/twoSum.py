import pprint 

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i, n in enumerate(nums):
            for j, k in enumerate(nums[i+1:-1]):
                if (n+k == target):
                    return [n, k]


solution = Solution()
pprint.pprint(solution.twoSum([2, 4, 5, 7], 9))
