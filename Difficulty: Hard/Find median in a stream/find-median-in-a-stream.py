
class Solution:
    def getMedian(self, arr):
        from heapq import heappush, heappop
        
        min_q, max_q, ans = [], [], []
        
        for e in arr:
            if min_q and e < abs(min_q[0]):
                heappush(min_q, -e)
            else:
                heappush(max_q, e)

            while len(min_q) > len(max_q) + 1:
                heappush(max_q, abs(heappop(min_q)))
            
            while len(max_q) > len(min_q) + 1:
                heappush(min_q, -heappop(max_q))
                
            if len(min_q) == len(max_q):
                m = (abs(min_q[0]) + abs(max_q[0])) / 2
            elif len(min_q) > len(max_q):
                m = abs(min_q[0])
            else:
                m = abs(max_q[0])
            ans.append(m)
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.getMedian(nums)
        print(" ".join(f"{x:.1f}" for x in ans))


if __name__ == "__main__":
    main()

# } Driver Code Ends