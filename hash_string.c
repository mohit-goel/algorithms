//Calculate hash of a string 
#include<stdio.h>

unsigned long hash( char *str);

int main()
{
    unsigned long int x= 0;

     char arr[] = {'m','o','h','i','t','\0'} ;

    x = hash(arr);
    printf("%ld",x);
    return 0;

    }

long sfold(String s, int M) {
     int intLength = s.length() / 4;
     long sum = 0;
     for (int j = 0; j < intLength; j++) {
       char c[] = s.substring(j * 4, (j * 4) + 4).toCharArray();
       long mult = 1;
       for (int k = 0; k < c.length; k++) {
	 sum += c[k] * mult;
	 mult *= 256;
       }
     }

     char c[] = s.substring(intLength * 4).toCharArray();
     long mult = 1;
     for (int k = 0; k < c.length; k++) {
       sum += c[k] * mult;
       mult *= 256;
     }

     return(Math.abs(sum) % M);
   }
