#User function Template for python3
class Solution:
    # Function to get the maximum total value in the knapsack.
    def fractionalknapsack(self, val, wt, capacity):
        #code here
        n=len(val)
        fk=[]
        for i in range(n):
            fk.append((val[i], wt[i], val[i]/wt[i]))
        
        fk.sort(key=lambda x: x[2], reverse=True)
        
        total=0
        for i in range(n):
            if capacity>=fk[i][1]:
                total+=fk[i][0]
                capacity-=fk[i][1]
            else:
                total=total+(fk[i][2]*capacity)
                break

        return total

#{ 
 # Driver Code Starts
#Position this line where user code will be pasted.

if __name__ == '__main__':
    test_cases = int(input())
    for _ in range(test_cases):
        # Read values array
        values = list(map(int, input().strip().split()))

        # Read weights array
        weights = list(map(int, input().strip().split()))

        # Read the knapsack capacity
        W = int(input().strip())

        ob = Solution()
        print("%.6f" % ob.fractionalknapsack(values, weights, W))
        print("~")

# } Driver Code Ends