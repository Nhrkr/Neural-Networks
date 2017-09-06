#include<iostream>


using namespace std;

struct input{
	int x,y;
};
//initialising weights
void init_weights(input &q,int x)
{
	q.x=0;
	q.y=0;
	x=0;
}

//target== o/p 0 if both a and b 0
int target(input p)
{
	int a=p.x;
	int b=p.y;
	if(a==0 && b==0)
		return 0;
	else
		return 1;
}
//function converts f(y) to y...threshold function
int response(int y,int thold)
{
	if(y>thold)
		return 1;
	else if(y>=(-1*thold) && y<=thold)
		return 0;
	else
		return -1;
}
//xiwi
int net_input(input p,int b,input q,int B)
{
	int ans;
	ans=p.x*q.x+p.y*q.y+b*B;
	return ans;
}
//if target==y
int exit_cond(int y,int t)
{
	return (y==t);
}
//update weight if target not equal to o/p response
void update_weight(input &q,int &b,int d1,int d2,int B)
{
	q.x+=d1;
	q.y+=d2;
	b+=B;
}
int main()
{
	int flag=1,b=1,d1,d2,d3,net_inp,out,th,targ,rate,B;
	cout<<"\nEnter threshold : ";// 0 or 1
	cin>>th;
	cout<<"\nEnter learning rate : ";//int val
	cin>>rate;
	input p[4];//4 inputs
	input q;//for output
	init_weights(q,B);//initialising
	for(int i=0;i<4;i++)
	{
		cout<<"\nEnter inputs for pair "<<(i+1)<<endl;
		cin>>p[i].x>>p[i].y;
	}
	while(flag)
	{
		for(int j=0;j<4 && flag;j++)
		{
			net_inp=net_input(p[j],b,q,B);//yin
			out=response(net_inp,th);//y
			targ=target(p[j]);//y
			if(exit_cond(out,targ))//if t==y stop
			{
				flag=0;
				cout<<"Stopping Condition achieved.\n\n";
				cout<<"Weights are given as : "<<q.x<<" "<<q.y<<" "<<B<<endl;
			}
			else//change weights
			{
				d1=rate*p[j].x*targ;
				d2=rate*p[j].y*targ;
				d3=rate*targ;
				update_weight(q,B,d1,d2,d3);
			}
		}
		if(flag)
		{
			cout<<"End of epoch\n";
		}
	}
}
