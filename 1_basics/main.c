#include <stdio.h>


int main()
{    
	char str[100];
	int i;
    float x;
    double y;
	
	printf("Enter a values char int float double: ");
	
	scanf("%d %s %f %lf", &i,str,&x, &y);

	printf("\nYou entered: %d::::::%s::::::%f:::::::%lf\n", i, str, x, y);
    
	return 0;
}
