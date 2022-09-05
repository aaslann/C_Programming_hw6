#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Compound {
   char price[50];
   char object[50];
   char name[50];
   double count;
};
double calculate(struct Compound s,int c);
int isNumber(char c[50]);
int numberofblank(char c[50]);
void removeBlanks(char * str);
int main() {

    double sum = 0;
    struct Compound s1;
    printf("Name the object: "); 
    scanf("%[^\n]%*c",s1.name);
    printf("%.2lf\n",calculate(s1,0));
    removeBlanks(s1.name);
    return 0;
}
double calculate(struct Compound s,int c){
    double total =0.0;
    char temp[50],temp2[50];
    int counter=0;
    float a;
    int i=0;
    if (c==0)
    {
        printf("Define %s?:\n",s.name);
    }
    else
    {
        printf("Define %s in %s?:\n",s.object,s.name);
        strcpy(s.name,s.object);
    }
    scanf(" %[^\n]%*c",temp);
    strcpy(temp2,temp);
    if (isNumber(temp) == 1)
    {
        return atof(temp);
    }
    else{
        char *token  = strtok(temp," ");
        while(token != NULL)
        {
            if (counter % 2 == 0)
            {
                s.count=atof(token);
            }
            else
            {
                strcpy(s.object,token);
                total += calculate(s,c+1)*s.count;
                if(numberofblank(temp2) <= 3){
                    token = strtok(temp2," ");
                    while(i != counter){
                        token = strtok(NULL," ");
                        i++;
                    }
                }
            }
            token=strtok(NULL," "); 
            counter++;
        }
        return total;
    }
}

int isNumber(char c[50]){
    int i=0;
    while(i<strlen(c)){
        if (c[i]==' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int numberofblank(char c[50]){
    int counter=0;
    int i=0;
    while(i<strlen(c)){
        if(c[i] == ' '){
            counter++;
        }
        i++;
    }
    return counter;
}
void removeBlanks(char * str)
{
    int i, j;
    char temp[100];

    i = 0;
    j = 0;

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            temp[j] = ' ';
            j++;
            while(str[i] == ' ')
                i++;
        }
        temp[j] = str[i];
        i++;
        j++;
    }
    temp[j] = '\0';
    strcpy(str,temp);

}