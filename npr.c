#include <stdio.h>
 
void main()
{
    int n, r, npr_var;
 
    printf("Enter the value of n:");
    scanf("%d", &n);
    printf("\nEnter the value of r:");
    scanf("%d", &r);
    
    npr_var = fact(n) / fact(n - r);
    printf("\nThe value of P(%d,%d) is: %d",n,r,npr_var);
}

int fact(int num)
{
    int k = 1, i;
    if (num == 0)
    {
        return(k);
    }
    else
    {
        for (i = 1; i <= num; i++)
    {
            k = k * i;
	}
    }
    return(k);
}