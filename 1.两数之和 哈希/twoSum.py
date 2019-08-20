class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for index, num in enumerate(nums):
            if target - num in dic:
                if target - num == num:                
                    return [nums.index(num), index]
                else:
                    return sorted([nums.index(num), nums.index(target - num)])
            else:
                dic[num] = num

if __name__ == "__main__":
    S = Solution()
    print(S.twoSum([3, 3], 6))