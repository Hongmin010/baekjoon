#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T,N;
long long tmp;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        priority_queue<__int128,vector<__int128>,greater<__int128>> pq;
        __int128 ans=1;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>tmp;
            pq.push(tmp);
        }
        if(N==1){
            cout<<1<<'\n';
            continue;
        }
        while(pq.size()!=1){
            __int128 A=pq.top();
            pq.pop();
            __int128 B=pq.top();
            pq.pop();
            __int128 n=(A*B)%1000000007;
            ans=(__int128)ans*n;
            ans=ans%1000000007;
            pq.push(A*B);
        }
        cout<<(long long)ans<<'\n';
        pq.pop();
    }
    return 0;
}
