
class Solution:
    def isCycle(self, V, edges):
        # code here
        graph = [[] for _ in range(V)]
        for u, v in edges:
            graph[u].append(v)
        
        visited = [False] * V
        recursion_stack = [False] * V
        
        def has_cycle(node):
            visited[node] = True
            recursion_stack[node] = True
            
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    if has_cycle(neighbor):
                        return True
                elif recursion_stack[neighbor]:
                    return True
            
            recursion_stack[node] = False
            return False
        
        for i in range(V):
            if not visited[i]:
                if has_cycle(i):
                    return True
        
        return False

#{ 
 # Driver Code Starts
from collections import deque


def main():
    tc = int(input())
    for _ in range(tc):
        V = int(input())
        E = int(input())
        edges = []
        for _ in range(E):
            u, v = map(int, input().split())
            edges.append((u, v))

        obj = Solution()
        ans = obj.isCycle(V, edges)
        print("true" if ans else "false")


if __name__ == "__main__":
    main()

# } Driver Code Ends