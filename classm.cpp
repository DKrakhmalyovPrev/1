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
		int wide,high;
		element **table;
			
	public:
		
		Matrix(){};

		Matrix(const Matrix<element>& a)
		{
			wide=a.wide;
			high=a.high;
			table=new element*[wide];
			for(int i=0;i<high;i++)
				table[i]=new element[wide];
			for(int i=0;i<wide;i++)
				for(int j=0;j<high;j++)
					table[i][j]=a.table[i][j];
		};

		Matrix(int s, int q): wide(s), high(q)
		{
			table=new element*[wide];
			for(int i=0;i<high;i++)
				table[i]=new element[wide];
			for(int i=0;i<wide;i++)
					for(int j=0;j<high;j++)
						if(i==j)
						{table[i][j]=1;} 
						else 
						{table[i][j]=0;};
		};

		~Matrix()
		{
			for(int i = 1; i < high; i++)
  				delete[] table[i];
			delete[] table;	
		}

		const int Wide()
		{ 
			return(wide);
		};
		
		const int High()
		{
			return(high);
		}
	
		const void PrintTable()
		{		
			for(int i=0;i<wide;i++)
			{
				for(int j=0;j<high;j++)
					cout<<table[i][j]<<"|";;
					
				cout<<"\n";			
			}
		};
		
		const void ScanMatrix()
		{
			for (int i=0;i<wide;i++)
				for(int j=0;j<high;j++)
					cin>>table[i][j];	
		}
	
		double const Trace()
		{
			if(wide==high)
			{
				element tr=0;
				for (int i=0;i<wide;i++)
					tr+=table[i][i];
				return(tr);
			}
			else
				cout<<"error trace";
				return(0);
		};

		Matrix const Trans()
		{
			if(high==wide)
			{
				Matrix a(high,wide);
				for (int i=0;i<wide;i++)
					for(int j=0;j<high;j++)
						a.table[i][j]=table[j][i];
				return(a);
			}
			else
				cout<<"error trans";
				return(*this);
		};
	

		void ToDiagUp()
		{	
			element co;
			if(high==wide)
				for(int i=0;i<wide-1;i++)
					{
						if(table[i][i]==0)
						{
							int p=i;
							while((table[p][i]==0)&&(p<wide)){p++;};
							for(int k=0;k<wide;k++)
							{
								co=table[p][k];
								table[p][k]=table[i][k];
								table[i][k]=co;
							};
							det*=-1;
						}	
						if(table[i][i]!=0)
							for(int j=i+1;j<wide;j++)
							{
								element b=table[j][i]/table[i][i];
								for(int k=i;k<wide;k++)
								{	
									table[j][k]-=b*table[i][k];
								}
							}
					}
		}

		Matrix ToDiagUpWith(const Matrix<element>& a)
		{	
			element co;
			
			for(int i=0;i<wide-1;i++)
				{
					if(table[i][i]==0)
					{
						int p=i;
						while((table[p][i]==0)&&(p<wide)){p++;};
						for(int k=0;k<wide;k++)
						{
							co=table[p][k];
							table[p][k]=table[i][k];
							table[i][k]=co;
							co=a.table[p][k];
							a.table[p][k]=a.table[i][k];
							a.table[i][k]=co;
						};
						det*=-1;
					}	
					if(table[i][i]!=0)
						for(int j=i+1;j<wide;j++)					
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

		Matrix ToDiagDownWith(const Matrix<element>& a)
		{	
			element co;
			
			for(int i=wide-1;i>0;i--)
				
				{
					if(table[i][i]==0)
					{
						int p=i;
						while((table[p][i]==0)&&(p>=0)){p--;};
						for(int k=wide-1;k>=0;k--)
						{
							co=table[p][k];
							table[p][k]=table[i][k];
							table[i][k]=co;
							co=a.table[p][k];
							a.table[p][k]=a.table[i][k];
							a.table[i][k]=co;
						};
						det*=-1;
					}	
					
					
					if(table[i][i]!=0)
						for(int j=i-1;j>=0;j--)
						{	
							element b=table[j][i]/table[i][i];
							for(int k=wide-1;k>=i;k--)
							{	
								a.table[j][k]-=b*a.table[i][k];
								table[j][k]-=b*table[i][k];
							}
						}
				}
	
			return(a);
		}

		
		double const Determ()
		{	
			if(wide==high)
			{
				det=1;

				Matrix<element> table1(*this);
				table1.ToDiagUp();
			
				for(int i=0;i<wide;i++)
					det*=table1.table[i][i];
				return(det);
			}
			else
				cout<<"error";	
				return(0);
		};
			
		Matrix const Reversed()
		{
			if(high==wide)
			{
				Matrix<element> edinst(wide,high);
				Matrix<element> table1(*this);
				table1.ToDiagUpWith(edinst);
				table1.ToDiagDownWith(edinst);
				
				for(int i=0;i<wide;i++)
					if(table1.table[i][i]!=0)
						for(int j=0;j<wide;j++)
							edinst.table[i][j]*=1.0/table1.table[i][i];					
				
				return(edinst);
			}
			else
			{
				cout<<"error";
				return(*this);
			}
		};
		
		Matrix const operator*(Matrix & other)
		{
			if(high==other.wide)
			{
				element b;
				Matrix mult(wide,other.high);
				for (int i=0;i<high;i++)
					for(int j=0;j<wide;j++)
					{
						b=0;
						for(int a=0;a<wide;a++)
						b+=table[a][i]*other.table[j][a];
						mult.table[j][i]=b;
					};
				return(mult);
			}
			else
				cout<<"error";
				return(*this);
		};

		Matrix const operator+(Matrix & other)
		{
			if((high == other.high) && (wide == other.wide))
			{
				Matrix sum(wide);
				for (int i=0;i<wide;i++)
					for(int j=0;j<wide;j++)
						sum.table[i][j]=table[i][j]+other.table[i][j];
				return(sum);
			}
			else
				cout<<"error";
				return(*this);
		};

		element *operator[](int i)
		{
			return(table[i]);
		};
		
		
};



int main(){
	Matrix<double> a(3,3);
	a.ScanMatrix();
	Matrix<double> b(a.Reversed());
	a=a*b;
	a.PrintTable();
	
	
	return(0);
};
