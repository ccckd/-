class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        l1 = len(nums1)
        l2 = len(nums2)
        mid1 = int(l1 / 2)
        if l1 % 2:
            nums1_mid = nums1[mid1]
        else:
            nums1_mid = (nums1[mid1] + nums1[mid1 - 1]) / 2
        

        mid2 = int(l2 / 2)
        if l2 % 2:
            nums2_mid = nums2[mid2]
        else:
            nums2_mid = (nums2[mid2] + nums2[mid2 - 1]) / 2

        if nums1_mid > nums2_mid:
            temp = nums1
            nums1 = nums2
            nums2 = temp
            temp = mid1
            mid1 = mid2
            mid2 = temp
            temp = nums1_mid
            nums1_mid = nums2_mid
            nums2_mid = temp

        
        while 1:
            
            mid1_new = int(mid1 + (len(nums1) - 1) / 2)
            if len(nums1[mid1_new:len(nums1)]) % 2:
                nums1_mid = nums1[mid1]
            else:
                nums1_mid = (nums1[mid1] + nums1[mid1 - 1]) / 2


            mid2_new = int(0 + mid2/ 2)
            if len(nums2[:mid2_new + 1]) % 2:
                nums2_mid = nums2[mid2]
            else:
                nums2_mid = (nums2[mid2] + nums2[mid2 - 1]) / 2

            if nums1_mid >= nums2_mid:
                nums1_mid = nums1[mid1]
                nums2_mid = nums2[mid2]
                break
            elif mid1 == len(nums1) - 1 or mid2 == 0:
                mid1 = mid1_new
                mid2 = mid2_new
                break
            else:
                mid1 = mid1_new
                mid2 = mid2_new
            
            new = nums1 + nums2
            mid2 += len(nums1)
            new = new[:mid1] + sorted(new[mid1:mid2 + 1]) + new[mid2 + 1:]
            new_len = len(new)
            mid_new = int(new_len / 2)
            if new_len % 2:
                return new[mid_new]
            else:
                return (new[mid_new] + new[mid_new - 1]) / 2
            



if __name__ == "__main__":
    S = Solution()
    print(S.findMedianSortedArrays([1, 3], [2]))