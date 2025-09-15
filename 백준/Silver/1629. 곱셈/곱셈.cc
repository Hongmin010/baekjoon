    #include<iostream>
    #include<cmath>
    long long pw(long long,long long,long long);
    using namespace std;
    long long A,B,C,ans;
    int main(void){
        cin>>A>>B>>C;
        cout<<pw(A,B,C);
        return 0;
    }

    long long pw(long long A, long long B, long long C){
        if(B==1) return A%C;
        if(B%2>0) {
            int n= pw(A,(B-1)/2,C);
            return A%C * n%C *n%C %C;
        }
        int n = pw(A,B/2,C);
        return n%C * n%C %C;
    }

    
