#include <iostream>
using namespace std;

int main(void){
    int T,K;
	cin >> T;
    int arr[T];
	cin >> K;
    int n=0;
    for(int i=0;i<T;i++) cin >> arr[T-1-i] ;
    for(int i=0;i<T;i++){
		n+=K/arr[i];
		K%=arr[i];
	}    
    
    cout << n;
	
return 0;
}
