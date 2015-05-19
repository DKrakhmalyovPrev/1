#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Point
{
	friend class Segment;
	friend class Vector;
	friend class Quadre;
	private:		
		double x,y;
	public:
		Point(){};

		Point(double j,double k): x(j), y(k){};
		
		void ScanPoint()
		{
			cin>>x>>y;
		}
		
		void PrintPoint()
		{
			cout<<x<<" "<<y;
		}
		
		double Getx(){return(x);};
		double Gety(){return(y);};
		void Sety(double j){y=j;};
		void Setx(double j){x=j;};
	
		
		
};

class Segment
{
	friend class Point;
	friend class Vector;
	private:		
		Point fst, snd; double A, B, C;
	public:
		Segment(){}
		
		Segment(const Point& i,const Point& j): fst(i), snd(j){};
	

		void ScanSegment()
		{
			cin>>fst.x>>fst.y>>snd.x>>snd.y;
		}
		
		void PrintSegment()
		{
			cout<<fst.x<<" "<<fst.y<<" "<<snd.x<<" "<<snd.y;
		}

		void Lane()
		{
			double k=(snd.y-fst.y)/(snd.x-fst.x);
			double b=(snd.x*fst.y-fst.x*snd.y)/(snd.x-fst.x);
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
			if( ((r.fst.x*s.A+r.fst.y*s.B-s.C) * (r.snd.x*s.A+r.snd.y*s.B-s.C) >= 0) 
				&& ((s.fst.x*r.A+s.fst.y*r.B-r.C) * (s.snd.x*r.A+s.snd.y*r.B-r.C) >= 0)) 
			{return(0);} 
			else {return(1);};
		}	
		
		const bool SegmentPoint(Segment& seg, Point& po)
		{
			seg.Lane();
			if( (seg.A*po.x + seg.B*po.y == seg.C) && ( (po.x-seg.fst.x) * (po.x-seg.snd.x) <= 0) )
				return(1);
			else
				return(0);
		} 
		
		const int LanePoint(Segment& seg, Point po)
		{
			seg.Lane();
			if( seg.A*po.x + seg.B*po.y > seg.C) return(-1);//Выше
			if( seg.A*po.x + seg.B*po.y < seg.C) return(1); //Ниже
			if( seg.A*po.x + seg.B*po.y == seg.C) return(0);//На прямой
		}

		
	
		
};	

class Vector
{
	friend class Point;
	friend class Segment;
	friend class Quadre;
	private:		
		Point  st; Point end; 
	public:
		
		Vector(){};
		
		Vector(const Point& i,const Point& j): st(i), end(j){};
	
		void ScanVector()
		{
			cin>>st.x>>st.y>>end.x>>end.y;
		}
		
		void PrintPVector()
		{
			cout<<st.x<<" "<<st.y<<" "<<end.x<<" "<<end.y;
		}

		Vector Reverce()
		{
			Vector s(end, st);
			return(s);
		}
				
		Segment VectorintoSegment(const Vector& a)
		{
			Segment b(st, end);
			return(b);
		}
		
		Point MovePoint(Point & a)
		{
			Point q(a.x,a.y);
			q.x+=end.x-st.x;
			q.y+=end.y-st.y;
			return(q);
		};

};

class Quadre
{
	friend class Point;
	friend class Vector;
	friend class Segment;

	private:
		Point dots[4];
	
	public:
		Quadre(){};
		
		Quadre(const Point& a,const Point& b,const Point& c,const Point& d)
		{
			dots[0]=a;
			dots[1]=b; 
			dots[2]=c; 
			dots[3]=d;
		};
		
		void ScanQuadre()
		{
			for(int i=0;i<4;i++)
				dots[i].ScanPoint();
		}
		void MoveThisFuckingShit(int num, Vector& vec)
		{
			int step=0;
			for(int i=0; i<4;i++)
				for(int j=i+1; j<4; j++) 
				{
					if((i!=num)&&(j!=num)&&(j!=i))
					{
						Segment side(dots[i], dots[j]);
						if( side.LanePoint(side, dots[num]) != side.LanePoint(side, vec.MovePoint(dots[num]) ) )
							step++;
					}
				}
			if(step%2==0)
				dots[num]=vec.MovePoint(dots[num]);
			else
				cout<<"Нельзя двигать, сорян";
		}
		
		void PrintQuadre()
		{
			for(int i=0;i<4;i++)
			{
				cout<<"Точка "<<i<<" = ("<<dots[i].x<<" , "<<dots[i].y<<")";
				cout<<"\n";
			}
		}
			
};
			

int StartWork()
{
	Quadre a;
	int got=0;
	string command;
	while(1)
	{
		
		cin>>command;
		if(command=="Задать")
		{
			a.ScanQuadre();
			got=1;
		}
		else if(got==0)
			cout<<"Сначала задай";
		else if(command=="Двинуть")
		{
			int i;
			cout<<"Какую двигаем";
			cin>>i;
			Vector q;
			cout<<"Задай вектор";
			q.ScanVector();
			a.MoveThisFuckingShit(i,q);
		}
		else if(command=="Распечатать")
		{
			a.PrintQuadre();	
		}
		else if(command=="Закончить")
			return(0);
	}
};

int main()
{
	StartWork();
	
	return(0);
}
