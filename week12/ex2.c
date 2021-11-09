#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>

int main(){
  FILE* stream = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
  struct input_event input_key;
  int ind = 0;
  char line[256];
  while (1) {
  	fread(&input_key, sizeof(struct input_event), 1, stream);
  	if (input_key.type==1){
  		if (input_key.value==0){
  			 printf("\nRELEASED %#x (%d)\n",input_key.code,input_key.code);
  		}else if  (input_key.value==1) {
  			 printf("\nPRESSED %#x (%d)\n",input_key.code,input_key.code);
  		}
  	}
  }    
}