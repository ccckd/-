class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return nums
        i = 0
        while i < len(nums) - 1:
            try:
                while nums[i + 1] == nums[i]:
                    del nums[i + 1]
            except:
                return nums
            i += 1
        return nums


if __name__ == "__main__":
    S = Solution()
    print(S.removeDuplicates([1,1,2, 2, 3, 3, 4]))