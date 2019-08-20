class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        if len(s) == 0:
            return []
        elif len(s) == 1:
            return [[s]]
        
        ans = []
        for x in self.partition(s[:-1]):
            ans.append(x + [s[-1]])
            if s[-1]==x[-1] or (len(set(x[-1]))==1 and s[-1]==x[-1][0]):
                ans.append(x[:-1] + [x[-1]+s[-1]])
            elif (len(x)>1 and s[-1]==x[-2]):
                ans.append(x[:-2] + [x[-2]+x[-1]+s[-1]])
        return ans