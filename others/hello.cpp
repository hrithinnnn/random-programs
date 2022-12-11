// C++ program to sort an array in
// decreasing order of their frequency
#include "bits/stdc++.h"
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[20000];
		int max=0;
		int max1=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>max){
				max=a[i];
			}
		}
			for(int i=0;i<n;i++){
			if(a[i]>max1 && a[i]!=max ){
				max1=a[i];
			}
			}
		
		//cout<<max<<max1;
		for(int i=0;i<n;i++){
			if(a[i]!=max){
				cout<<a[i]-max<<" ";
			}
			else{
				cout<<a[i]-max1<<" ";
			}
		
		}
		cout<<endl;
	}
	return 0;
}