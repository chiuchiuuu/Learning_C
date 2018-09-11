/* Program demonstrating atof(char s[]).The function which converts the string to a floating 
   point value */
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAXLINE 100

double myatof(char s[]);
int mgetline(char line[],int maxline);

int main(void)
{
    char str[MAXLINE];
    double num;
    mgetline(str,MAXLINE);

    num=myatof(str);
    printf("%f",num);

    return 0;
}

double myatof(char s[])
{
    double val,power;
    int sign,i,esign,exp;   
    int powerer(int base,int exp);    
        
    for(i=0;isspace(s[i]);i++)
        ;

    sign=(s[i]=='-')?-1:1;

    if(s[i]=='+' || s[i] == '-')
        i++;

    for(val=0.0;isdigit(s[i]);i++)
        val = 10.0 * val + (s[i] - '0');
    
    if(s[i]=='.')
        i++;

    for(power=1.0;isdigit(s[i]);i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if(s[i]=='e' || s[i] =='E')
        i++;
    if(s[i]=='+' || s[i] =='-')
    {
        esign=s[i];
        i++;
    }

    for(exp=0;isdigit(s[i]);i++)
        exp=10.0 * exp + (s[i] - '0');
    
    if( esign == '-')
        return sign * (val / power) / pow(10,exp);
    else
    
        return sign * (val / power) * pow(10,exp);
}

int mgetline(char s[],int lim)
{
    int i,c;

    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i] = c;
    
    if(c=='\n')
        s[i++]=c;

    s[i]='\0';
}
    
int powerer(int base,int exp)
{
    int powerer;
    powerer=1;
    while(exp-- > 0)
        powerer *=base;

    return powerer;
}