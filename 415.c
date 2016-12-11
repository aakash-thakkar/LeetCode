#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) ( (a) >= (b) ? (a) : (b) )

int main()
{
	char *num1 = "500";
	char *num2 = "650";
	printf("Num1: %s and length: %lu\n", num1, strlen(num1));
	printf("Num2: %s and length: %lu\n", num2, strlen(num2));
	char *result = malloc(sizeof(char) * MAX(strlen(num1),strlen(num2))+1);
	int carry = 0;
	for(int i = (MAX(strlen(num1), strlen(num2))-1); i >= 0; i--)
	{
		int a,b,sum;
		i < strlen(num1) ? (a = (int)*(num1+i) - 48) : (a = 0);
		i < strlen(num2) ? (b = (int)*(num2+i) - 48) : (b = 0);
		
		sum = a + b + carry;
		if(sum > 9)
		{ 
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		*(result+(i)+1) = sum + 48;
	}
	*(result) = carry + 48;
	printf("RESULT: %s\n", result);
	return 0;
}
