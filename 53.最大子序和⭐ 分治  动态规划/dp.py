class Solution:
    def maxSubArray(self, nums):
        """
        动态规划
        线性时间复杂度
        dp[i]代表以i元素结尾的最大和子序列
        """
        max_sum = float('-inf')
        this_sum = 0
        left = 0
        right = 0
        for i in range(0, len(nums)):
            if this_sum + nums[i] > nums[i]:
                right += 1
                this_sum += nums[i]
            else:
                left = i
                right = i
                this_sum = nums[i]
            if this_sum > max_sum:
                max_sum = this_sum
                l = left
                r = right
        return l, r, max_sum