class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs:
            comm_now = strs[0]
        else:
            return ''
            
        comm_new = ''
        for word in strs:
            i = 0
            while i < min(len(word), len(comm_now)):
                if word[i] == comm_now[i]:
                    comm_new += word[i]
                    i += 1
                else:
                    break
            comm_now = comm_new
            comm_new = ''
        return comm_now

if __name__ == "__main__":
    S = Solution()
    print(S.longestCommonPrefix(["aca","cba"]))