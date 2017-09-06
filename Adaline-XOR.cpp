#include<iostream>
using namespace std;
struct ipair{
	int x,y;
};
struct wpair{
	float x,y,z;
};
void init_weights(wpair &q)
{
	q.x=0.2;
	q.y=0.2;
	q.z=0.2;
}
int target(ipair p)
{
	int a=p.x;
	int b=p.y;
	if(a==1 && b==1)
		return -1;
	else if(a==1 && b==-1)
		return 1;
	else if(a==-1 && b==1)
		return -1;
	else
		return -1;
}
float net_input(ipair p,int b,wpair q)
{
	float ans;
	ans=p.x*q.x+p.y*q.y+b*q.z;
	return ans;
}
void update_weight(wpair &q,float d1,float d2,float B)
{
	q.x+=d1;
	q.y+=d2;
	q.z+=B;
}
int main()
{
	int flag=1,b=1,out,th,targ,B,c=0;
	float error=100.0,rate,n,net_inp,d1,d2,d3;                                     
	cout<<"\nEnter learning rate : ";
	cin>>rate;
	ipair p[4];
	wpair q;
	init_weights(q);
	for(int i=0;i<4;i++)
	{
		cout<<"\nEnter inputs for pair "<<(i+1)<<endl;
		cin>>p[i].x>>p[i].y;
	}
	do
	{
		error=0.0;
		for(int j=0;j<4 && flag;j++)
		{
			net_inp=net_input(p[j],b,q);
			targ=target(p[j]);	
			d1=rate*p[j].x*(targ-net_inp);
			d2=rate*p[j].y*(targ-net_inp);
			d3=rate*(targ-net_inp);
			update_weight(q,d1,d2,d3);
			n=(targ-net_inp);
			error+=n*n;
		}
		cout<<"End of epoch "<<c+1<<".\n";
		c++;
		cout<<"ERROR = "<<error<<endl<<endl;
	}while(c<10);
	cout<<"Stopping Condition achieved.End of all epochs.\n\n";
	cout<<"Weights are given as : "<<q.x<<" "<<q.y<<" "<<q.z<<endl;
}
