class Solution:
    def maxProduct(self, A):
        B = A[::-1]
        for i in range(1, len(A)):
            A[i] *= A[i - 1]
            B[i] *= B[i - 1]
        return max(max(A),max(B)) 
         




S = Solution()
print(S.maxProduct([-3,0,1,-2]))