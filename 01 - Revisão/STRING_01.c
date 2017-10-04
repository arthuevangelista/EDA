#include <stdio.h>

int lerString (){
	int i, c;

	c = getchar();
	while(c!='\0'){
	if (c!='\0')
		printf("%c = %d\n", c, c);
	c = getchar();
	}
return 0;
}
