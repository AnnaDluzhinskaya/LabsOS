#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
	DIR* dir = opendir("/");
	struct dirent* temp;
	int count = 1;
	while ((temp = readdir(dir)) != NULL) {
		printf("%d) %s\n",count, temp->d_name);
		count++;
	}
}
