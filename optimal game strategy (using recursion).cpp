#include<iostream>
using namespace std;

int Rec(int arr[], int i, int j, int sum)
{
    //base case: return the maximum of the last two elements left
    if (j == i + 1)
        return max(arr[i], arr[j]);
 
    // if we choose i,opponent is left to choose from i+1 and j
    // if we choose j,opponent is left with i or j-1
    return max((sum - Rec(arr, i + 1, j, sum - arr[i])),(sum - Rec(arr, i, j - 1, sum - arr[j])));
}

int main() {
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	cout << Rec(a, 0, n - 1, sum);
	
	return 0;
}