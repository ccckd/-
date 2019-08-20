class Solution(object):
	def increasingTriplet(self, nums):
		"""
		:type nums: List[int]
		:rtype: bool
		"""
		a, b = float('inf'), float('inf')
		for n in nums:
			if n < a: a = n
			elif n > a and n < b:
				b = n
			elif n > b:
				return True

		return False
            

s = Solution()
print(s.increasingTriplet([1, 2, 0, 4]))