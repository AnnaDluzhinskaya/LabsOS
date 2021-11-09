#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>

int main(){
  	FILE* stream = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
  	struct input_event input_key;
  	char* temp = malloc(128);
  	
  	int arr[20];
  	for (int i=0;i<20;i++){
		arr[i]=0;
	}
	int k = 1;
    while (1) {
     	fread(&input_key, sizeof(struct input_event), 1, stream);
     	if (input_key.type==1){
   	  		if (input_key.value==0){
   	  			printf("\nRELEASED %#x (%d)\n",input_key.code,input_key.code);
   	  			snprintf(temp, 128, "%u",input_key.code);
   	  			for (int i=0;i<k;i++){
					if(arr[i]==atoi(temp)){
  						arr[i]=0;
  						break;
  					}
  				}
  				for (int i=0;i<19;i++){
  				  	if(arr[i]==0){
  				  		arr[i]=arr[i+1];
  				  		arr[i+1]=0;
  				  	}
  				}

  				k--;
   	  		}else if  (input_key.value==1) {
  			 	printf("\nPRESSED %#x (%d)\n",input_key.code,input_key.code);
  			 	snprintf(temp, 128, "%u",input_key.code);
	 			arr[k]=atoi(temp);
	 			k++;
   	  		}
   	  		
  			if (arr[0]==25 && arr[1]==18 && arr[2]==0){
  				printf("I passed the Exam!\n");
  			}
  			if (arr[0]==46 && arr[1]==30 && arr[2]==25 && arr[3]==0){
  				printf("Get some cappuccino!\n");
  			}
  			if (arr[0]==30 && arr[1]==32 && arr[2]==0){
  				printf("Anna Dluzhinskaya!\n");
  			}
     	}
  			
	}
}   
