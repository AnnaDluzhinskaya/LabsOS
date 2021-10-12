# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int main () {
  for(int i = 0; i < 100; i++){
    int* a = malloc(1024*1024*1024);
    memset(a, 0, 1024*1024*1024);
    sleep(1);
  }
}
