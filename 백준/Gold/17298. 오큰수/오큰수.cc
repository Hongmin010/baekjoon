#include<iostream>
#include<stack>
using namespace std;
int arr[1000000];
int sol[1000000];
int N,tmp;
stack<int> st;
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        tmp=arr[N-1-i];
        while(!st.empty()){
            if(st.top()<=tmp) st.pop();
            else {
                sol[N-1-i]=st.top();
                break;
            }
        }
        if(st.empty()) sol[N-1-i]=-1;
        st.push(tmp);
    }
    for(int i=0;i<N;i++){
        cout<<sol[i]<<" ";
    }

    return 0;
}


