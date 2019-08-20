class Solution:
    temp = []
    res = []
    def partition(self, s):
        
        self.f(s, 0, self.temp)
        return self.res
    

    def f(self, s, l, temp):

        if l == len(s):
            self.res.append(list(temp))
            # temp.pop(-1)
            return 

        for i in range(l, len(s)):
            t = s[l : i + 1]
            if t == t[::-1]:
                temp.append(t)
                self.f(s, i+1, temp)
                temp.pop(-1)
            else:
                continue
        
s = Solution()
print(s.partition('a'))