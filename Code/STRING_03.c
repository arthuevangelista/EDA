#include <stdio.h>
/* conta linhas na entrada */
int main(){
int c, nl;
nl = 0;
c = getchar();
while (c != EOF) {
if (c == '\n') {
nl = nl+1;
} /* fim-if */
c = getchar();
} /* fim-while */
printf("%d\n", nl);
} /* fim-programa */
