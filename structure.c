#include <stdio.h>

typedef struct FRUITS{
    int apple;
    int grape;
    int melon;
}fruits;

typedef struct COUNTRY{
    int america;
    int japan;
    int korean;
    int chinese;
    fruits example;
}country;

int main(void)
{
    fruits Fruits;
    Fruits.apple = 10;
    country Country;
    Country.example.apple = 20;
    printf("%d",Country.example.apple);

    return 0;
}