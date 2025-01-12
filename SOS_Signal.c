#include <stdio.h>
#include "pico/stdlib.h"

#define GREEN_PIN 11
#define BLUE_PIN 12
#define RED_PIN 13

int count = 0;
int matrix[3] = {GREEN_PIN, BLUE_PIN, RED_PIN};

void set_pin(int pin_num){
    gpio_init(pin_num);
    gpio_set_dir(pin_num, GPIO_OUT);
}

void make_line(int pin_num){
    gpio_put(pin_num, 1);
    sleep_ms(800);
    gpio_put(pin_num, 0);
}

void make_point(int pin_num){
    gpio_put(pin_num, 1);
    sleep_ms(200);
    gpio_put(pin_num, 0);
}

void letter_s(int pin_num){
    // Essa letra é composta por 3 pontos separados por 0,125s entre si
    // Primeiro ponto
    make_point(pin_num);
    sleep_ms(125);

    // Segundo ponto
    make_point(pin_num);
    sleep_ms(125);

    // Terceiro ponto
    make_point(pin_num);
}

void letter_o(int pin_num){
    // Essa letra é composta por 3 traços separados por 0,125s entre si
    // Primeiro traço
    make_line(pin_num);
    sleep_ms(125);

    // Segundo traço
    make_line(pin_num);
    sleep_ms(125);

    // Terceiro traço
    make_line(pin_num);
}

int main(){
    stdio_init_all();

    set_pin(GREEN_PIN);
    set_pin(BLUE_PIN);
    set_pin(RED_PIN);

    while (true) {
        
        letter_s(matrix[count]);     // Letra S
        sleep_ms(250);               // Intervalo das letras (0,25 segundos)
        letter_o(matrix[count]);     // Letra O
        sleep_ms(250);               // Intervalo das letras (0,25 segundos)
        letter_s(matrix[count]);     // Letra S
        sleep_ms(3000);              // Intervalo do ciclo (3 segundos)

        count += 1;
        if (count == 3){
            count = 0;
        }
    }
}
