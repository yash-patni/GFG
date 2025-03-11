#User function Template for python3
class Solution:
	def maxSumIS(self, arr):
		# code here
        n=len(arr)
        ans=arr[0]
        dp=arr[:]
        for i in range(1, n):
            for j in range(i):
                if arr[i]>arr[j] and dp[i]<arr[i]+dp[j]:
                    dp[i]=arr[i]+dp[j]
            ans=max(ans, dp[i])
        
        return ans

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        # n = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.maxSumIS(arr)
        print(ans)

        print("~")

# } Driver Code Ends