class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        n = len(deadline)
        jobs = sorted(zip(profit, deadline), key=lambda x: -x[0])
        max_deadline = max(deadline)
        parent = list(range(max_deadline + 1))  # DSU parent array
        
        def find(x):
            if parent[x] == x:
                return x
            parent[x] = find(parent[x])  # Path compression
            return parent[x]
        
        job_count = 0
        total_profit = 0
        
        for p, d in jobs:
            available_slot = find(min(d, max_deadline))
            if available_slot > 0:
                parent[available_slot] = find(available_slot - 1)  # Union step
                job_count += 1
                total_profit += p
        
        return [job_count, total_profit]

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq

#Position this line where user code will be pasted.

if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        deadline = list(map(int, input().strip().split()))
        profit = list(map(int, input().strip().split()))

        obj = Solution()
        ans = obj.jobSequencing(deadline, profit)
        print(ans[0], ans[1])
        print("~")
# } Driver Code Ends