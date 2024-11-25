#User function Template for python3
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr):
		# code here
		maxi = arr[0]
        mini = arr[0]
        ans = arr[0]
        
        # Traverse the array starting from the second element
        for i in range(1, len(arr)):
            
            # If the current number is negative, swap max and min
            if arr[i] < 0:
                maxi, mini = mini, maxi
            
            # Update max_product and min_product
            maxi = max(arr[i], maxi*arr[i])
            mini = min(arr[i], mini*arr[i])
            
            # Update the result
            ans = max(ans, maxi)
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr)
        print(ans)
        tc -= 1

# } Driver Code Ends