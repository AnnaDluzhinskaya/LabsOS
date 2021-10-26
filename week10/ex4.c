#include<stdio.h>
#include <stdlib.h>
#include<dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

  DIR *dr = opendir("./tmp/"); 
  
  struct dirent* de;

  while ((de = readdir(dr)) != NULL){ 
    DIR *temp = opendir("./tmp/");
    struct dirent* temp_de;
    int c = 0;
    char **s = malloc(10*sizeof(char*));
      
    while ((temp_de = readdir(temp)) != NULL){
      if (temp_de->d_ino==de->d_ino){
        s[c] = temp_de->d_name;
        c++;
      }
    }  
    closedir(temp); 

    if (c > 1) {
      printf("%s - ", de->d_name);
      for (int i = 0; i < c-1; i++) {
        printf("%s, ", s[i]);
      }
      printf("%s\n", s[c-1]);
    }
  }  
  closedir(dr);     	

	return 0;
}
