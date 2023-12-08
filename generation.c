#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)

{
    int age = get_int ("How old are you?:");
printf("Age:%i \n", age);


if ( age < 21)
{
printf("You are Generation Z\n");
}
else
{printf("Millenial age\n");
}
if ( age >60)
{
    printf("Baby-Boomer!\n");
}
}