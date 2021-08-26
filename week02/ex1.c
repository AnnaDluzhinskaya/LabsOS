#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int temp1 = INT_MAX;
    float temp2 = FLT_MAX;
    double temp3 = DBL_MAX;

    printf("Integer:\n");
    printf("Size: %lu\n",sizeof(temp1));
    printf("Value: %d\n",temp1);
    printf("\n");

    printf("Float:\n");
    printf("Size: %lu\n",sizeof(temp2));
    printf("Value: %f\n",temp2);
    printf("\n");

    printf("Double:\n");
    printf("Size: %lu\n",sizeof(temp3));
    printf("Value: %lf\n",temp3);
    
    return 0;
}
