import pprint 

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        i=0
        while (i < len(nums)-1):
            j = i + 1
            while (j <= len(nums)-1):
                if (nums[i] + nums[j] == target):
                    return [i, j]
                j += 1
            i += 1


solution = Solution()
pprint.pprint(solution.twoSum([2, 4, 5, 7], 9))
