class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, arr):
        #Your Code goes here.
        n=len(arr)
        if n<=2:
            return arr
        ans=[]
        arr.sort()
        count=1
        for i in range(1,n):
            if arr[i]==arr[i-1]:
                count+=1
            else :
                if count>n//3:
                    ans.append(arr[i-1])
                count=1
        
        if count>n//3:
            ans.append(arr[-1])
        
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
        ans = ob.findMajority(nums)
        if not ans:
            print("[]")
        else:
            print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()

# } Driver Code Ends