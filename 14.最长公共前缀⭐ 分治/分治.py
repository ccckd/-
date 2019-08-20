def divide(strs, left, right):
    if left == right:
            return strs[left]
    else:
        mid = int((left + right) / 2)
        LCPleft = divide(strs, left, mid)
        LCPright = divide(strs, mid + 1, right)

    comm = ''
    i = 0
    while i < min(len(LCPleft), len(LCPright)):
        if LCPleft[i] == LCPright[i]:
            comm += LCPleft[i]
            i += 1
        else:
            break
    return comm






class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs:
            return divide(strs, 0, len(strs) - 1)
        else:
            return ''
       


if __name__ == "__main__":
    S = Solution()
    print(S.longestCommonPrefix(["flower","flow","flight"]))