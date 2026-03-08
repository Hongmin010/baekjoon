#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool promising(int y, int x);
void backTracking(int idx,int num, int color);
int chess_map[11][11];
int visited[11][11];
int N,max_num = 0;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>chess_map[i][j];
        }
    }
    backTracking(0,0,0);
    int num1 = max_num;
    max_num = 0;
    backTracking(0,0,1);    
    cout<< num1 + max_num;
    return 0;
}

bool promising(int y, int x){
    if(visited[y][x]) return false;
    if(!chess_map[y][x]) return false;
    for(int X = 0; X < N; X++){
        int Y = (x + y) - X;
        if(Y >= N or Y < 0) continue;
        if(visited[Y][X]) return false;
    }
    for(int X = 0 ; X < N; X++){
        int Y = X + (y - x);
        if(Y >= N or Y < 0) continue;
        if(visited[Y][X]) return false;
    }
    return true;
}

void backTracking(int idx,int num, int color){
    if(idx >= N*N){
        if(max_num<num) max_num = num;
        return;
    }
    int y = idx / N;
    int x = idx % N;
    if ((y + x) % 2 != color) {
        backTracking(idx + 1, num, color);
        return; 
    }
    if(promising(y,x)){
        visited[y][x] = true;
        backTracking(idx + 1, num + 1, color);
        visited[y][x] = false;
    }
    backTracking(idx + 1, num, color);
}