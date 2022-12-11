#include<stdio.h>
int main()
{	
	int i,n,t;
	int h[1440],m[1440];
	scanf("%d",&n);

for(i=0;i<n;i++)
{
	scanf("%d%d",&h[i],&m[i]);
}
for( i=0;i<n;i++)
{
		h[i]=23-h[i];
		m[i]=60-m[i];
		t=(h[i]*60)+m[i];
		printf("%d\n",t);
	}

}
