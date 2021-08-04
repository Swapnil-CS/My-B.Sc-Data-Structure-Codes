#include<stdio.h>
#include<limits.h>


int main()
{
    
        printf("Size of signed char is %u bytes\n",sizeof(signed char));
        printf("Maximum Value of signed char is %d\n",SCHAR_MAX);
        printf("Minimum Value of signed char is %d\n\n",SCHAR_MIN);
    


        printf("Size of unsigned char is %u bytes\n",sizeof(unsigned char));
        printf("Maximum Value of unsigned char is %d\n\n",UCHAR_MAX);
    


        printf("Size of char is %u bytes\n",sizeof(char));
        printf("Maximum Value of char is %d\n",CHAR_MAX);
        printf("Minimum Value of char is %d\n\n",CHAR_MIN);
    


        printf("Size of short int is %u bytes\n",sizeof(short int));
        printf("Maximum Value of short int is %d\n",SHRT_MAX);
        printf("Minimum Value of short int is %d\n\n",SHRT_MIN);
    


        printf("Size of unsigned short int is %u bytes\n",sizeof(unsigned short int));
        printf("Maximum Value of unsigned short int is %d\n\n",USHRT_MAX);
    


        printf("Size of int is %u bytes\n",sizeof(int));
        printf("Maximum Value of int is %d\n",INT_MAX);
        printf("Minimum Value of int is %d\n\n",INT_MIN);
    


        printf("Size of unsigned int is %u bytes\n",sizeof(unsigned int));
        printf("Maximum Value of unsigned int is %lld\n\n",UINT_MAX);


        printf("Size of long int is %u bytes\n",sizeof(long int));
        printf("Maximum Value of long int is %lld\n",LONG_MAX);
        printf("Minimum Value of long int is %lld\n\n",LONG_MIN);
    


        printf("Size of unsigned long int is %u bytes\n",sizeof(unsigned long int));
        printf("Maximum Value of unsigned long int is %lld\n\n",ULONG_MAX);
    


        printf("Size of long long int is %u bytes\n",sizeof(long long int));
        printf("Maximum Value of long long int is %lld\n",LLONG_MAX);
        printf("Minimum Value of long long int is %lld\n\n",LLONG_MIN);

        printf("Size of unsigned long long int is %u bytes\n",sizeof(unsigned long long int));
        printf("Maximum Value of unsigned long long int is %llu\n\n",ULLONG_MAX);
    


     
     return 0;
}
