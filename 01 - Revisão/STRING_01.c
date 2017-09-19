#include <stdio.h>

int main (){
	int i, c;

	c = getchar();
	while(c!='0'){
	if (c!=10)
		printf("%c = %d\n", c, c);
	c = getchar();
	}
return 0;
}
