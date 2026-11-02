#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float area_triangle(float a, float b, float c) {
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void draw_triangle(int a, int b, char symbol) {
 
    for (int i = 0; i < a; i++) {
        int width = b - (i * b) / a;
        for (int j = 0; j < width; j++) {
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    char symbol;
    float R;

    printf("Введите символ для рисования:\n");
    scanf(" %c", &symbol);

    printf("Введите радиус:\n");
    scanf(" %f", &R);

   
    if (R < 2.0f) {
        printf("R < 2 невалиден для отрисовки полностью, значение по-умолчанию: 6\n");
        R = 6.0f;
    }

    float b_f = R; 
    float a_f = R * sqrt(3.0); 
    float c_f = 2 * b_f;
    int b = (int)roundf(b_f);
    int a = (int)roundf(a_f);
    int c = (int)roundf(c_f);

    printf("Выбирите операцию\n");
    printf("1 - рассчитать площадь\n");
    printf("2 - вывести определение фигуры\n");
    printf("3 - нарисовать фигуру\n");
    char operation;
    scanf(" %c", &operation);

    switch (operation) {
    case '1':
        printf("Площадь фигуры: %f\n", area_triangle(a_f, b_f, c_f));
        break;
    case '2':
        printf("Три точки соединёные между собой не лежащие на одной прямой\n"); //????
        break;
    case '3':
        draw_triangle(a, b, symbol);
        break;
    default:
        printf("Неподдерживаемое значение\n");
        return 1;
    }

    return 0;
}