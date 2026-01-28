#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(double t,double *y,double *f,double *par);
void RK4(double t,double *y,double *f,double *par);

void main(int argc,char *argv[]){
  double h,par[3],G;
  double *y,*f,t,K;
  int i, n, T, Ne;
  FILE *fp;

  fp=fopen("solar1.dat","w");
  
  Ne=4;
  y=malloc(Ne*sizeof(double));
  f=malloc(Ne*sizeof(double));
  h=0.01;
  G=4*M_PI*M_PI;
  par[0]=h;   par[1]=Ne;  par[2]=G;
  
  y[0]=9.6;  // x
  y[1]=0;  // Vx
  y[2]=0      ;  // y
  y[3]=sqrt(G/y[0]);  // Vy

  T=10*pow(y[0],3./2);
  for(t=0;t<=T;t+=h){
    RK4(t,y,f,par);
    K=0.5*(y[1]*y[1]+y[3]*y[3]);
    fprintf(fp,"%lf %lf %lf %lf\n",t,y[0],y[2],K);
  }

  fclose(fp);
  free(y); free(f);
}

void fun(double t,double *y,double *f,double *par){
  double r123,G=par[2];
  
  r123=pow(y[0]*y[0]+y[2]*y[2],3./2);
  
  f[0]=y[1];
  f[1]=-G*y[0]/r123;
  f[2]=y[3];
  f[3]=-G*y[2]/r123;
}

void RK4(double t,double *y,double *f,double *par){
  double h,*ya,*acum,ta;
  int i,Ne,ki;
  double mask[4]={1./6.,1./3.,1./3.,1./6.}, maskty[4]={0,0.5,0.5,1};

  h=par[0]; Ne=par[1];
  
  ya=malloc(Ne*sizeof(double));
  acum=malloc(Ne*sizeof(double));

  for(i=0;i<Ne;++i) acum[i]=0; 

  for(ki=0;ki<4;++ki){
    ta=t+maskty[ki]*h;
    for(i=0;i<Ne;++i) ya[i]=y[i]+maskty[ki]*h*f[i];
    fun(ta,ya,f,par); // actualizamos todas las pendientes (en f)
    for(i=0;i<Ne;++i) acum[i]+=mask[ki]*h*f[i];
  }

  for(i=0;i<Ne;++i) y[i]+=acum[i];
  
  free(ya); free(acum);
}
