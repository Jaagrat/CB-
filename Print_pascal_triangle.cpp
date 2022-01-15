#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		cout<<"  ";
	}
	cout<<1; 
	cout<<endl;

	int data=1;
	for(int line=1;line<n;line++){
		for(int i=0;i<(n-line-1);i++){
			cout<<"  ";
		}
		cout<<1;
		for(int times=1;times<line;times++){
			cout<<"   "<<data;
		}
		cout<<"   "<<1;
		cout<<endl;
		data++;
	}
	return 0;
}