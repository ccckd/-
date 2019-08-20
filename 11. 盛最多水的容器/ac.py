class Solution:
    def maxArea(self, height):
        l, r= 0, len(height) - 1
        
        maxArea = 0
        while l < r:
            area = (r - l) * min(height[l], height[r])
            maxArea = area if area > maxArea else maxArea
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxArea
                
S = Solution()
print(S.maxArea([2,3,10,5,7,8,9]))