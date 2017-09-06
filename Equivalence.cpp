#include<iostream>
using namespace std;
#define N 5
float min(float a,float b)
{
	if(a<b)
	return a;
	else
	return b;
}
int isReflexive(float a[][N])
{
	int ans=1;
	for(int i=0;i<N && ans;i++)
	{
		if(a[i][i]!=1)
		{
			ans=0;
			cout<<"Not Reflexive\n";
		}
	}
	return ans;
}
int isSymmetric(float a[][N])
{
	int ans=1;
	for(int i=1;i<N && ans;i++)
	{
		for(int j=0;j<i && ans;j++)
		{
			if(a[i][j]!=a[j][i])
			{
				ans=0;
				cout<<"Not Symmetric\n";
			}
		}
	}
	return ans;
}
int isTransitive(float a[][N])
{
	int ans=1;
	float x,y,z;
	for(int i=0;i<N && ans;i++)
	{
		for(int j=0;j<N && ans;j++)
		{
			x=a[i][j];
			for(int k=0;k<N && ans;k++)
			{
				y=a[j][k];
				z=a[i][k];
				if(z<min(x,y))
				{
					cout<<"Not Transitive : x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
					cout<<i<<" "<<j<<" "<<k<<endl;
					ans=0;
				}
			}
		}
	}
	return ans;
}
int main()
{
	float r[N][N]={{1,0.8,0.4,0.5,0.6},{0.5,1,0.4,0.3,0.9},{0.4,0.2,1,0.4,0.4},{0.5,0.5,0.3,1,0.3},{0.4,0.9,0.4,0.7,1}};
	float s[N][N]={{1,0.8,0.4,0.5,0.8},{0.8,1,0.4,0.5,0.9},{0.4,0.4,1,0.4,0.4},{0.5,0.5,0.4,1,0.5},{0.8,0.9,0.4,0.5,1}};
	if(isReflexive(r) && isSymmetric(r) && isTransitive(r))
	cout<<"Yes,R is equivalent.\n";
	else
	cout<<"No,R is not equivalent.\n";
	if(isReflexive(s) && isSymmetric(s) && isTransitive(s))
	cout<<"Yes,S is equivalent.\n";
	else
	cout<<"No,S is not equivalent.\n";
}
