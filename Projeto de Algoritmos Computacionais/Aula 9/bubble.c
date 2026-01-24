#include <stdio.h>

void bubble(int v[], int qt) {
    for(int ultimo = qt-1; ultimo >= 0; ultimo--) {
        for(int i=0; i<ultimo; i++) {
            if(v[i]>v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}

int main() {
    int v[] = { 40, 70, 10, 50, 30, 60, 20 };
    bubble(v,7);
    for(int i=0; i<7; i++) {
        printf("%d, ",v[i]);
    }
    printf("\n");
    return 0;
}
/*#include <stdio.h>

void bubble(int v[], int qt) {
    for(int ultimo = 0; ultimo <= qt-1; ultimo++) {
        for(int i=0; i< qt - ultimo - 1; i++) {
            if(v[i]>v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}

int main() {
    int v[] = { 40, 70, 10, 50, 30, 60, 20 };
    bubble(v,7);
    for(int i=0; i<7; i++) {
        printf("%d, ",v[i]);
    }
    printf("\n");
}*/