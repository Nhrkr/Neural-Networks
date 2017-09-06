#include<iostream>
#include<cmath>
#define N 2
using namespace std;
float func(float x)
{
	float ans = (1/(1 + exp(-1 * x)));
	return ans;
}
float deriv(float x)
{
	float ans=func(x)*(1-func(x));
	return ans;
}
void update_v(float v[][N],float change_v[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			v[i][j]+=change_v[i][j];
		}
	}
}
void update_w(float w[],float change_w[])
{
	for(int i=0;i<N;i++)
	{
		w[i] += change_w[i];
	}
}
void init_weights(float v[][N],float w[N],float bv[],float &bw)
{
	cout<<"Enter weights for input-hidden layer : \n\n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<"\nEnter bias for input-hidden layer : \n\n";
	for(int i=0;i<N;i++)
	{
		cin>>bv[i];
	}
	cout<<"\nEnter weights for hidden-output layer : \n\n";
	for(int i=0;i<N;i++)
	{
		cin>>w[i];
	}
	cout<<"\nEnter bias for output layer : \n\n";
	cin>>bw;
}
float calc_zin(int j,int inp[],float v[][N],float bv[])
{
	float ans = bv[j];
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<N;k++)
		{
			ans += inp[i]*v[i][j];
		}
	}
	return ans;
}
void calc_z(float z[],int inp[],float v[][N],float bv[])
{
	for(int j=0;j<N;j++)
	{
		z[j]=func(calc_zin(j,inp,v,bv));
	}
}
float calc_yin(float z[],float w[],float bw)
{
	float ans = bw;
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<N;k++)
		{
			ans += z[i]*w[i];
		}
	}
	return ans;
}
float calc_y(float z[],float w[],int bw)
{
	return func(calc_yin(z,w,bw));
}
void calc_delv(float change_v[][N],float rate,int inp[],float v[][N],float w[],float bv[],float delk)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			change_v[i][j]=rate * (delk*w[j]*deriv(calc_zin(j,inp,v,bv))) * inp[i];
		}
	}
}
void calc_delw(float change_w[],float rate,float delk,float z[])
{
	for(int i=0;i<N;i++)
	{
		change_w[i] = rate * delk * z[i];
	}
}
float calc_target(int inp[])
{
	int a=inp[0];
	int b=inp[1];
	if(a != b)
	return 1;
	else
	return 0;
}
void show_w(float w[])
{
	for(int i=0;i<N;i++)
	cout<<w[i]<<" ";
	cout<<endl;
}
void show_v(float v[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int c=1,i,j;                //No of epochs
	//----------------------------------------------------------------------------------------//
	int inp[2],t;
	float v[N][N]={{2,1},{1,2}};
	float w[N]={-1,1};
	float bv[N]={0,-1};
	float bw=-1,y,delk,rate;
	float z[N];
	float change_v[N][N],change_w[N];
	cout<<"Enter rate : ";
	cin>>rate;
	//---------------------------------------------------------------------------------------//
	while(c<=4)
	{
		cout<<"\nEnter inputs : \n\n";
		cin>>inp[0]>>inp[1];
		t=calc_target(inp);
		calc_z(z,inp,v,bv);
		y=calc_y(z,w,bw);
		delk=(t-y)*deriv(calc_yin(z,w,bw));
		calc_delw(change_w,rate,delk,z);
		calc_delv(change_v,rate,inp,v,w,bv,delk);
		update_w(w,change_w);
		update_v(v,change_v);
		cout<<"Weights (W) : \n";
		show_w(w);
		cout<<"Weights (V) : \n";
		show_v(v);
		cout<<"\nEnd of epoch "<<c<<endl;
		c++;
	}
}
