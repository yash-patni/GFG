class Solution:
    def equalPartition(self, arr):
        # code here
        N=len(arr)
        s = sum(arr)
        if s % 2 != 0:
            return False
            
        subsum = s//2
        dp = [[False] * (subsum+1) for _ in range(N+1)]
        
        for i in range(N+1):
            dp[i][0] = True

        for i in range(1, N+1):
            for j in range(1, subsum+1):
                if dp[i-1][j]:
                    dp[i][j] = True
                else:
                    b = j - arr[i-1]
                    if b >= 0:
                        dp[i][j] = dp[i-1][b]
        return dp[-1][-1]
        

#{ 
 # Driver Code Starts
import sys

input = sys.stdin.readline

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        if ob.equalPartition(arr):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends