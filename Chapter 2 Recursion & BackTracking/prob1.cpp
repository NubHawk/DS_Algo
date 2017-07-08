#include <iostream>

using namespace std;


void TowersOfHanoi(int n, char S, char D, char A)
{
	if(n==1)
	{
		cout << "Moving disk 1 from " << S << " to " << D << endl;
		return;
	}

	TowersOfHanoi(n-1,S,A,D);
	cout << "Moving disk " << n << " from " << S <<" to " << D << endl;
	TowersOfHanoi(n-1,A,D,S);
}




int main()
{
	TowersOfHanoi(3,'S','D','A');
}