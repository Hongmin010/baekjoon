#include <iostream>
using namespace std;

int N;
int arr[16][16];
int dp[16][16][3]; 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][1][0] = 1; 
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (arr[y][x]) continue; 
            if (x + 1 < N && arr[y][x + 1] == 0) {
                dp[y][x + 1][0] += dp[y][x][0] + dp[y][x][2];
            }
            if (y + 1 < N && arr[y + 1][x] == 0) {
                dp[y + 1][x][1] += dp[y][x][1] + dp[y][x][2];
            }
            if (x + 1 < N && y + 1 < N &&arr[y][x + 1] == 0 &&arr[y + 1][x] == 0 &&arr[y + 1][x + 1] == 0) {
                dp[y + 1][x + 1][2] += dp[y][x][0] + dp[y][x][1] + dp[y][x][2];
            }
        }
    }

    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    return 0;
}
