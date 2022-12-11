//program to draw ray diagram for a convex lens of a given focal length, height of object and object distance
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
void convex(float h, float f, float u, float v)
{
 float x1,y1,dx1,dy1,dx2,dy2;
 float c1,c2,m1,m2;
 int gd=DETECT,gm;
 initgraph(&gd,&gm," ");
 line(20,250,750,250); //axis 1
 line(325,20,325,450); //axis 2
 line(325+(2*u),250,325+(2*u),250-h);  //object
 line(325+(2*u),250-h,325,250-h);  //object to axis ray 1
 line(325+(2*u),250-h,325,250);    //object to center of curvature
 line(325,250-h,325+(2*f),250); //point on axis to f
 int x=325;
 int y=250;
 int startangle=0;
 int endangle=360;
 int xrad=15;int yrad=50;
 ellipse(x,y,startangle,endangle,xrad,yrad);
 dx1=-(2*u);
 dy1=h;
 m1=dy1/dx1;
 c1=(250-h)-(m1*(325+2*u));
 dx2=2*f;
 dy2=h;
 m2=dy2/dx2;
 c2=250-m2*(325+(2*f));
 x1=(c2-c1)/(m1-m2);
 y1=(m1*x1)+c1;
 line(x1,y1,325+(2*v),250); //from object to p. axis
 line(x1,y1,325,250); //from center of curvature to object
 line(x1,y1,325+(2*f),250); //from focus to mirror
 getch();
 closegraph();
}
 void concave(float h, float f, float u, float v)
{
 float x1,y1,dx1,dy1,dx2,dy2;
 float c1,c2,m1,m2;
 int gd=DETECT,gm;
 initgraph(&gd,&gm," ");
 line(20,250,750,250); //axis 1
 line(325,20,325,450); //axis 2
 line(325+(2*u),250,325+(2*u),250-h);  //object
 line(325+(2*u),250-h,325,250-h);  //object to axis ray 1
 line(325+(2*u),250-h,325,250);    //object to center of curvature
 line(325,250-h,325+(2*f),250); //point on axis to f
 int xrad=15;int yrad=50;
 ellipse(295,250,270,90,xrad,yrad);
 ellipse(355,250,90,270,xrad,yrad);
 line(295,200,355,200);
 line(295,300,355,300);
 dx1=-(2*u);
 dy1=h;
 m1=dy1/dx1;
 c1=(250-h)-(m1*(325+2*u));
 dx2=2*f;
 dy2=h;
 m2=dy2/dx2;
 c2=250-m2*(325+(2*f));
 x1=(c2-c1)/(m1-m2);
 y1=(m1*x1)+c1;
 line(x1,y1,325+(2*v),250); //from object to p. axis
 line(x1,y1,325,250); //from center of curvature to object
 line(x1,y1,325+(2*f),250); //from focus to mirror
 getch();
 closegraph();
}
 void choose_lens(float h, float f, float u, float v)
 {
  if(f>0)
  convex(h,f,u,v);
  else
  concave(h,f,u,v);
 }
void check(float h, float f, float u, float v)
{
 if(u>-20)
 cout<<"invalid object distance";
else if(v<-100||v>200)
 cout<<"invalid image distance";
else if(h<20||h>50)
 cout<<"invalid object height";
else  if(f>500||f==-u)
 cout<<"invalid focal length";
 else
 choose_lens(h,f,u,v);
 }
void accept()
{
 clrscr();
 float ho,h,u,f;
 float v,m;
 cout<<"enter height of the object";
 cin>>h;
 cout<<"enter the focal length of the mirror with sign convention";
 cin>>f;
 cout<<"enter the object distance with sign convention";
 cin>>u;
 v=(f*u)/(f+u);
 cout<<"image distance is: "<<v<<endl;
 ho=(v*h)/u;
 m=v/u;
 cout<<"height of image is: "<<ho<<endl;
 cout<<"magnification produced: "<<m<<endl;
 getch();
check(h,f,u,v);
}
void cover()
{
	int gdriver = DETECT, gmode, errorcode;
	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	for (int i=0;i<100;i+=10)
	{
	  circle(300,250,50+i);

	}
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
	outtextxy(255,240,"Ray Optics");
	getch();
	accept();
}

void main()
{
cover();
}

