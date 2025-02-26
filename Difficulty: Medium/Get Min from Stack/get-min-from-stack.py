class Solution:

    def __init__(self):
        self.s = []
        self.minEle = None

    # Add an element to the top of Stack
    def push(self, x):
        if not self.s:
            self.s.append((x, x))
        else:
            self.s.append((x, min(x, self.s[-1][1])))

    # Remove the top element from the Stack
    def pop(self):
        if not self.s:
            return
        self.s.pop()

    # Returns top element of the Stack
    def peek(self):
        if not self.s:
            return -1
        return self.s[-1][0]

    # Finds minimum element of Stack
    def getMin(self):
        if not self.s:
            return -1
        return self.s[-1][1]




#{ 
 # Driver Code Starts
# Driver Code
if __name__ == '__main__':
    t = int(input())  # Number of test cases

    for _ in range(t):
        q = int(input())  # Number of queries
        stk = Solution()  # Initialize stack
        results = []

        for _ in range(q):
            query = list(map(int, input().split()))

            if query[0] == 1:
                stk.push(query[1])  # Push operation
            elif query[0] == 2:
                stk.pop()  # Pop operation (no return value)
            elif query[0] == 3:
                results.append(str(stk.peek()))  # Peek operation
            elif query[0] == 4:
                results.append(str(stk.getMin()))  # GetMin operation

        print(" ".join(results))  # Print all results in one line
        print("~")

# } Driver Code Ends