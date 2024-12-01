/*
By: Caio Felipe Poreto
*/ 

#include <stdio.h>
#include <math.h>

#define MAXIT 100

double funcao(double x){
 
    return 12-x-pow(10,-11)*(exp(40*x)-1); //write your function here
}

double derivada_funcao(double x){
 
    return -1-pow(10,-11)*exp(40*x)*40; //write your derived fuction here
}

int main(){

    double x; // x = x(n) in Newton-Raphson method
    double x_anterior; // x_anterior = x(n-1) in Newton-Raphson method
    double delta_x; // delta_x = x - x_anterior = x(n) - x(n-1)
    double max, min;
    max = 1;
    min = 0;
    int i=1;
    double RTOL = 0.0000000000000001; // RTOL is the tolerance chose for the root(s)

    if(fabs(funcao(max)) < fabs(funcao(min))){
        x = max;
    }
    else{
        x = min;
    }

    if(funcao(x) > 0){
        x_anterior = min;
        min = x;
    }
    else if (funcao(x) < 0){
        x_anterior = max;
        max = x;
    }

    delta_x = x - x_anterior;
    double condicao1 = ((x-min)*derivada_funcao(x)-funcao(x))*((x-max)*derivada_funcao(x)-funcao(x));
    double condicao2 = fabs(derivada_funcao(x)*delta_x) - 2*fabs(funcao(x));
    
    do{
        
        i++;
        condicao1 = ((x-min)*derivada_funcao(x)-funcao(x))*((x-max)*derivada_funcao(x)-funcao(x));
        condicao2 = fabs(derivada_funcao(x)*delta_x);

        if(condicao1 < 0 && condicao2 > 2*fabs(funcao(x))){
            x_anterior = x;
            x = x - funcao(x)/derivada_funcao(x);
            printf("METODO DE NEWTON\n");
        }
        else{
            x_anterior = x;
            x = (max+min)/2;
            printf("DICOTOMIA\n");
        }

        if(funcao(x) > 0){
            min = x;
        }
        else if (funcao(x) < 0){
            max = x;
        }
    
        delta_x = x - x_anterior;
        
    }while(i < MAXIT && funcao(x) != 0 && fabs(delta_x) >= RTOL * fabs(x));
    
    printf("%.50lf %d\n", x, i); // prints the root found and the number of iteractions
    
    return 0;
}