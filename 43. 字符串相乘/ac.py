class Solution:
    def multiply(self, num1, num2):
        l1, l2 = len(num1), len(num2)
        x, y = 0, 0
        for char in num1:
            x += (ord(char) - 48) * pow(10, l1 - 1) 
            l1 -= 1
        for char in num2:
            y += (ord(char) - 48) * pow(10, l2 - 1) 
            l2 -= 1

        res = ''
        out = x * y
        if not out:
            return '0'
        while out != 0:
            res += chr(out % 10 + 48)
            out = out // 10
        return res[::-1]



s = Solution()
print(s.multiply('3', '2'))