#include <stdio.h>


void CzytajRownanie(float *a, float *b, float *c){
    printf("Podaj współczynnik a równania:\n");
    scanf("%f",a);
    printf("Podaj współczynnik b równania:\n");
    scanf("%f",b);
    printf("Podaj współczynnik c równania:\n");
    scanf("%f",c);
}

void WypiszRozwiązanie(int *N, float *x, float *y){
    if(*N==2){
        printf("Układ ma nieskończenie wiele rozwiązań\n");
    }
    else if(*N==1){
        printf("Układ ma jedno rozwiązanie: x = %f; y = %f\n",*x,*y);
    }
    else{
        printf("Równanie sprzeczne, brak rozwiązań\n");
    }
}

float ObliczWyznacznik(float *p1, float *p2, float *p3, float *p4){
    return (*p1 * *p4 - *p2 * *p3);
}

int ObliczRozwiązanie(float *a1, float *b1, float *c1, float *a2, float *b2, float *c2, float *x, float *y){
    float W = ObliczWyznacznik(a1,b1,a2,b2);
    float Wx = ObliczWyznacznik(c1,b1,c2,b2);
    float Wy = ObliczWyznacznik(a1,c1,a2,c2);

    if(W==0){
        if(Wx==0 && Wy==0){
            return 2;
        }
        else{
            return 0;
        }   
    }
    else{
        *x=Wx/W;
        *y=Wy/W;
        return 1;
    }
}

int main(int argc, char*argv[] )
{ float A1, B1, C1;
float *pA1, *pB1, *pC1;
pA1 = &A1;
pB1 = &B1;
pC1 = &C1;
float A2, B2, C2;
float *pA2, *pB2, *pC2;
pA2 = &A2;
pB2 = &B2;
pC2 = &C2;
float X, Y;
float *pX, *pY;
pX = &X;
pY = &Y;
int N;
int *pN= &N;
CzytajRownanie(pA1, pB1, pC1);
CzytajRownanie(pA2, pB2, pC2);
N = ObliczRozwiązanie(pA1, pB1, pC1, pA2, pB2, pC2, pX, pY);
WypiszRozwiązanie(pN, pX, pY);
return 0;
}