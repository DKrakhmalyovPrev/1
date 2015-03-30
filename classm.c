#include <iostream>

#include <stdio.h>

#include <cstdlib>

#include <math.h>


using namespace std;

template<typename element>
class Matrix
{	
	
	private:
		int wide;
		element **table;
			
	public:
		
		Matrix(int s)
		{
			wide=s;
			table=new element*[wide];
			for(int i=0;i<wide;i++)
				table[i]=new element[wide];
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					//cin>>table[i][j];
					table[i][j]=rand() % 300 - 150;
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

		Matrix(int s, int i): wide(s)
		{
			table=new element*[wide];
			for(int i=0;i<wide;i++)
				table[i]=new element[wide];
		};

		int Rasmer()
		{ 
			return(wide);
		};
		
		void PrintTable()
		{		
			for(int i=0;i<wide;i++)
			{
				for(int j=0;j<wide;j++)
					printf("%.2lf |", table[i][j]);
					
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
		
		double ToDiag(const Matrix<element>& a)
		{	
			double det=1;
			int i,j,k,p;
			element co,b;
			
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++)
				{
					if(table[i][i]==0)
					{
						p=i;
						while((table[p][i]==0)&&(p+1<wide)){p++;};
						for(k=0;k<wide;k++)
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
						b=table[j][i]/table[i][i];
						for(k=i;k<wide;k++)
						{	
							a.table[j][k]-=b*a.table[i][k];
							table[j][k]-=b*table[i][k];
						}
					}
				}
	
			return(det);
		}

		double Determ()
		{
			Matrix<element> table1(*this);
			double det=table1.ToDiag(*this);
			
			for(int i=0;i<wide;i++)
				det*=table1.table[i][i];
			return(det);	
		};
			
		Matrix Reversed()
		{
			int i,j,k,p; double det; element co,b;
			Matrix<element> edinst(wide,1);
			Matrix<element> table1(*this);
			for(i=0;i<wide;i++)
				for(j=0;j<wide;j++)
					if(i==j)
					{
						edinst.table[i][j]=1;
					} 
					else 
					{
						edinst.table[i][j]=0;
					};

			table1.ToDiag(edinst);

			edinst=edinst.Trans();
			table1=table1.Trans();
			
			table1.ToDiag(edinst);
			
			for(i=0;i<wide;i++)
				if(table1.table[i][i]!=0)
					edinst.table[i][i]*=1/table1.table[i][i];
			
			return(edinst);
		};
		
		Matrix operator*(Matrix & other)
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

		Matrix operator+(Matrix & other)
		{
			Matrix sum(wide,1);
			for (int i=0;i<wide;i++)
				for(int j=0;j<wide;j++)
					sum.table[i][j]=table[i][j]+other.table[i][j];
			return(sum);
		};

		double *operator[](int i)
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
	//Matrix<double> odint(odin.Reversed());
	//odint.PrintTable();	
	
	return(0);
};
