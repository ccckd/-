class Solution:
    def searchInsert(self, nums, target):
        """
        直接二分搜索
        """
        l, r = 0, len(nums) - 1
        while 1:
            if l >= r:
                if target == nums[l]:
                    return l
                elif target > nums[l]:
                    return l + 1
                else:
                    return l
            mid = int((l + r) / 2)
            if nums[mid] == target:
                return mid
            elif target > nums[mid]:
                l = mid + 1
            else:
                r = mid - 1

                

if __name__ == "__main__":
    S = Solution()
    print(S.searchInsert([1,3], 0))

