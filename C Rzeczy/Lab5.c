#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Nie mam tych pdf'ow z przykladami wiec robie na czuja xd


void InitTab(char ***wsk){
    *wsk = (char **)malloc(sizeof(char*));
    (*wsk)[0] = NULL;
    printf("Tablica zainicjowana\n");
}

void AddName(char *buf, char ***wsk){
    int i = 0;
    while((*wsk)[i]!=NULL){
        i++;
    }

    *wsk = (char **)realloc(*wsk,sizeof(char*)*(i+2));
    (*wsk)[i] = (char *)malloc(sizeof(char)*(strlen(buf)+1));
    (*wsk)[i]= strdup(buf);
    (*wsk)[i+1] = NULL;
}

void RemoveNamebyIndex(int nr, char ***wsk){

    int i = 0;
    while((*wsk)[i]!=NULL){
        i++;
    }
    if(nr>i){
        printf("Nie ma takiego indeksu\n");
        return;
    }
    for(int j = nr; j<i; j++){
        (*wsk)[j] = (*wsk)[j+1];
    }
    (*wsk)[i-1] = NULL;
    free((*wsk)[i]);
    printf("Imie usuniete\n");
}

void RemoveName(char *buf, char ***wsk){
    int i = 0;
    while((*wsk)[i]!=NULL){
        if((*wsk)[i] == buf){
            int j = i;
            i++;
            while((*wsk)[i] != NULL){
                (*wsk)[j] = (*wsk)[i];
                j++;
                i++;
            }
            (*wsk)[j] = NULL;
            free((*wsk)[i]);
        }
        i++;
    }
}



void PrintAllNames(char ***wsk){
    int i = 0;
    printf("Wszystkie imiona:\n");
    while((*wsk)[i]!=NULL){ 
        printf("%s\n",(*wsk)[i]); 
        i++;
        
    }
    
}


void PrintNames(char first_letter, char ***wsk){
    int i = 0;
    printf("Imiona zaczynajace sie na %c:\n",first_letter);
    while((*wsk)[i]!=NULL){
        if( (*wsk)[i][0] == first_letter){
            printf("%s\n",(*wsk)[i]);
        }
        i++;
    }
}

// sortowanie alfabetem
void SortAlphabet(char ***WSK) {
    int c = 0;
    while ((*WSK)[c] != NULL) {
        c++;
    }

    for (int i = 0; i<c-1; i++) {
        for (int j = i+1; j<c; j++) {
            if (strcmp((*WSK)[i], (*WSK)[j]) > 0) {
                char *temp = (*WSK)[i];
                (*WSK)[i] = (*WSK)[j];
                (*WSK)[j] = temp;
            }
        }
    }
}

// sortowanie rosnąco
void SortLength(char ***wsk){
    int i = 0;
    int j = 0;
    while((*wsk)[i+1]!=NULL){
        if( strlen((*wsk)[i]) > strlen((*wsk)[i+1]) ){
            char *tmp = (*wsk)[i];
            (*wsk)[i] = (*wsk)[i+1];
            (*wsk)[i+1] = tmp;
        }
        i++;
    }
    while((*wsk)[j+1]!=NULL){
        if( strlen((*wsk)[j]) > strlen((*wsk)[j+1]) ){
            char *tmp = (*wsk)[j];
            (*wsk)[j] = (*wsk)[j+1];
            (*wsk)[j+1] = tmp;
        }
        j++;
    }
}

int main(){
    char **WSK;

    char buf[81];

    InitTab(&WSK);
    //Menu
    bool warunek = true;
    bool koniec = true;
    while(warunek&&koniec){
        bool koniec = false;
        printf("\n1. Dodaj imie\n2. Usun imie (indexem)\n3. Usun imie (wpisz imie)\n4. Wyswietl wszystkie imiona\n5. Wyswietl imiona zaczynajace sie na dana litere\n6. Posortuj alfabetycznie\n7. Posortuj wedlug dlugosci\n8. Wyjdz\n");
        int wybor;
        scanf("%d",&wybor);
        getchar();
        switch(wybor){
            case 1:
                printf("Podaj imie: ");
                fgets(buf, 81, stdin);
                buf[strcspn(buf, "\n")] = '\0';
                printf("\n\nImie dodane: %s\n",buf);
                AddName(buf, &WSK);
                bool koniec = true; //Bez tego ponownie wyskakuje menu zanim wpiszesz imie
                break;
            case 2:
                printf("Podaj indeks: ");
                int indeks;
                scanf("%d",&indeks);
                RemoveNamebyIndex(indeks,&WSK);
                break;
            case 3:
                printf("Podaj imie: ");
                scanf("%s",&buf);
                RemoveName(buf,&WSK);
                break;
            case 4:
                PrintAllNames(&WSK);
                break;
            case 5:
                printf("Podaj litere: ");
                char litera;
                scanf(" %c",&litera);
                PrintNames(litera,&WSK);
                break;
            case 6:
                SortAlphabet(&WSK);
                printf("Posortowano alfabetycznie\n");
                break;
            case 7:
                SortLength(&WSK);
                printf("Posortowano wedlug dlugosci\n");
                break;
            case 8:
                warunek = false;
                break;
            default:
                printf("Nie ma takiej opcji\n");
                break;
        }
    }

    int i = 0;
    while(WSK[i] != NULL){
        free(WSK[i]);
        i++;
    }
    free(WSK);
    printf("Tablica zwolniona\n");
    return 0;
}

