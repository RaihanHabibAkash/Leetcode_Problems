// Problem: Even Number of Knight Moves
// Platform: LeetCode
// Difficulty: Eas;y
// Link: https://leetcode.com/problems/even-number-of-knight-moves/
// Topics: 2D Grid BFS, level tracker
/*
You are given two integer arrays start and target, where each array is of the form [x, y] representing a cell on a standard 8 x 8 chessboard.

Return true if a knight can move from start to target in an even number of moves. Otherwise, return false.

Note: A valid knight move consists of moving two squares in one direction and one square perpendicular to it. The figure below illustrates all eight possible moves from a cell.



 

Example 1:

Input: start = [1,1], target = [2,2]

Output: true

Explanation:

One possible sequence of moves is (1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2).

The knight reaches the target in 4 moves, which is even. Thus, the answer is true.

Example 2:

Input: start = [4,5], target = [6,6]

Output: false

Explanation:​​​​​​​

It is impossible to reach target = [6, 6] from start = [4, 5] in an even number of moves. Thus, the answer is false.

 

Constraints:

start.length == target.length == 2
0 <= start[i], target[i] <= 7
*/
class Solution {
public:
    bool vis[8][8];
    int lvl[8][8];
    vector<pair<int,int>> knight_mv = {{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{2,1},{1,2},{-1,2}};

    bool valid(int i, int j) {
        if(i < 0 || i >= 8 || j < 0 || j >= 8)
            return false;
        return true;
    }

    void bfs(int si, int sj) {
        queue<pair<int,int>> q;
        vis[si][sj] = true;
        lvl[si][sj] = 0;
        q.push({si,sj});

        while(!q.empty()) {
            int pi = q.front().first,
                pj = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++) {
                int ci = pi + knight_mv[i].first,
                    cj = pj + knight_mv[i].second;
                if(valid(ci,cj) && !vis[ci][cj]) {
                    vis[ci][cj] = true;
                    lvl[ci][cj] = lvl[pi][pj] + 1;
                    q.push({ci,cj});
                }
            }
        }
    }

    bool canReach(vector<int>& start, vector<int>& target) {
        memset(vis, false, sizeof(vis));
        memset(lvl, -1, sizeof(lvl));

        int si = start[0],
            sj = start[1],
            di = target[0],
            dj = target[1];
        
        bfs(si, sj);

        if(vis[di][dj] && !(lvl[di][dj] % 2) ) return true;
        return false;
    }
};