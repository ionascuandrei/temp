#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
LSC *add_card(LSC *lsc_head,long int nr_card,char *pinul,char *data_exp,char *pass,int count){
	LSC *node;
	node=(LSC*)malloc(sizeof(LSC));
	node->card_number=nr_card;
	node->pin=(char*)malloc(strlen(pinul)*sizeof(char));
	strcpy(node->pin,pinul);
	node->expiry=(char*)malloc(strlen(data_exp)*sizeof(char));
	strcpy(node->expiry,data_exp);
	node->cvv=(char*)malloc(strlen(pass)*sizeof(char));
	strcpy(node->cvv,pass);
	node->balance=0;
	strcpy(node->status,"NEW");
	if(count==1){
		node->next=NULL;
	}
	else lsc_head->next=node;
	lsc_head=node;
	return lsc_head;
}
void show(LSC *lsc_head,long int nr_card,FILE *output){
	LSC *p;
	for(p=lsc_head;p!=NULL;p=p->next){
		if(nr_card==lsc_head->card_number){
			fprintf(output,"(card number: %ld, PIN: %s, expiry date: %s, CVV: %s, balance: %d, status: %s, history: [])\n",p->card_number,p->pin,p->expiry,p->cvv,p->balance,p->status);
		}
	}
}
int main(int argc, char **argv) {
	int nr_max_carduri;
	FILE *input,*output;
	input=fopen(argv[1],"r");
	if(input==NULL){
		exit(1);
	}
	output=fopen("output.out","w");
	fscanf(input,"%d",&nr_max_carduri);
	//printf("%d",nr_max_carduri);
	int count=0;
	LSC *lsc_head;
	POZ *poz_poz;
	char line[50];
	while(count!=nr_max_carduri && fgets(line,sizeof(line),input)!=NULL){
		//printf("%s",line);
		char *actiune;
		actiune=strtok(line," ");
		if(strcmp(actiune,"add_card")==0 && count==0){
			long int nr_card;
			actiune=strtok(NULL," ");
			nr_card=atol(actiune);
			//printf("nr_card : %ld\n",nr_card);
			char *pinul;
			actiune=strtok(NULL," ");	
			pinul=actiune;
			//printf("pinul: %s\n",pinul);
			char *data_exp;
			actiune=strtok(NULL," ");
			data_exp=actiune;
			//printf("data_exp: %s\n",data_exp );
			char *pass;
			actiune=strtok(NULL,"\n");
			pass=actiune;
			//printf("pass: %s\n",pass);
			count++;
			lsc_head=add_card(lsc_head,nr_card,pinul,data_exp,pass,count);
			/*LSC *p;
			int i;
			for(i=0,p=lsc_head;i<count,p!=NULL;i++,p=p->next){
				printf("Cardul %d: \n",i+1);
				printf("Number: %ld \n",p->card_number);
				printf("PIN: %s\n",p->pin);
				printf("EXPIRY: %s\n",p->expiry);
				printf("CVV: %s\n",p->cvv);
				printf("BALANCE: %d\n",p->balance);
				printf("STATUS: %s\n",p->status);
			}*/
			int sum=0,pozitie;
			while(nr_card!=0){
				sum=sum+nr_card%10;
				nr_card=nr_card/10;
			}
			pozitie=sum%nr_max_carduri;
			//printf("pozitie %d\n",pozitie);
		}
		if(strcmp(actiune,"show")==0){
			long int nr_card;
			actiune=strtok(NULL,"\n");
			nr_card=atol(actiune);
			//printf("%ld\n",nr_card );
			show(lsc_head,nr_card,output);
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}
