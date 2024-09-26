#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000000];
void search(int l,int h);
int N,M,B,S,x;
int main(void) {
    cin>>N>>M;
    cin>>arr[0];
    B=arr[0];
    S=0;
    for(int i=1;i<N;i++){
        cin>>arr[i];
        if(B<arr[i])B=arr[i];
    }
    sort(arr,arr+N);
    search(S,B);
    cout<<x;




    return 0;
}


void search(int l,int h){
    if(l>h) return;
    int mid=(h+l)/2;
    long long sum=0;
    for(int i=0;i<N;i++){
        if(arr[i]-mid>0) sum+=arr[i]-mid;
    }
    if(sum>=M) {
        x=mid;
        search(mid+1,h);
    }
    if(sum<M){
        search(l,mid-1);
    }
}

