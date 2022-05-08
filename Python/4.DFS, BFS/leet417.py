# There is an m x n rectangular island that borders both the Pacific Ocean and
# Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and
# the Atlantic Ocean touches the island's right and bottom edges.
#
#  The island is partitioned into a grid of square cells. You are given an m x
# n integer matrix heights where heights[r][c] represents the height above sea
# level of the cell at coordinate (r, c).
#
#  The island receives a lot of rain, and the rain water can flow to
# neighboring cells directly north, south, east, and west if the neighboring cell's height
# is less than or equal to the current cell's height. Water can flow from any cell
# adjacent to an ocean into the ocean.
#
#  Return a 2D list of grid coordinates result where result[i] = [ri, ci]
# denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic
# oceans.
#
#
#  Example 1:
#
#
# Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
#
# Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
#
#
#  Example 2:
#
#
# Input: heights = [[2,1],[1,2]]
# Output: [[0,0],[0,1],[1,0],[1,1]]
#
#
#
#  Constraints:
#
#
#  m == heights.length
#  n == heights[r].length
#  1 <= m, n <= 200
#  0 <= heights[r][c] <= 10⁵
#
#  Related Topics Array Depth-First Search Breadth-First Search Matrix 👍 3549 ?
# ? 808


# leetcode submit region begin(Prohibit modification and deletion)
from collections import deque

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        dir_n1 = [-1,1,0,0]
        dir_n2 = [0,0,-1,1]
        N = len(heights)
        M = len(heights[0])

        visit1 = [[0]*M for _ in range(N)]
        visit2 = [[0]*M for _ in range(N)]

        Queue1 = deque()
        Queue2 = deque()

        for n1 in range(N):
            Queue1.append((n1, 0, heights[n1][0]))
            Queue2.append((n1, M-1, heights[n1][M-1]))
            visit1[n1][0] = 1
            visit2[n1][M-1] = 1

        for n2 in range(M):
            Queue1.append((0, n2, heights[0][n2]))
            Queue2.append((N-1, n2, heights[N-1][n2]))
            visit1[0][n2] = 1
            visit2[N-1][n2] = 1

        while Queue1:
            cur_n1, cur_n2, cur_h = Queue1.popleft()

            for i in range(4):
                next_n1 = cur_n1 + dir_n1[i]
                next_n2 = cur_n2 + dir_n2[i]
                if next_n1 < 0 or next_n1 > N-1 or next_n2 < 0 or next_n2 > M-1 or visit1[next_n1][next_n2] == 1 or heights[next_n1][next_n2]<cur_h:
                    continue
                Queue1.append((next_n1, next_n2, heights[next_n1][next_n2]))
                visit1[next_n1][next_n2] = 1

        while Queue2:
            cur_n1, cur_n2, cur_h = Queue2.popleft()

            for i in range(4):
                next_n1 = cur_n1 + dir_n1[i]
                next_n2 = cur_n2 + dir_n2[i]
                if next_n1 < 0 or next_n1 > N - 1 or next_n2 < 0 or next_n2 > M - 1 or visit2[next_n1][next_n2] == 1 or heights[next_n1][next_n2] < cur_h:
                    continue
                Queue2.append((next_n1, next_n2, heights[next_n1][next_n2]))
                visit2[next_n1][next_n2] = 1

        ans = []
        for n1 in range(N):
            for n2 in range(M):
                if visit1[n1][n2] * visit2[n1][n2] == 1:
                    ans.append([n1, n2])

        return ans
# leetcode submit region end(Prohibit modification and deletion)
