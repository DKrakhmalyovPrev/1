#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Shape
{
	int i;
};

class Point
{
	public:
		Point()
		{
			printf("Введите координаты точки\n");
			scanf("%lf%lf", &x1,&y1);
		}
		
		Point(double j,double k): x1(j), y1(k){};
	
	double x1,y1;
};

class Segment
{
	public:
		Segment()
		{
			printf("Введите точки отрезка\n");
			scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
		}
		
		Segment(double i,double j,double k,double l): x1(i), y1(j), x2(k), y2(l){};
	
	void Lane()
	{
		double k=(y2-y1)/(x2-x1);
		double b=(x2*y1-x1*y2)/(x2-x1);
		A=k;
		B=-1;
		C=-b;
	}
	int SegmentCut(Segment r,Segment s)
	{
		double x,y;
		r.Lane();
		s.Lane();
		y=((s.C-r.C*(s.A/r.A))/(s.B-r.B*(s.A/r.A)));
		x=(r.C-r.B*y)/r.A;
		printf("%lf %lf", x,y);
		if( ((r.x1*s.A+r.y1*s.B-s.C)*(r.x2*s.A+r.y2*s.B-s.C)>=0) && ((s.x1*r.A+s.y1*r.B-r.C)*(s.x2*r.A+s.y2*r.B-r.C)>=0)) 
		{return(0);} 
		else {return(1);};
	}	
	
	void SegmentPoint(Segment seg, Point po)
	{
		seg.Lane();
		if((seg.A*po.x1+seg.B*po.y1==seg.C)&&((po.x1-seg.x1)*(po.x1-seg.x2)<=0)){printf("Лежит");}else{printf("Не лежит");};
	} 
	
	void LanePoint(Segment seg, Point po)
	{
		seg.Lane();
		if(seg.A*po.x1+seg.B*po.y1>seg.C){printf("Ниже");};
		if(seg.A*po.x1+seg.B*po.y1<seg.C){printf("Выше");}; 
		if((seg.A*po.x1+seg.B*po.y1==seg.C)){printf("На прямой");};
	}
	double x1,x2,y1,y2, A, B, C;
};

class Vector
{
	public:
		Vector()
		{
			printf("Введите координаты начала и конца");
			scanf("%lf%lf%lf%lf", &xst, &yst, &xend, &yend);
		}

		Vector(double i,double j,double k,double l): xst(i), yst(j), xend(k), yend(l){};
	

		Vector Reverce()
		{
			Vector s(xend,yend,xst,yst);
			return(s);
		}
				
		void VectorintoSegment(Vector a, Segment b)
		{
			b.x1=a.xst;
			b.x2=a.xend;
			b.y1=a.yst;
			b.y2=a.yend;
		}

double  xst, yst, xend, yend; 
};
