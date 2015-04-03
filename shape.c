#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Point
{
	friend class Segment;
	friend class Vector;
	private:		
		double x1,y1;
	public:
		Point()
		{
			cout<<"Введите координаты точки\n";
			cin>>x1>>y1;
		}
		
		Point(double j,double k): x1(j), y1(k){};
		
};

class Segment
{
	friend class Point;
	friend class Vector;
	private:		
		double x1,x2,y1,y2, A, B, C;
	public:
		Segment()
		{
			cout<<"Введите точки отрезка\n";
			cin>>x1>>y1>>x2>>y2;
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
	
	bool SegmentCut(Segment& r, Segment& s)
	{
		double x,y;
		r.Lane();
		s.Lane();
		y=( (s.C-r.C * (s.A/r.A)) / (s.B-r.B * (s.A/r.A)) );
		x=( r.C - r.B*y ) / r.A;
		cout<<x<<" "<<y;
		if( ((r.x1*s.A+r.y1*s.B-s.C) * (r.x2*s.A+r.y2*s.B-s.C) >= 0) && ((s.x1*r.A+s.y1*r.B-r.C) * (s.x2*r.A+s.y2*r.B-r.C) >= 0)) 
		{return(0);} 
		else {return(1);};
	}	
	
	const void SegmentPoint(Segment& seg, Point& po)
	{
		seg.Lane();
		if( (seg.A*po.x1 + seg.B*po.y1 == seg.C) && ( (po.x1-seg.x1) * (po.x1-seg.x2) <= 0) ){printf("Лежит");}else{printf("Не лежит");};
	} 
	
	const void LanePoint(Segment& seg, Point& po)
	{
		seg.Lane();
		if( seg.A*po.x1 + seg.B*po.y1 > seg.C){cout<<"Ниже";};
		if( seg.A*po.x1 + seg.B*po.y1 < seg.C){cout<<"Выше";}; 
		if( seg.A*po.x1 + seg.B*po.y1 == seg.C){cout<<"На прямой";};
	}

	
};

class Vector
{
	friend class Point;
	friend class Segment;
	private:		
		double  xst, yst, xend, yend; 
	public:
		
		Vector()
		{
			cout<<"Введите координаты начала и конца";
			cin>>xst>>yst>>xend>>yend;
		}

		Vector(double i,double j,double k,double l): xst(i), yst(j), xend(k), yend(l){};
	

		Vector Reverce()
		{
			Vector s(xend,yend,xst,yst);
			return(s);
		}
				
		Segment VectorintoSegment(const Vector& a)
		{
			Segment b(a.xst,a.xend,a.yst,a.yend);
			return(b);
		}

};

int main(){
	Segment a,b; int i;
	i = a.SegmentCut(a,b);
	return(0);
}

