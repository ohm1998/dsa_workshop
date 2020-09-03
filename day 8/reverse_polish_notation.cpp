#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s1;
	s1.push(2);
	s1.push(3);
	printf("->");
	while(!s1.empty())
	{
		printf("%d \n",s1.top());
		s1.pop();
	}
}
