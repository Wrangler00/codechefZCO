#include <iostream>
using namespace std;
#define LL long int
int main() {
	int n;
	cin>>n;
	
	LL a[n],b[n][2],i;
	
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}

    if(n==1){
        cout<<a[0];
        return 0;
    }
    
    if(n==2){
        cout<<a[0]+a[1];
        return 0;
    }
	
	b[0][0] = 0;
	b[0][1] = a[0];
	
	b[1][0] = a[1]+b[0][1];
	b[1][1] = a[1];
	
	for(i=2;i<n;i++){
	    b[i][0] = a[i]+b[i-1][1];
	    b[i][1] = a[i]+max(b[i-2][0],b[i-2][1]);
	}
	
	cout<<max(max(b[n-1][0],b[n-1][1]),max(b[n-2][0],b[n-2][1]));
	return 0;
}
