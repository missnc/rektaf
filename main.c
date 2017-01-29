#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct int_array_t {
    int n[2];
} int_array_t;

typedef void (*print_int_array_t)(int_array_t a);
typedef int_array_t (*new_int_array_t)();
typedef int_array_t (*addone_int_array_t)(int_array_t a);

int_array_t new_int_array_f() {
    const int_array_t n = { .n = { 1,2 } };
    return n;
}

int_array_t addone_int_array_f(int_array_t a) {
    const int_array_t n = { .n = { a.n[0] + 1, a.n[1] + 1 } };
    return n;
}

int_array_t arg_int_array_f(int argc, char** argv) {
    if(argc <= 4 && (strcmp(argv[1], "-print") == 0)){
        const int x = atoi(argv[2]);
        const int y = atoi(argv[3]);
        const int_array_t n = { .n = { x,y } };
        return n;
    } else {
        const int_array_t b = { .n = { 0 } };
        return b;
    }
}

void print_int_array_f(int_array_t a){
    const int s = sizeof(a.n) / sizeof(int);
    for (int i = 0; i < s; i++) {
        printf("%d ",a.n[i]);
    }
    printf("\n");
}

print_int_array_t print_int_array = print_int_array_f;
new_int_array_t new_int_array = new_int_array_f;
addone_int_array_t addone_int_array = addone_int_array_f;

int main(int argc, char** argv) {

    print_int_array(addone_int_array(new_int_array()));

}
