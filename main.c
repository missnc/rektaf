#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct int_array_t {
   int n[2];
} int_array_t;

typedef int_array_t (*arg_int_array_fp_t)(int argc, char** argv);
typedef void (*print_int_array_fp_t)(int_array_t a);
typedef int_array_t (*new_int_array_fp_t)();
typedef void (*print_int_array_f_fp_t)(new_int_array_fp_t a);

int_array_t arg_int_array(int argc, char** argv) {
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

void print_int_array(int_array_t a) {
    const int s = sizeof(a.n) / sizeof(int);
    for (int i = 0; i < s; i++) {
        printf("%d ",a.n[i]);
    }
    printf("\n");
}

int_array_t new_int_array() {
    const int_array_t n = { .n = { 1,2 } };
    return n;
}

void print_int_array_f(new_int_array_fp_t a){
    const int_array_t b = a();
    const int s = sizeof(b.n) / sizeof(int);
    for (int i = 0; i < s; i++) {
        printf("%d ",b.n[i]);
    }
    printf("\n");
}

arg_int_array_fp_t arg_int_array_fp = arg_int_array;
print_int_array_fp_t print_int_array_fp = print_int_array;
new_int_array_fp_t new_int_array_fp = new_int_array;
print_int_array_f_fp_t print_int_array_f_fp = print_int_array_f;

int main(int argc, char** argv) {

    print_int_array_f(new_int_array_fp);

}
