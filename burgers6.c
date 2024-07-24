
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//cal trobar bona nu, canviar discretitzacions de t i de x
//cal canviar la sigma i posar-la adimensional, unorm(valor dimensional)

#define g 9.8
#define h 100
#define u0 pow(g*h,1.0/2.0)
#define nu 0.967*pow(10,-6)
#define x0 200
#define t0 x0/(u0)
#define Nx 100
#define Nt 1000


double unorm(double u);
double xnorm(double x);
double tnorm(double t);


double U[Nx][Nx][2];


int main(){
    //Discretitzacions i nombre d'intervals
    
    double dx=0.01;
    double dt=0.49*pow(dx,2); 
   
    double gamma=dt/dx;
    double kappa=nu/(u0*x0);
    FILE* output; //generem un fitxer que direm output 
    //output=fopen("C:\\Users\\surfi\\Desktop\\MN pr lliure\\Burgers_definitiu3.txt","w"); // w de write
    char buffer[200];
    //u_old`[Nx+1][Nx+1]
    //u_new
    
    //el primer es la posició(j) el segon es el temps(i)
    
    
    for (int k = 0; k < Nx; k++)
    { 
        for (int j = 0; j < Nx; j++)
        {
            U[j][k][0]=unorm(u0)*exp(-pow(j*dx-0.5, 2)/(2*pow((xnorm(4.8)),2)));
        }
    }
    
    
    for (int i = 0; i < Nt; i++)
    {
        
        for (int j = 1; j < Nx-1; j++)
        {       
            
            U[j][0][1]=U[j][0][0]-gamma/4*(pow(U[j+1][0][0],2)-pow(U[j-1][0][0],2))+pow(gamma,2)/8*((U[j][0][0]+U[j+1][0][0])*(pow(U[j+1][0][0],2)-pow(U[j][0][0],2))-(U[j][0][0]+U[j-1][0][0])*(pow(U[j][0][0],2)-pow(U[j-1][0][0],2)))+kappa*dt/(pow(dx,2))*(U[j+1][0][0]-2.0*U[j][0][0]+U[j-1][0][0]+U[j][1][0]-2.0*U[j][0][0]+U[j][Nx-1][0]);


            U[j][Nx-1][1]=U[j][Nx-1][0]-gamma/4*(pow(U[j+1][Nx-1][0],2)-pow(U[j-1][Nx-1][0],2))+pow(gamma,2)/8*((U[j][Nx-1][0]+U[j+1][Nx-1][0])*(pow(U[j+1][Nx-1][0],2)-pow(U[j][Nx-1][0],2))-(U[j][Nx-1][0]+U[j-1][Nx-1][0])*(pow(U[j][Nx-1][0],2)-pow(U[j-1][Nx-1][0],2)))+kappa*dt/(pow(dx,2))*(U[j+1][Nx-1][0]-2.0*U[j][Nx-1][0]+U[j-1][Nx-1][0]+U[j][0][0]-2.0*U[j][Nx-2][0]+U[j][Nx-1][0]);
        }    
                
            U[0][0][1]=U[1][0][1];
            U[0][Nx-1][1]=U[1][Nx-1][1];

            
            U[Nx-1][0][1]=U[Nx-2][0][1];
            U[Nx-1][Nx-1][1]=U[Nx-2][Nx-1][1];
            
        
        for (int k = 1; k < Nx-1; k++)
        {
          for (int j = 1; j < Nx-1; j++)
        {          
            
            U[j][k][1]=U[j][k][0]-gamma/4*(pow(U[j+1][k][0],2)-pow(U[j-1][k][0],2))+pow(gamma,2)/8*((U[j][k][0]+U[j+1][k][0])*(pow(U[j+1][k][0],2)-pow(U[j][k][0],2))-(U[j][k][0]+U[j-1][k][0])*(pow(U[j][k][0],2)-pow(U[j-1][k][0],2)))+kappa*dt/(pow(dx,2))*(U[j+1][k][0]-2.0*U[j][k][0]+U[j-1][k][0]+U[j][k+1][0]-2.0*U[j][k][0]+U[j][k-1][0]);
            
        }  
            U[0][k][1]=U[1][k][1];
            
            U[Nx-1][k][1]=U[Nx-2][k][1];
        
        }

        //u_old = u_new
        for (int k = 0; k < Nx; k++)
        {
          for (int j = 0; j < Nx; j++)
            {    
                U[j][k][0] = U[j][k][1];
            }
        }

        //imprimim en fitxer la iteracio actual
        sprintf(buffer, "C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio2\\Burgers_iteracio_%d.txt", i);
        output = fopen(buffer, "w");

            for (int k = 0; k < Nx; k++){
            
            for (int j = 0; j < Nx; j++)
            {
                fprintf(output,"%.10lf    ",U[j][k][1]*u0);             
            }
            fprintf(output, "\n");
        }  
        fprintf(output, "\n");

        fclose(output);

       /*
        if (i<30)
        {
            sprintf(buffer, "C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio\\Burgers_iteracio_%d.txt", i);
            output = fopen(buffer, "w");

            for (int k = 0; k < Nx; k++){
            
            for (int j = 0; j < Nx; j++)
            {
                fprintf(output,"%.10lf    ",U[j][k][1]*u0);             
            }
            fprintf(output, "\n");
        }  
        fprintf(output, "\n");

        fclose(output);
        }
        
        if (i>=30 && i%10 == 0 ){
            sprintf(buffer, "C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio\\Burgers_iteracio_%d.txt", i/10+27);
            output = fopen(buffer, "w");

            for (int k = 0; k < Nx; k++){
            
            for (int j = 0; j < Nx; j++)
            {
                fprintf(output,"%.10lf    ",U[j][k][1]*u0);             
            }
            fprintf(output, "\n");
        }  
        fprintf(output, "\n");

        fclose(output);

        }
    */
        
    }


    return 0;
}

double xnorm(double x){
    double xnorm=x/(x0);
    return xnorm;
}
double unorm(double u){
    double unorm=u/(u0);
    return unorm;
}
double tnorm(double t){
    double tnorm=t/(t0);
    return tnorm;
}


