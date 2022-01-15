#include<iostream>
#include<vector>
using namespace std;


#define MAX 1000000
int isPrime[MAX];
vector<int> primes;

void sieve(){
	isPrime[0]=0;
	isPrime[1]=0;
	for(int i=2;i<MAX;i++){
		isPrime[i]=1;
	}

	for(int i=2;i*i<MAX;i++){
		if(isPrime[i]==1){
			for(int j=i*i;j<MAX;j+=i){
				isPrime[j]=0;
			}
		}
	}

	for(int i=2;i<MAX;i++){
		if(isPrime[i]==1){
			primes.push_back(i);
		}
	}
}


int main() {
	sieve();//sieve should only be created once if their are multiple testcases, no need to build it again and again
	int n;
	cin>>n;
	if(isPrime[n]==1)
		cout<<"Prime ";
	else
		cout<<"Not Prime";
	return 0;
}