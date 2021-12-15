#include<stdio.h>

struct Structure {
    int integer;
    float decimal;
    char name[20];
};

union Union{
    int integer;
    float decimal;
    char name[20];
};

int main(void) {

    struct Structure s = {12, 67.9, "Panama"};
    union Union u = {12, 67.9, "Panama"};

    /*Accessing all variables at the same time */
    printf("\n\n -----Structure contents: \n Integer value: %d \n Decimal value: %f \n String value: %s \n", s.integer, s.decimal, s.name);
    printf("\n\n -----Union contents: \n Integer value: %d \n Decimal value: %f \n String value: %s \n", u.integer, u.decimal, u.name);

    /*Sizes of structure and union */
    printf("\n\n Size of Structure: %d", sizeof(s));
    printf("\n\n Size of Union: %d", sizeof(u));

    /*Changes in the values*/
    s.integer = 23;
    s.decimal = 82.76;
    printf("\n\n -----Altered Structure contents: \n Integer value: %d \n Decimal value: %f \n String value: %s \n", s.integer, s.decimal, s.name);
    u.integer = 39;
    u.decimal = 45.11;
    printf("\n\n -----Altered Union contents: \n Integer value: %d \n Decimal value: %f \n String value: %s \n", u.integer, u.decimal, u.name);

    return 0;
}
