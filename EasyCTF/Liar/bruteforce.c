#include <stdlib.h>
#include <stdio.h>

int main() {
        int i;
        char * str = malloc (100 * sizeof(char));

        for (i=0; i<2500; i++) {
                sprintf(str, "echo '%i' | ./d692f7a8a8626a021ff89ce1227c9d51c7c59184d3934c1a73f3a0a84043588f_getflag >> tmp", i);
                system(str);
        }
        system("cat tmp");
}
