class Solution {
public:
    struct Info{
    int x;
    int y;
    int lvl;   // time (minute) when this orange becomes rotten
};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();

    queue<Info> q;
    int freshOranges = 0;

    // Push all initially rotten oranges and count fresh ones
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2)
                q.push({i,j,0});     // start BFS from all rotten oranges
            else if(grid[i][j] == 1)
                freshOranges++;
        }
    }

    if(freshOranges == 0) return 0;  // no fresh oranges → no time needed

    int time = 0;

    // 4-direction movement
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};

    while(!q.empty()){

        Info curr = q.front();
        q.pop();

        int currX = curr.x;
        int currY = curr.y;
        time = curr.lvl;   // update time with the latest rotting minute

        for(int k = 0; k < 4; k++){

            int newX = currX + dx[k];
            int newY = currY + dy[k];

            // If adjacent cell has a fresh orange
            if(newX >= 0 && newX < n &&
               newY >= 0 && newY < m &&
               grid[newX][newY] == 1){

                grid[newX][newY] = 2;        // mark it rotten immediately
                freshOranges--;           // reduce fresh count
                q.push({newX,newY,time+1}); // push with next minute
            }
        }
    }

    // if some fresh oranges remain → impossible
    return freshOranges == 0 ? time : -1;
    }
};