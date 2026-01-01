/*
PATTERN: Multi-Source BFS (Time Spread)
Each BFS layer = 1 minute
Used in: virus spread, fire spread, flood fill, network broadcast
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();    //number of rows
        int n = grid[0].size(); //number of columns;

        queue<pair<int, int>> q; // BFS queue storign rotten oranges
        int fresh = 0;  // count of fresh ones

        // Step 1: Push all intial rotten oranges & count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({ i,j });  // rotten orange position
                else if (grid[i][j] == 1)    fresh++;    // count fresh oranges
            }
        }
        int minutes = 0;

        // Direction: Right, Down, Left, Up
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };

        // Step 2: BFS layer by layer (each layer = 1 minute)
        while (!q.empty() && fresh > 0) {
            int size = q.size();    // number of rotten ornages at this minute

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                // Explore 4 directions
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i]; // next row
                    int ny = y + dy[i]; // next column

                    // If inside grid and it's a fresh orange, rot it
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;   // make it rotten 
                        fresh--;       // one less fresh orange
                        q.push({ nx, ny });   // process it in next minute
                    }
                }
            }
            minutes++;  // one minute passed
        }
        // If no fresh ornages left, return minutes, else return -1
        return fresh == 0 ? minutes : -1;
    }
};