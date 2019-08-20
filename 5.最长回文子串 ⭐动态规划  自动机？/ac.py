class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''先把长度为1和2的填完，再找更长的子串，满足关系：if s[i] == s[j]
        那么s[i] + s[i-1:j] + s[j]也是回文串'''
        n = len(s)
        if not n:
            return ''
        m = [['' for __ in range(n)] for _ in range(n)]
        max_l = 1
        res = s[0]
        for i in range(n):          
            m[i][i] = s[i]
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                m[i][i + 1] = s[i:i+2]
                max_l = 2
                res = s[i:i+2]
        for i in range(2, n):
            for j in range(n - i):
                if m[j+1][j+i-1] != '' and s[j] == s[j + i]:
                    m[j][j + i] = s[j:j+i+1]
                    if i + 1 > max_l:
                        max_l = i + 1
                        res = s[j:j+i+1]
        return res
                

                
if __name__ == "__main__":
    
    s = Solution()
    print(s.longestPalindrome("cbbd"))