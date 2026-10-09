// Graph problems on a grid (LeetCode)
// 1) 733. Flood Fill
// 2) 994. Rotting Oranges
//
// Compile & run on Mac:
//   g++ -std=c++17 graph_flood_fill_rotting_oranges.cpp -o out && ./out

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // ---------- 733. Flood Fill (DFS) ----------
    // Idea: start at (sr, sc). Change its color, then spread to the
    // 4 neighbors (up, down, left, right) that have the OLD color.
    // Time: O(m * n), Space: O(m * n) recursion in the worst case.
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;  // nothing to change, avoids infinite loop
        dfs(image, sr, sc, oldColor, color);
        return image;
    }

    // ---------- 994. Rotting Oranges (multi-source BFS) ----------
    // Idea: all rotten oranges start rotting their neighbors at the same time.
    // Put every rotten orange in the queue first, then spread minute by minute.
    // Time: O(m * n), Space: O(m * n).
    // Returns minutes needed, or -1 if some fresh orange can never rot.
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size();  // everything in the queue rots its neighbors this minute
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                    if (grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;  // fresh -> rotten
                    fresh--;
                    q.push({nr, nc});
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }

private:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if (r < 0 || c < 0 || r >= (int)image.size() || c >= (int)image[0].size()) return;
        if (image[r][c] != oldColor) return;

        image[r][c] = newColor;
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }
};

// ---------- Quick local test (not needed on LeetCode) ----------
int main() {
    Solution s;

    // Flood Fill test
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> result = s.floodFill(image, 1, 1, 2);
    cout << "Flood Fill result:\n";
    for (auto& row : result) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    // Rotting Oranges test
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Rotting Oranges minutes: " << s.orangesRotting(grid) << "\n";  // expected 4

    return 0;
}
