class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for num in nums:
            a = a ^ num
        return a


s = Solution()
s.singleNumber([8, 2, 3, 2, 3])


'''
这个题用异或操作可以巧妙的解决，任意数异或0都等于0，且任何数异或同一个数两次会变成原来的数。
异或还可以用来交换A B 
A = A ^ B  
B = A ^ B
A = A ^ B
'''