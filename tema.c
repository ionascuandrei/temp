#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[]) {
	int nr_max_carduri;
	FILE *input,*output;
	input=fopen(argv[1],"r");
	if(input==NULL){
		exit(1);
	}
	fscanf(input,"%d",&nr_max_carduri);
	int count;
	LSC *p=NULL;
	POZ *pozitia_curenta=NULL;
	while(count!=nr_max_carduri){
		char *line;
		line=(char)malloc(sizeof(char));
		fgets(line,200,input);
		printf("%s",line); 
		char *actiune;
		actiune=strtok(line," ");
		if(actiune=='add_card'){
			double nr_card;
			fscanf(input,"%f",&nr_card);
			printf("%d",nr_card);
			int pinul[4],i;
			for(i=0;i<4;i++){
				fscanf(input,"%d",&pinul[i]);
				printf("%d",pinul[i]);
			}
		}
	}	
	return 0;
}