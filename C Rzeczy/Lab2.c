#include <stdio.h>
#include <math.h>

void zad1(){
    int kolumny;
    int wiersze;
    printf("Zad 1\nPodaj liczbe wierszy\n");
    scanf("%d",&wiersze);
    printf("Podaj liczbe kolumn\n");
    scanf("%d",&kolumny);
    printf("    |     ");
    for (int k=1; k-1<kolumny;k++){
        printf("%-3d ",k);
    }
    printf("\n");
    for (int k=1; k-1<kolumny;k++){
        printf("-----");
    }
    for(int i =1;i-1<wiersze;i++){
        printf("\n%2d  |  ",i);
        for(int j=1;j-1<kolumny;j++){
            printf("%4d",i*j);
        }
        
    }
    printf("\n-----------------Koniec zadania 1------------\n");
}



void zad2(){
    long liczba;
    int suma = 0;
    printf("Zadanie 2\n");
    printf("Podaj liczbe\n");
    scanf("%ld",&liczba);
    while(liczba>0){
        suma+=liczba%10;
        liczba = liczba/10;
    }
    printf("Suma cyfr tej liczby wynosi %d\n",suma);
    printf("\n-----------------Koniec zadania 2------------\n");


}

int NWD(int a, int b){
    int pom;
    while(b!=0){
        pom = b;
        b=a%b;
        a=pom;
    }
    return a;
}

int NWW(int a, int b){
    return(a*b/NWD(a,b));
}

void zad3(){
    int a;
    int b;
    int nwd;
    int nww;
    printf("Podaj pierwszą liczbę:\n");
    scanf("%d",&a);
    printf("Podaj drugą liczbę:\n");
    scanf("%d",&b);
    nwd = NWD(a,b);
    nww = NWW(a,b);
    printf("NWD tych liczb wynosi %d, a NWW %d\n",nwd,nww);
    printf("\n-----------------Koniec zadania 3------------\n");


}


void zad4(){
    double eps;
    printf("Podaj wartość eps:\n");
    scanf("%lf",&eps);

    double suma1 = 1;
    double suma2 = 1;
    int k = 1;
    double temp = 0.0;
    do{
        temp = 1.0/(2*k+1);
        k++;
        if(k%2==0){
        suma1-=temp;
        }
        else{
            suma1+=temp;
        }
    }while(fabs(temp)>eps);

    suma1*=4;
    temp=1.0;
    k=1;

    do{
        temp = temp/k;
        k++;
        suma2+=temp;
    }while(fabs(temp)>eps);
    printf("\nSuma pierwszego szeregu wynosi %lf a suma drugiego %lf",suma1,suma2);
    printf("==========================================\n\n-----------------Koniec zadania 4 (i całego programu)------------\n");
}


int main(){
    zad1();
    zad2();
    zad3();
    zad4();
    return 0;
}