class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        dic = { 'I': 1,
                'V': 5,
                'X': 10,
                'L': 50,
                'C': 100,
                'D': 500,
                'M': 1000,
                'IV': 4,
                'IX': 9,
                'XL': 40,
                'XC': 90,
                'CD': 400,
                'CM': 900,
                'O' : 0}
        ans = 0
        i = 0
        while i < len(s):
            try:
                if s[i] + s[i + 1] in dic:
                    ans += dic[s[i] + s[i + 1]]
                    i += 1
                else:
                    ans += dic[s[i]]
            except:
                ans += dic[s[i]]
            i += 1
        return ans


if __name__ == "__main__":
    S = Solution()
    print(S.romanToInt('MCMXCIV'))