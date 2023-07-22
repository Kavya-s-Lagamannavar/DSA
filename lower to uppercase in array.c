#include<stdio.h>
void input(char arr[][10], int size);
void upper(char arr[][10], int size);
void findIntValue(char arr[][10], int size);

int main(void)
{
  char arr[SIZE][10] = {0.0};

  input(arr, SIZE);

  upper(arr, SIZE);

  findIntValue(arr, SIZE);

  return 0;
}

 void input(char arr[][10], int size)
{
  int i, j;

  for(i = 0 ; i < size ; i++)
 {
    printf("\nEnter the name: ");
    scanf(" %s", arr[i]);
 }
}

void upper(char arr[][10], int size)
{
  int i, j;

  for(i = 0 ; i < size && arr[i] != '\0' ; i++)
 {
    for(j = 0 ; j < 10 && arr[i][j] != '\0' ; j++)
    {
        if(arr[i][j] >= 97 && arr[i][j] <= 122)
        {
            arr[i][j] -= 32;
        }
    }
 }

 for(i = 0; i < size && arr[i] != '\0' ; i++)
 {
    for(j = 0 ; j < 10 && arr[i][j] != '\0' ; j++)
    {
        printf("\n%s\n", arr);
    }
 }
}

void findIntValue(char arr[][10], int size)
{
  int i, j;
  int total = 0;

  for(i = 0 ; i < size && arr[i] != '\0' ; i++)
 {
    for(j = 0 ; j < 10 && arr[i][j] != '\0' ; j++)
    {
        total += arr[i][j];

        printf("\n%s\t%d\n", arr, total);

        total = 0;
    }
  }
}
