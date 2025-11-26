#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>


void overflow()
{
	char pass[8];
	int auth = 0;
	printf("enter a pasword:\n");
	ssize_t = n read(0,pass, 200);
	if(n>0 && strcmp(pass, "hello")==0)
	{
		auth = 1;
	}

	if(auth)
	{
		printf("access granted");
	}
	else{
		printf("no access\n");
	}
}

int main(){
	overflow();
	return 0;
}