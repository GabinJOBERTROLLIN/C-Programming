#include <stdio.h>
int factorielle(int);
int main(){
    int N=5;
    printf("factorielle : %i\n", factorielle(N));
}
int factorielle (int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return (num * factorielle (num-1));
    }
}