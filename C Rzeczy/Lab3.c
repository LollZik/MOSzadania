#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR 5
float Tab[ROZMIAR];


void wypelnijtabele1(){ //Wybieranie ręcznie tak jak w zad 1 chcieli
printf("Wypisz %d elementów typu float:\n",ROZMIAR);
    for (int i=0;i<ROZMIAR;i++){
        scanf("%f",&Tab[i]);
    }
}

void zad2(){
    float max;
    float min;
    float losowa;

    printf("Wylosowane zostanie %d liczb\n",ROZMIAR);
    printf("Podaj maksymalną liczbe:\n");
    scanf("%f",&max);
    min = -max;

    for (int i = 0;i<ROZMIAR;i++){
        losowa = min + (max-min)*rand()/((double)RAND_MAX);
        Tab[i] = losowa;
    }

}

void zad1(){
    int liczbadodatnich = 0;
    float sumadodatnich = 0;
    int liczbaujemnych = 0;
    float sumaujemnych = 0;

    float srednia = 0;
    bool czyrosnaco = true;
    bool czymalejaco = false;



    printf("\nTab = [  ");
    for(int i = 0;i<ROZMIAR;i++){
        printf("%.2f  ",Tab[i]);
        srednia += Tab[i];
    }

    printf("]\n");

    for(int i=0;i<ROZMIAR-1;i++){
        if (Tab[i]<0){
            liczbaujemnych++;
            sumaujemnych +=Tab[i];
        }
        else{
            liczbadodatnich++;
            sumadodatnich += Tab[i];
        }
        if (Tab[i]<Tab[i+1]){
            czymalejaco = false;
        }
        if(Tab[i]>Tab[i+1]){
            czyrosnaco = false;
        }
    }
    if (Tab[ROZMIAR-1]<0){
            liczbaujemnych++;
            sumaujemnych +=Tab[ROZMIAR-1];
        }
        else{
            liczbadodatnich++;
            sumadodatnich += Tab[ROZMIAR-1];
        }

    printf("\nW tabeli znaduje się %d liczb dodatnich (Suma = %f),\n%d liczb ujemnych (Suma = %f),\nśrednia wszystkich liczb wynosi %f,",liczbadodatnich,sumadodatnich,liczbaujemnych,sumaujemnych,(srednia/ROZMIAR));
    if(czyrosnaco){
        printf("\nTabela jest posortowana rosnąco\n");
    }
    else if(czymalejaco){
        printf("\nTabela jest posortowana malejaco\n");
    }
    else{
        printf("\nTabela nie jest posortowana\n");
    }

} 

void zad3(){
    float temp;
    int k;
    for (int i=1;i<ROZMIAR;i++){
        k=i-1;
        temp = Tab[i];
        while(k >=0 && Tab[k]>temp){
                Tab[k+1] = Tab[k];
                k--;
        }
        Tab[k+1] = temp;
    }
    printf("\nPosortowano tablice\n");
    zad1();
}

int main(){
    srand(time(0));
    zad2();
    zad1();
    zad3();
    return 0;
}