#include <stdlib.h>
#include <stdio.h>

int main() {
        int i;
        char * str = malloc (100 * sizeof(char));

        for (i=0; i<2500; i++) {
                sprintf(str, "echo '%i' | ./getflag >> tmp", i);
                system(str);
        }
        system("cat tmp");
}
