#include<iostream>
using namespace std;
#define N 4
void init_weights(int w[])
{
	for(int i=0;i<N;i++)
	{
		w[i]=0;
	}
}
int compare(int a[][N],int b[][N])
{
	int ans=1;
	for(int i=0;i<N && ans;i++)
	{
		if(a[0][i]!=b[0][i])
		ans=0;
	}
	return ans;
}
void mat_mult(int a[][N],int b[][N],int t_result[][N])
{
	int t,m,x;
	for(int i=0;i<N;i++)
	{
		t=0;
		for(int j=0;j<N;j++)
		{
			t+=a[0][j]*b[j][i];
		}
		if(t>0)
		t=1;
		else if(t<0)
		t=-1;
		else
		t=0;
		t_result[0][i]=t;
	}
}
void calc_weight(int w[][N],int a[][1],int b[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			w[i][j]=a[i][0]*b[0][j];
		}	
	}	
}
int main()
{
	int w[N][N],a[N][1]={{1},{1},{-1},{-1}};
	int b[1][N]={{1,1,-1,-1}};
	int test_result[1][N];
	calc_weight(w,a,b);
	mat_mult(b,w,test_result);
	if(compare(test_result,b))
	{
		cout<<"Trained Network successfully recognises the input vector.\n";
	}
	else
	{
		cout<<"Network doesn't recognise the given input vector.\n";
	}
}
