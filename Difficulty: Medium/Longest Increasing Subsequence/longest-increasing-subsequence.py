class Solution:
    def lis(self, arr):
        # code here
        c=1
        l=[]
        l.append(arr[0])
        for i in arr:
            if l[-1]<i:
                l.append(i)
                c+=1
            else:
                for j in range(c):
                    if l[j]==i:
                        break
                    if l[j]>i:
                        l[j]=i
                        break
        return c 



#{ 
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    for _ in range(int(input())):
        a = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.lis(a))
        print("~")
# } Driver Code Ends