#include<iostream>
using namespace std;
#define N 2
#define INP_SIZE 4
float calc_d(int j,float w[][N],float inp[])
{
	float ans=0.0;
	for(int i=0;i<INP_SIZE;i++)
	{
		ans += (w[i][j] - inp[i])*(w[i][j] - inp[i]);
	}
	return ans;
}
void update_weights(int j,float w[][N],float rate,float inp[])
{
	for(int i=0;i<INP_SIZE;i++)
	{
		w[i][j] += rate * (inp[i] - w[i][j]);
	}
}
void update_cflag(int npar,int minpos,int change_flag[])
{
	int i,c;
	if(minpos==0)
	{
		i=minpos+1;
		c=npar;
		while(c--)
		{
			change_flag[i]=1;
			i++;
		}
	}
	else if(minpos==N-1)
	{
		i=minpos-1;
		c=npar;
		while(c--)
		{
			change_flag[i]=1;
			i--;
		}
	}
	else
	{
		i=minpos+1;
		c=npar;
		while(c--)
		{
			change_flag[i]=1;
			i++;
		}
		i=minpos-1;
		c=npar;
		while(c--)
		{
			change_flag[i]=1;
			i--;
		}
	}
}
void show_weights(float w[][N])
{
	for(int i=0;i<INP_SIZE;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<w[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	float inp[INP_SIZE];
	int minpos;
	int neighb_par;
	float d,min,rate;
	float w[INP_SIZE][N]={{0.2,0.6},{0.3,0.5},{0.4,0.7},{0.2,0.8}};
	//-----------------------------------------------------//
	cout<<"Enter rate : ";
	cin>>rate;
	cout<<"\n\nEnter neighborhood parameter : ";
	cin>>neighb_par;
	for(int t=0;t<4;t++)
	{
		int change_flag[N]={0};
		cout<<"\nEnter inputs : ";
		cin>>inp[0]>>inp[1]>>inp[2]>>inp[3];
		min=100;
		for(int i=0;i<N;i++)
		{
			d=calc_d(i,w,inp);
			if(d<min)
			{
				min=d;
				minpos=i;
			}
		}
		change_flag[minpos]=1;
		update_cflag(neighb_par,minpos,change_flag);
		for(int i=0;i<N;i++)
		{
			if(change_flag[i])
			{
				update_weights(i,w,rate,inp);
			}
		}
//		cout<<"\nWeights after epoch "<<t+1<<endl<<endl;
		show_weights(w);
	}
}
