#include <stdio.h>
#include <math.h>

/*




zad 1




*/
void zad1(){
    double a;
    double b;
    double c;
    double delta;
    double x1;
    double x2;
    printf("Zad 1\n");
    printf("Podaj współczynnik a: ");
    scanf("%lf",&a);
    printf("Podaj współczynnik b: ");
    scanf("%lf",&b);
    printf("Podaj współczynnik c: ");
    scanf("%lf",&c);

    if(a==0){
        printf("Równanie nie jest równaniem kwadratowym");
    }
    else{
        delta = b*b-4*a*c;
        if(delta<0){
            printf("Delta ujemna (%.2lf), brak rozwiązań",delta);
        }
        else if(delta ==0){
            x1 = -b/(2*a);
            printf("Równanie ma jedno rozwiązanie podwójne: %.2lf",x1);
        }
        else{
            x1 = -b-sqrt(delta)/(2*a);
            x2 = -b+sqrt(delta)/(2*a);
            printf("Równanie ma dwa rozwiązania: %.2lf oraz %.2lf",x1,x2);
        }
    }
    printf("\n-----------------Koniec zadania 1------------\n");

    
}
/*





zad 2




*/
void zad2(){
    int dzien;
    int miesiac;
    int rok;
    int war = 0;
    printf("Zad 2 \n");
    printf("Podaj dzień miesiąca:");
    scanf("%d",&dzien);
    printf("Podaj miesiąc:");
    scanf("%d",&miesiac);
    printf("Podaj rok:");
    scanf("%d",&rok);
    if(miesiac==2 && dzien==29){
        if(rok%4==0){
            if(rok%100==0 && rok%400!=0){
                printf("Wprowadzona data jest niepoprawna (29 luty w roku nieprzestępnym)\n");
                war = 1;
            }
        }
        else{
            printf("Wprowadzona data jest niepoprawna (29 luty w roku nieprzestępnym)\n");
            war = 1;
            
        }
    }
    else{
        if (miesiac==1 || miesiac == 3 || miesiac ==5 || miesiac ==7 || miesiac ==8 || miesiac == 10 || miesiac == 12){
            if(dzien>31 || dzien<1){
                    printf("Wprowadzona data jest niepoprawna (nieodpowiednia ilość dni)\n");
                    war = 1;
                }
        }
        else if(miesiac>12) {
            printf("Wprowadzona data jest niepoprawna (nie ma takiego miesiaca)\n");
            war = 1;
        }
        else if(miesiac==2){
            if(dzien>29 || dzien<1){
                    printf("Wprowadzona data jest niepoprawna (nieodpowiednia ilość dni)\n");
                    war = 1;
            }

        }
        else{
            if(dzien>30 || dzien<1){
                    printf("Wprowadzona data jest niepoprawna (nieodpowiednia ilość dni)\n");
                    war = 1;
            }
        }

    
    } if(war==0){
        printf("\nPodana data jest prawidłowa");
    }
    printf("\n-----------------Koniec zadania 2------------\n");
}

/*





zad 3







*/

void zad3(){
    double minr;
    double maxr;
    int lwierszy;

    printf("\n Zad 3\n");

    printf("Podaj minimalny promien:");
    scanf("%lf",&minr);
    printf("Podaj maksymalny promien:");
    scanf("%lf",&maxr);
    printf("Podaj ilosc wierszy:");
    scanf("%d",&lwierszy);

    double obwody[lwierszy];
    double pola[lwierszy];
    double promienie[lwierszy];
    double wzrost;

    double r = minr;
    double obw;
    double pole;

    if (lwierszy>1){
        wzrost = (maxr-minr)/(lwierszy-1.0);
    }
    else{
        wzrost = 0;
    }
    for(int i=0;i<lwierszy;i++){
        obw = r*M_PI*2;
        pole = r*r*M_PI;
        promienie[i] = r;
        obwody[i] = obw;
        pola[i] = pole;
        r = r+wzrost;
    }
    printf("==========================================\n| Lp | promien | obowod kola | pole kola |\n==========================================\n");
    for (int i=0;i<lwierszy;i++){
        printf("| %d |    %-4.2lf |    %-9.2lf |    %-6.2lf |\n",i+1,promienie[i],obwody[i],pola[i]);
    }
    printf("==========================================\n\n-----------------Koniec zadania 3 -----------\n");


}
    
    



int main(){
    zad1();
    zad2();
    zad3();
    return 0;
}

