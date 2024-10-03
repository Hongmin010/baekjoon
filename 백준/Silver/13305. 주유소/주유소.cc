#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

long long dis[100001];
long long pri[100001];
int main(void) {
   int N,t=1,k=0;
   long long ans=0;
   cin>>N;
   for(int i=0;i<N-1;i++){
    cin>>dis[i];
   }
   for(int i=0;i<N;i++){
    cin>>pri[i];
   }
    while(k<N){
        if(pri[k]<pri[t]){
            t++;
            continue;
        }
        else{
            for(int i=k;i<t;i++){
                ans+=pri[k]*dis[i];
            }
            k=t;
            t++;
        }
    }
    cout<<ans;



    return 0;
}




