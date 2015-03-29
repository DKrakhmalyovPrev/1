#include <iostream>

#include <stdio.h>

#include <cstdlib>

#include <math.h>


using namespace std;

template<typename element>
class Matrix
{	
	
	private:
		
		int i,j;
		element co,b,tr;
	
	public:
		int wide;
		element **table;
		
		Matrix(int s)
		{
			wide=s;
			table=new element*[wide];
			for(i=0;i<wide;i++)
				table[i]=new element[wide];
			for (i=0;i<wide;i++)
				for(j=0;j<wide;j++)
					table[i][j]=rand() % 300 - 150;
					//cin>>table[i][j];
		};

		Matrix(const Matrix<element>& a)
		{
			wide=a.wide;
			table=new element*[wide];
			for(i=0;i<wide;i++)
				table[i]=new element[wide];
			for(i=0;i<wide;i++)
				for(j=0;j<wide;j++)
					table[i][j]=a.table[i][j];
		};

		Matrix(int s, int i): wide(s)
		{
			table=new element*[wide];
			for(i=0;i<wide;i++)
				table[i]=new element[wide];
		};

		int Rasmer()
		{ 
			return(wide);
		};
		
		void PrintTable()
		{		
			for(i=0;i<wide;i++)
			{
				for(j=0;j<wide;j++)
					printf("%.2lf ", table[i][j]);
					//cout<<table[i][j]<<" ";
			cout<<"\n";
			}
		};
		
		double Trace()
		{
			tr=0;
			for (i=0;i<wide;i++)
				tr+=table[i][i];
			return(tr);
		};

		Matrix Trans()
		{
			Matrix a(wide,1);
			for (i=0;i<wide;i++)
				for(j=0;j<wide;j++)
					a.table[i][j]=table[j][i];
			return(a);
		};

		double Determ()
		{
			double det=1;
			int i,j,k,p;
			Matrix<element> table1(*this);
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++)
					table1.table[i][j]=table[i][j];
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++)
				{
					if(table1.table[i][i]==0)
					{
						p=i;
						while((table1.table[p][i]==0)&&(p+1<wide)){p++;};
						for(k=0;k<wide;k++)
						{
							co=table1.table[p][i];
							table1.table[p][k]=table1.table[i][k];
							table1.table[i][k]=co;
						};
						det*=-1;
					};	
					if(table1.table[i][i]!=0)
					{
						b=table1.table[j][i]/table1.table[i][i];
						for(k=i;k<wide;k++)
							table1.table[j][k]-=b*table1.table[i][k];
					};
				};
			for(i=0;i<wide;i++)
				det*=table1.table[i][i];
			return(det);	
		};
			
		Matrix Reversed()
		{
			int i,j,k,p; double det;
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
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++)
				{
					if(table1.table[i][i]==0)
					{
						p=i;
						while( (table1.table[p][i]==0) && (p+1<wide) )
						{
							p++;
						};
						for(k=0;k<wide;k++)
						{
							co=table1.table[p][i];
							table1.table[p][k]=table1.table[i][k];
							table1.table[i][k]=co;
							co=edinst.table[p][i];
							edinst.table[p][k]=edinst.table[i][k];
							edinst.table[i][k]=co;
						};
					det*=-1;
					};
					if(table1.table[i][i]!=0)
					{	
						b=table1.table[j][i]/table1.table[i][i];
						for(k=i;k<wide;k++)
						{
							table1.table[j][k]-=b*table1.table[i][k];
							edinst.table[j][k]-=b*edinst.table[i][k];
						};	
					};	
				};	
			for(i=0;i<wide;i++)
				det*=table1.table[i][i];
				element **revers=new element*[wide];
			
				for(i=0;i<wide;i++)
					revers[i]=new double[wide];

				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						revers[i][j]=table1.table[j][i];
			
				element **reversedin=new element*[wide];

				for(i=0;i<wide;i++)
					reversedin[i]=new double[wide];

				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						reversedin[i][j]=edinst.table[j][i];

				for(i=0;i<wide;i++)
					for(j=i+1;j<wide;j++)
						edinst.table[i][j]=reversedin[i][j];

				for(i=0;i<wide;i++)
					for(j=i+1;j<wide;j++)
					{
						if(revers[i][i]==0)
						{
							p=i;
							while( (revers[p][i]==0) && (p+1<wide) )
							{
								p++;
							};
							for(k=0;k<wide;k++)
							{
								co=revers[p][i];
								revers[p][k]=revers[i][k];
								revers[i][k]=co;
								co=edinst.table[p][i];
								edinst.table[p][k]=edinst.table[i][k];		
								edinst.table[i][k]=co;
							};
						};
						if(revers[i][i]!=0)
						{
							b=revers[j][i]/revers[i][i];
							for(int k=i;k<wide;k++)
							{
								revers[j][k]-=b*revers[i][k];
								edinst.table[j][k]-=b*edinst.table[i][k];
							};
						};
					}
				for(i=0;i<wide;i++)
					if(revers[i][i]!=0)
						edinst.table[i][i]*=1/revers[i][i];
			
				if(det==0){printf("No reverced matrix");} else

				return(edinst);
		};
			
		Matrix operator*(Matrix & other)
		{
			Matrix mult(wide,1);
			for (i=0;i<wide;i++)
				for(j=0;j<wide;j++)
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
			for (i=0;i<wide;i++)
				for(j=0;j<wide;j++)
					sum.table[i][j]=table[i][j]+other.table[i][j];
			return(sum);
		};

		double *operator[](int i)
		{
			return(table[i]);
		};

		friend ostream& operator<<(ostream &out,Matrix &x)
		{
	        	for(int i=0;i<x.wide;i++)
			{
			        for(int j=0;j<x.wide;j++)
			            out<<x.table[i][j]<<" ";
        				out<<endl;
    			}
    			out<<x.wide<<" "<<x.wide;
		return out;
		}

	
		

};

/*void PrintMatrix(Matrix<double>& a)
{
   for (int i = 0; i < a.wide ; ++ i)
   {
      for (int j = 0; j < a.wide ; ++ j)
         printf ("%5.3lf ", a.table[i][j]);
      puts ("");
   }
}
*/
int main(){
	int i,j; 
	Matrix<double> odin(50);
	odin.PrintTable();
	printf("\n Обратная матрица \n");
	Matrix<double> odint(odin.Reversed());
	odint.PrintTable();
	//Matrix<double> odint(odin);
	//cout << odin;
	//odin.PrintTable();
	
	
return(0);
};
