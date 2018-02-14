#include<stdio.h>
#include<stdlib.h>

void main(){
FILE *fptr;
char filename[6], ch;
char **double_arr = (char**) malloc(sizeof(char*)*5);
printf("enter the filename to be opened \n");
scanf("%s", filename);
fptr = fopen(filename, "r");
if(fptr == NULL)
{
	printf("cannot open file\n");
	return;
}
double_arr[0] = (char*) malloc(sizeof(char)*16*10);
double_arr[1] = (char*) malloc(sizeof(char)*5*10);
double_arr[2] = (char*) malloc(sizeof(char)*5*10);
double_arr[3] = (char*) malloc(sizeof(char)*5*10);
double_arr[4] = (char*) malloc(sizeof(char)*5*10);

int i=0;
int j=0;
ch = fgetc(fptr);
	i = -1;	
	while(ch != '\n')
		{
		j = 0;
		while(ch !=','&& ch !='\"')
			{	
				printf("%c\n",ch);
				double_arr[i][j] = ch;
				ch = fgetc(fptr);
				j++;
			}
		i++;
		ch = fgetc(fptr);
		printf("enter the filename to be opened %c \n",ch);
		scanf("%s", filename);
		}


printf("%s", double_arr[0]);
fclose(fptr);

}
