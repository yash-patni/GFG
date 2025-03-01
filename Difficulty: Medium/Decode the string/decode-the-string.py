
class Solution:
    def decodedString(self, s):
        # code here
        stack=[]
        for item in s:
            if item=="]":
                curr=""
                while stack and stack[-1]!="[":
                    curr=stack.pop()+curr
                stack.pop()
                val=""
                while stack and stack[-1].isnumeric():
                    val=stack.pop()+val
                stack.append(curr*int(val))
            else:
                stack.append(item)
            ans=""
        while stack:
            ans=stack.pop()+ans
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()

        ob = Solution()
        print(ob.decodedString(s))
        print("~")

# } Driver Code Ends