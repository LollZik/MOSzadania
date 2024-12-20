#include <stdio.h>
#include <string.h>

int moje_strlen1(const char *str){
    const char *s = str;
    while(*s){

        s++;
    }
    return s-str;
}

int moje_strlen2(const char *str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}


int moje_strcspn1(const char *str1, const char *str2){
    const char *s = str1;
    while(*s != *str2){
        s++;
    }
    return s-str1;
}

int moje_strcspn2(const char *str1, const char *str2){
    int i = 0;
    while(str1[i] != str2[i]){
        i++;
    }
    return i;
}

int moje_strcmp1(const char *str1, const char *str2){
    const char *s1 = str1;
    const char *s2 = str2;
    while(*s1 == *s2 && *s1){
        s1++;
        s2++;

    }
    int a1 = *s1;
    int a2 = *s2;
    if(a1>a2){
        return 1;
    }
    else if(a1<a2){
        return -1;
    }
    else{
    return 0;}

}

int moje_strcmp2(const char *str1, const char *str2){
    int i = 0;
    while(str1[i] == str2[i] & str1[i]!='\0'){
        i++;

    }
    int a1 = str1[i];
    int a2 = str2[i];
    if(a1>a2){
        return 1;
    }
    else if(a1<a2){
        return -1;
    }
    else{
    return 0;}}

char *moje_strcpy1(char *dest, const char *src){
    while (*src) {   
        *dest = *src; 
        dest++;         
        src++;          
    }
    *dest = '\0';  
    return dest;      
}

char *moje_strcpy2(char *dest, const char *src){
    int i = 0;
    while (src[i] !='\0') {   
        dest[i] = src[i]; 
        i++;          
    }
    dest[i] = '\0';  
    return dest;      
}

char* moje_strupr1(char * s){
    while(*s != '\0'){
        if(*s>='a' && *s<='z'){
            *s =*s-32;
        }
        s++;
    }
    return s;
}

char* moje_strupr2(char * s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i]>='a' && s[i]<='z'){
            s[i] = s[i]-32;
        }
        i++;
    }
    return s;
}

char* moje_strlwr1(char * s){
    while(*s != '\0'){
        if(*s>='A' && *s<='Z'){
            *s =*s+32;
        }
        s++;
    }
    return s;
}
char* moje_strlwr2(char * s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = s[i]+32;
        }
        i++;
    }
    return s;
}




int main()
{
char x[99];
char a[] = "aaaa";
char b[] = "zzzz";

printf("Wypisz string:  \n");
fgets(x,sizeof(x),stdin); // nie scanf bo ten kończy input m.in po spacji
x[moje_strcspn2(x,"\n")]='\0'; //strcspn znajduje \n i zmieniamy go na \0 zeby strlen zadzialal poprawnie
printf("Słowo \"%s\" ma długość %d znaków\n",x,moje_strlen1(x));

int r = moje_strcmp2(a,b);
printf("cmp: %d\n",r);
printf("Przed kopią: %s, %s\n",a,b);
moje_strcpy2(a,b);
printf("Po kopii: %s, %s\n",a,b);


char f[]="abcde";
    moje_strupr2(f);
    printf("%s\n",f);
    moje_strlwr1(f);
    printf("%s\n",f);

return 0;
}