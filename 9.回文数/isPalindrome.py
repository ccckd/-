class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        i = 0
        j = len(x) - 1
        
        while i <= j:
            if x[i] != x[j]:
                return False
            else:
                i += 1
                j -= 1
        return True

if __name__ == "__main__":
    S = Solution()
    print(S.isPalindrome(0))