#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

class Solution:
    def getMaxArea(self, hist):
        #code here
        stack = []
        maxArea = 0
        n = len(hist)
        for i in range(n):
            while stack and hist[stack[-1]] > hist[i]:
                element = stack.pop()
                nse = i
                pse = stack[-1] if stack else -1
                maxArea = max(hist[element] * (nse - pse - 1), maxArea)
            stack.append(i)
        while stack:
            nse = n
            element = stack.pop()
            pse = stack[-1] if stack else -1
            maxArea = max(hist[element] * (nse - pse - 1), maxArea)
        return maxArea



#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.getMaxArea(arr)
        print(res)
        print("~")
        t -= 1


# } Driver Code Ends