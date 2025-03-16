class Solution:
	def minJumps(self, arr):
	    # code here
        n=len(arr)
        jumps,maxRange,currRange=0,0,0
        for i in range(n-1):
            maxRange=max(maxRange,arr[i]+i)
            if i==currRange:
                if maxRange<=i:
                    return -1
                currRange=maxRange
                jumps+=1
        return jumps

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        # n = int(input())
        Arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.minJumps(Arr)
        print(ans)
        print("~")
# } Driver Code Ends