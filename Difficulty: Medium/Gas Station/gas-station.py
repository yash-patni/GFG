class Solution:
    def startStation(self, gas, cost):
        # Your code here
        if sum(gas) < sum(cost):
            return -1
        start_index = 0
        current_gas = 0
        
        for i in range(len(gas)):
            current_gas += gas[i] - cost[i]
            if current_gas < 0:
                start_index = i + 1
                current_gas = 0
        return start_index


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        gas = list(map(int, input().strip().split()))
        cost = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.startStation(gas, cost)
        print(ans)
        print("~")

# } Driver Code Ends