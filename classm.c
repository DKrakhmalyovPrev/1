#include <iostream>

#include <stdio.h>

#include <cstdlib>

#include <math.h>

#include<ctime>


using namespace std;

template<typename element>
class Matrix
{	
	
	private:
		double det;
		int wide;
		element **table;
			
	public:
		
		Matrix(int s)
		{
			srand( time(0) );
			wide=s;
			table=new element*[wide];
			for(int i=0;i<wide;i++)
				table[i]=new element[wide];
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					cin>>table[i][j];
		};

		Matrix(const Matrix<element>& a)
		{
			wide=a.wide;
			table=new element*[wide];
			for(int i=0;i<wide;i++)
				table[i]=new element[wide];
			for(int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					table[i][j]=a.table[i][j];
		};

		Matrix(int s, int q): wide(s)
		{
			table=new element*[wide];
			for(int i=0;i<wide;i++)
				table[i]=new element[wide];
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					table[i][j]=rand() % q;
		};

		const int Size()
		{ 
			return(wide);
		};
		
		const void PrintTable()
		{		
			for(int i=0;i<wide;i++)
			{
				for(int j=0;j<wide;j++)
					cout<<.2table[i][j]<<"|";;
					
				cout<<"\n";			
			}
		};
		
		double Trace()
		{
			element tr=0;
			for (int i=0;i<wide;i++)
				tr+=table[i][i];
			return(tr);
		};

		Matrix Trans()
		{
			Matrix a(wide,1);
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					a.table[i][j]=table[j][i];
			return(a);
		};
		
		Matrix ToDiag(const Matrix<element>& a)
		{	
			element co;
			
			for(int i=0;i<wide;i++)
				for(int j=i+1;j<wide;j++)
				{
					if(table[i][i]==0)
					{
						int p=i;
						while((table[p][i]==0)&&(p+1<wide)){p++;};
						for(int k=0;k<wide;k++)
						{
							co=table[p][i];
							table[p][k]=table[i][k];
							table[i][k]=co;
							co=a.table[p][i];
							a.table[p][k]=a.table[i][k];
							a.table[i][k]=co;
						};
						det*=-1;
					}	
					if(table[i][i]!=0)
					{
						element b=table[j][i]/table[i][i];
						for(int k=i;k<wide;k++)
						{	
							a.table[j][k]-=b*a.table[i][k];
							table[j][k]-=b*table[i][k];
						}
					}
				}
	
			return(a);
		}

		constdouble Determ()
		{	
			det=1;

			Matrix<element> table1(*this);
			Matrix<element> just(*this);
			table1=table1.ToDiag(just);
			
			for(int i=0;i<wide;i++)
				det*=table1.table[i][i];
			return(det);	
		};
			
		const Matrix Reversed()
		{
			double s; element co,b;
			Matrix<element> edinst(wide,1);
			Matrix<element> table1(*this);
			for(int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					if(i==j)
					{
						edinst.table[i][j]=1;
					} 
					else 
					{
						edinst.table[i][j]=0;
					};
			s=Determ();
			edinst=table1.ToDiag(edinst);

			edinst=edinst.Trans();
			table1=table1.Trans();
			
			edinst=table1.ToDiag(edinst);
			
			for(int i=0;i<wide;i++)
				if(table1.table[i][i]!=0)
					edinst.table[i][i]*=1/table1.table[i][i];
			
			edinst=edinst.Trans();	
			if(s==0)
				cout<<"Обратной не существует"; 
			else		
			return(edinst);
			
		};
		
		const Matrix operator*(Matrix & other)
		{
			element b;
			Matrix mult(wide,1);
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
				{
					b=0;
					for(int a=0;a<wide;a++)
					b+=table[i][a]*other.table[a][j];
					mult.table[i][j]=b;
				};
			return(mult);
		};

		const Matrix operator+(Matrix & other)
		{
			Matrix sum(wide,1);
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					sum.table[i][j]=table[i][j]+other.table[i][j];
			return(sum);
		};

		element *operator[](int i)
		{
			return(table[i]);
		};


	
		

};



int main(){
	int i,j; 
	Matrix<double> odin(3);
	odin.PrintTable();
	printf("%.2lf" , odin.Determ());
	
	printf("\n Обратная матрица \n");
	Matrix<double> odint(odin.Reversed());
	odint.PrintTable();	
	
	return(0);
};
