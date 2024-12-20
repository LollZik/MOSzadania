#include <stdio.h>

// getch() potrzebuje <conio.h> ktorego nie ma na linuxie (chyba),
// a jego alternatywy są na oko zjebane, to zamiast #include'owac jakies losowe rzeczy
// Uzywam getchar()

int main() {
    int Tab[26] = {0};
    int n = 0;
    char c;

    printf("Wypisuj litery: ");

    while ((c = getchar()) != 27) {    

        if(c>='A' && c<='Z'){
            Tab[c-'A']++; 
            n++;
        }
        else if(c>='a' && c<='z'){
            Tab[c-'a']++; 
            n++;
        }
        
    }


    printf("Wypisano ogolem %d znakow w tym:\n",n);
    for (int i = 0; i < 26; i++) {

        printf("Litera %c %d ", 'A'+i, Tab[i]);
        
        for(int j = 0;j<Tab[i];j++){
            printf("#");
        }
        printf("\n");

    }

    return 0;
}
