/*
By: Caio Felipe Poreto
*/ 

#include <stdio.h>
#include <math.h>

#define MAXIT 1000

double funcao(double x){
 
    return (10 - exp(-2*x/1)*(10-3*x))/x - 20;
}

double derivada_funcao(double x){
 
    return (20*exp(-2*x)-3*exp(-2*x) + 6*x*exp(-2*x)*x - 10 - exp(-2*x)*10 - 3*x*exp(-2*x));
}

int main(){
    double x, delta_x, x_anterior;
    double max, min;
    max = 1;
    min = 0;
    int i=1;
    double RTOL = 0.0000000000000001;

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
        }
        else{
            x_anterior = x;
            x = (max+min)/2;
        }

        if(funcao(x) > 0){
            min = x;
        }
        else if (funcao(x) < 0){
            max = x;
        }
    
        delta_x = x - x_anterior;
        
    }while(i < MAXIT && funcao(x) != 0 && fabs(delta_x) >= RTOL * fabs(x));
    
    printf("%.50lf %d\n", x, i);
    return 0;
}