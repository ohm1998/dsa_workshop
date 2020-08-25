#include<iostream>

using namespace std;

void change_val(int *p)
{
	*p = 0;
}

int main()
{
	int a,b;
	a=1;
	b=5;
	cout<<a<<endl<<b;
	change_val(&b);
	cout<<a<<endl<<b;
	return 0;
}

