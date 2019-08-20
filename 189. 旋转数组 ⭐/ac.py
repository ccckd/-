



class Solution:
    x = 0
           
    def exchange(self, nums, st, count, k, orgin):
        self.x += 1
        to = (st + k) % len(nums)
        count += 1
        if to != orgin:
            self.exchange(nums, to, count, k, orgin)
        if count == 1:
            return
        nums[st], nums[to] = nums[to], nums[st] 

    def rotate(self, nums, k):
            """
            Do not return anything, modify nums in-place instead.
            """
            n = len(nums)
            k %= n
            for i in range(n):
                self.exchange(nums, i, 0, k, i)
                if self.x == n:
                    return



if __name__ == "__main__":
    S = Solution()
    S.rotate([1, 2, 3, 4, 5, 6], 4)