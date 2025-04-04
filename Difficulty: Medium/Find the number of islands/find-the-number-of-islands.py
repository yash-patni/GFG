#User function Template for python3

class Solution:
    def numIslands(self, grid):
        # code here
        if not grid or not grid[0]: 
            return 0
        
        rows = len(grid)
        columns = len(grid[0])
        visited = [[False for _ in range(columns)] for _ in range(rows)]
        island_count = 0
        
        def visit_neighbours(i, j):
            if i < 0 or i >= rows or j < 0 or j >= columns:
                return
            if visited[i][j] or grid[i][j] == 'W':
                return
            
            visited[i][j] = True
            
            directions = [(-1, -1), (-1, 0), (-1, 1), 
                          (0, -1),         (0, 1), 
                          (1, -1), (1, 0), (1, 1)]
            
            for dx, dy in directions:
                visit_neighbours(i + dx, j + dy)
        
        for i in range(rows):
            for j in range(columns):
                if not visited[i][j] and grid[i][j] == 'L':
                    island_count += 1
                    visit_neighbours(i, j)
        
        return island_count
        

#{ 
 # Driver Code Starts
# Driver code
if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input().strip())
        m = int(input().strip())
        grid = [input().strip().split() for _ in range(n)]

        obj = Solution()
        print(obj.numIslands(grid))
        print("~")

# } Driver Code Ends