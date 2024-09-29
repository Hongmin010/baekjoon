#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000000];
void search(long long l,long long h);
int N,K,x,m;
int main(void) {
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>arr[i];
        if(m<arr[i]) m=arr[i];
        
    }
    search(1,m);
    cout<<x;

    return 0;
}


void search(long long l,long long h){
    if(l>h) return;
    long long mid=(h+l)/2;
    long long sum=0;
    for(int i=0;i<N;i++){
        sum+=arr[i]/mid;
    }
    if(sum>=N) {
        if(x<mid) x=mid;
        search(mid+1,h);
    }
    if(sum<N){
        search(l,mid-1);
    }
}

