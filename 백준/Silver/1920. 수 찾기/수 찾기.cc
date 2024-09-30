#include<iostream>
#include<algorithm>
using namespace std;
int search(int a, int b[], int, int);
int* a, * b;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;
    a = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> M;
    b = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    sort(a, a + N);
    for (int i = 0; i < M; i++) {
        cout << search(b[i], a, 0, N - 1) <<"\n";
    }
    return 0;
}

int search(int a, int* b, int l, int h) {
    if (l>h) return 0;
    int mid = (l + h) / 2;
    if (b[mid] > a) {
        return search(a, b, l, mid-1);
    }
    else if (b[mid] < a) {
        return search(a, b, mid+1, h);
    }
    else return 1;
    

}
