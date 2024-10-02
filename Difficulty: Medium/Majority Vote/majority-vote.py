class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, nums):
        if not nums:
            return -1
            
        c1, c2 = None, None
        count1, count2 = 0, 0
        
        for num in nums:
            if c1 == num:
                count1 += 1
            elif c2 == num:
                count2 += 1
            elif count1 == 0:
                c1, count1 = num, 1
            elif count2 == 0:
                c2, count2 = num, 1
            else:
                count1 -= 1
                count2 -= 1
        
        count1, count2 = 0, 0
        for num in nums:
            if num == c1:
                count1 += 1
            elif num == c2:
                count2 += 1
        result = []
        n = len(nums)
        if count1 > n // 3:
            result.append(c1)
        if count2 > n // 3:
            result.append(c2)
        return result if result else [-1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.findMajority(nums)
        print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()

# } Driver Code Ends