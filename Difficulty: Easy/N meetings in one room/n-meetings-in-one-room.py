#User function Template for python3

class Solution:
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,start,end):
        # code here
        ls = []
        n = len(start)
        for i in range(n):
            ls.append((start[i], end[i]))
        
        ls.sort(key = lambda x:x[1])
        ans=-1
        count=0
        for s, e in ls:
            if s>ans:
                ans=e
                count+=1
        
        return count

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        start = list(map(int, input().strip().split()))
        end = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.maximumMeetings(start, end))
        print("~")

# } Driver Code Ends