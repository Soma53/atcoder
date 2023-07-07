#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
char field[510][510];
bool reached[510][510];
int H, W;
// queue<pair<int, int>> q;
queue<tuple<int, int, int>> q;

// void bfs(queue<pair<int, int>> &q, string target) {
//     while(!q.empty()){
//         auto [x, y] = q.front();
//         q.pop();

//         for(int i=0; i<4; ++i){
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
//             if(field[nx][ny] != target[(target.find(field[x][y])+1)%5]) continue;
//             if(reached[nx][ny]) continue;

//             reached[nx][ny] = true;
//             q.push({nx, ny});
//         }
//     }
// }

void bfs(queue<tuple<int, int, int>> &q, string target){
    while(!q.empty()){
        auto [x, y, idx] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(field[nx][ny] != target[(idx+1)%5]) continue;
            if(reached[nx][ny]) continue;

            reached[nx][ny] = true;
            q.push({nx, ny, (idx+1)%5});
        }
    }
}

int main(){
    cin >> H >> W;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            cin >> field[i][j];
        }
    }

    memset(reached, 0, sizeof(reached));
    q.push({0, 0, 0});
    reached[0][0] = true;
    bfs(q, "snuke");

    cout << (reached[H-1][W-1] ? "Yes" : "No") << endl;

    return 0;
}
