# https://leetcode.com/problems/image-overlap/

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        ans = 0
        N = len(img1)
        
        for x in range(N):
            for y in range(N):
                temp = 0
                for i in range(x, N):
                    for j in range(y, N):
                        if img1[i-x][j-y] == 1 and img2[i][j] == 1:
                            temp += 1
                ans = max(ans, temp)
                
                temp = 0
                for i in range(N-x):
                    for j in range(y, N):
                        if img1[i+x][j-y] == 1 and img2[i][j] == 1:
                            temp += 1
                ans = max(ans, temp)
                
                temp = 0
                for i in range(x, N):
                    for j in range(N-y):
                        if img1[i-x][j+y] == 1 and img2[i][j] == 1:
                            temp += 1
                ans = max(ans, temp)
                
                temp = 0
                for i in range(N-x):
                    for j in range(N-y):
                        if img1[i+x][j+y] == 1 and img2[i][j] == 1:
                            temp += 1
                ans = max(ans, temp)

        return ans
                
        