class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        dp = []
        n = len(s)
        for t in range(n):
            dp.append([list() for i in range(n)])
        for i in range(n):
            dp[i][i] = [[s[i]]]
        for i in range(2, n+1):
            for j in range(0 , n-i+1):
                t = s[j:j+i]
                if t == t[::-1]:
                    dp[j][j+i-1].append([t])
                for k in range(j, j+i-1):
                    t1 = s[j:k+1]
                    if t1 == t1[::-1]:
                        for v1 in dp[k+1][j+i-1]:
                            dp[j][j+i-1].append([t1] + v1)
                            
                
        return dp[0][n-1]


s =Solution()
print(s.partition('aabb'))