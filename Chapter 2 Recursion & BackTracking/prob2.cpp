#include <iostream>

using namespace std;


bool isArraySorted(int a[], int n)
{
	if(n == 1)
		return true;
	if(a[n-1] > a[n-2])
		return isArraySorted(a,n-1);
	else
		return false;
	
}



int main()
{
	int n;
	cin >> n;
	int *a = new int [n];
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	cout << isArraySorted(a,n) << endl;
}