#include<iostream>
#include<stdlib.h>

using namespace std;

int coins[5] = { 25,10,5,1 };
int account(int total)
{
	int count = 0;
	for (int j = 0; (j < 4)&&(total>0); j++)
	{
		if (total >= coins[j])
		{
			count += total/coins[j];
			total %= coins[j];
		}
	}
	return count;
}

int main(char argc, char** argv)
{
	if (argc > 1)
		//cout << atoi(argv[1]) << endl;
		cout << account(atoi(argv[1])) << endl;
	return 0;
}