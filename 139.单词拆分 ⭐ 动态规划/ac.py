class Solution:
    def wordBreak(self, s: str, wordDict):
        dp = []
        for i in range(len(s)):
            dp.append(False)
            
        for i in range(len(s)):
            if s[:i + 1] in wordDict:
                dp[i] = True
            for j in range(i-1, -1 , -1):
                if dp[j]:
                    if s[j+1 : i+1] in wordDict:
                        dp[i] = True
        return dp[len(s) - 1]
                
s = Solution()
print(s.wordBreak("applepenapple", ["apple","pen"]))