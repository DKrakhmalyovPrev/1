#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Matrix{
	public:
		Matrix(int wide){	
				table=(double**)malloc(wide*sizeof(double));
				for(i=0;i<wide;i++)
					table[i]=(double*)malloc(wide*sizeof(double));
				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						cin>>table[i][j];
					
			};

		Matrix(Matrix a){
						wide=a.wide;
							table=(double**)malloc(wide*sizeof(double));
							for(i=0;i<wide;i++)
									table[i]=(double*)malloc(wide*sizeof(double));
							table=a.table;
		};

		Matrix(int wide, int i){
						 
							table=(double**)malloc(wide*sizeof(double));
							for(i=0;i<wide;i++)
									table[i]=(double*)malloc(wide*sizeof(double));
		};

		void PrintTable(){
				for (i=0;i<wide;i++){
					for(j=0;j<wide;j++)
						cout<<table[i][j];
					cout<<"\n";}
				};
		double Trace(){	
				tr=0;
				for (i=0;i<wide;i++)
					tr+=table[i][i];
					//printf("Trace is %lf", tr);
					return(tr);
				};
		

		Matrix Trans(){	
				Matrix a(wide,1);
				/*transtable=(double**)malloc(wide*sizeof(double));
				for(i=0;i<wide;i++)
					transtable[i]=(double*)malloc(wide*sizeof(double));	*/	
				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						a.table[i][j]=table[j][i];
				/*for (i=0;i<wide;i++){
					for(j=0;j<wide;j++)
						printf("%lf ", transtable[i][i]);
					printf("\n");};
					*/
				return(a);
				};
		
		void Determ(){
			double det=1;
			int i,j,k,p;
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++){
					if(table[i][i]==0){
						p=i;
						while((table[p][i]==0)&&(p<wide-1)){p++;};
						for(k=0;k<wide;k++){
							co=table[p][i];
							table[p][k]=table[i][k];
							table[i][k]=co;
							};
						det*=-1;
					};	
					if(table[i][i]!=0){
						b=table[j][i]/table[i][i];
						for(k=i;k<wide;k++)
							table[j][k]-=b*table[i][k];
					};
				};
			for(i=0;i<wide;i++)
				det*=table[i][i];
			cout<<det;	
			};
			
			
		Matrix Reversed(){
			int i,j,k,p; double det;
			Matrix edinst(wide,1);
			//edinst=(double**)malloc(wide*sizeof(double));
				//for(i=0;i<wide;i++)
					//edinst[i]=(double*)malloc(wide*sizeof(double));	
			for(i=0;i<wide;i++)
				for(j=0;j<wide;j++)
					if(i==j){edinst.table[i][j]=1;} else {edinst.table[i][j]=0;};			
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++){
					if(table[i][i]==0){
						p=i;
						while((table[p][i]==0)&&(p<wide-1)){p++;};
						for(k=0;k<wide;k++){
							co=table[p][i];
							table[p][k]=table[i][k];
							table[i][k]=co;
							co=edinst.table[p][i];
							edinst.table[p][k]=edinst.table[i][k];
							edinst.table[i][k]=co;
							};
						det*=-1;
					};	
					if(table[i][i]!=0){
						b=table[j][i]/table[i][i];
						for(k=i;k<wide;k++){
							table[j][k]-=b*table[i][k];
							edinst.table[j][k]-=b*edinst.table[i][k];
					};};
				};
			for(i=0;i<wide;i++)
				det*=table[i][i];

			revers=(double**)malloc(wide*sizeof(double));
				for(i=0;i<wide;i++)
					revers[i]=(double*)malloc(wide*sizeof(double));		
				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						revers[i][j]=table[j][i];
			reversedin=(double**)malloc(wide*sizeof(double));
				for(i=0;i<wide;i++)
					reversedin[i]=(double*)malloc(wide*sizeof(double));		
				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						reversedin[i][j]=edinst.table[j][i];
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++)
					edinst.table[i][j]=reversedin[i][j];
						
			for(i=0;i<wide;i++)
				for(j=i+1;j<wide;j++){
					if(revers[i][i]==0){
						p=i;
						while((revers[p][i]==0)&&(p<wide-1)){p++;};
						for(k=0;k<wide;k++){
							co=revers[p][i];
							revers[p][k]=revers[i][k];
							revers[i][k]=co;
							co=edinst.table[p][i];
							edinst.table[p][k]=edinst.table[i][k];
							edinst.table[i][k]=co;
							};
					};	
					if(revers[i][i]!=0){
						b=revers[j][i]/revers[i][i];
						for(k=i;k<wide;k++){
							revers[j][k]-=b*revers[i][k];
							edinst.table[j][k]-=b*edinst.table[i][k];
						};
					};
				};
			for(i=0;i<wide;i++)
				if(revers[i][i]!=0)
					edinst.table[i][i]*=1/revers[i][i];
			
			if(det==0){printf("No reverced matrix");} else
			//for(i=0;i<wide;i++){
				//for(j=0;j<wide;j++)
					//printf("%.2lf ", edinst.table[i][j]);
				//printf("\n");};
			return(edinst);
		};
			

		Matrix operator*(Matrix & other){
				Matrix mult(wide,1);
				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++){
						b=0;
						for(a=0;a<wide;a++)
						b+=table[i][a]*other.table[a][j];
						mult.table[i][j]=b;
					};
				return(mult);
				};
		

		Matrix operator+(Matrix & other){
				Matrix sum(wide,1);
				for (i=0;i<wide;i++)
					for(j=0;j<wide;j++)
						sum.table[i][j]=table[i][j]+other.table[i][j];
				return(sum);
				};
				
		double *operator[](int i){
				return(table[i]);
		};
	
		
	int wide, i,j,a,c,k,p; double co,b,tr;
	double **table;
	double **transtable;
	double **mult;
	double **sum;
	double **revers;
	double **edinst;
	double **reversedin;
};
