#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   while(1){
      char str[256];
      fgets(str,256,stdin);
      system(str);
   }
}
