#include <cs50.h>
#include <stdio.h>
int main(void)

{ int n;
do
{
  n = get_int("Height:");
}
while (n < 1 || n  > 8);
     int height;



{
    for (int i = 1; i < (n + 1); i++)

{
      for (int j = 1; j < (n + 1); j++)

        if (j <=(n - i))
        {
            printf(" ");
        }
        else
      {
          printf("#");
      }
      printf("\n");
  }

    }
    }



