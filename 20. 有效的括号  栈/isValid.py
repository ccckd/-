class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True

        stack = []
        stack.append(s[0])
        for char in s[1:]:
            if not stack:
                stack.append(char)
                continue
            if stack[len(stack) - 1] == '{' and char =='}':
                stack.pop()
            elif stack[len(stack) - 1] == '[' and char ==']':
                stack.pop()
            elif stack[len(stack) - 1] == '(' and char ==')':
                stack.pop()
            else:
                stack.append(char)
        if stack:
            return False
        else:
            return True   

if __name__ == "__main__":
    S = Solution()
    print(S.isValid("()[]{}"))