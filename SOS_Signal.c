#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN 12

void make_line(){
    gpio_put(LED_PIN, 1);
    sleep_ms(800);
    gpio_put(LED_PIN, 0);
}

void make_point(){
    gpio_put(LED_PIN, 1);
    sleep_ms(200);
    gpio_put(LED_PIN, 0);
}

void letter_s(){
    // Essa letra é composta por 3 pontos separados por 0,125s entre si
    // Primeiro ponto
    make_point();
    sleep_ms(125);

    // Segundo ponto
    make_point();
    sleep_ms(125);

    // Terceiro ponto
    make_point();
}

void letter_o(){
    // Essa letra é composta por 3 traços separados por 0,125s entre si
    // Primeiro traço
    make_line();
    sleep_ms(125);

    // Segundo traço
    make_line();
    sleep_ms(125);

    // Terceiro traço
    make_line();
}

int main(){
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        letter_s();     // Letra S
        sleep_ms(250);  // Intervalo das letras (0,25 segundos)
        letter_o();     // Letra O
        sleep_ms(250);  // Intervalo das letras (0,25 segundos)
        letter_s();     // Letra S
        sleep_ms(3000); // Intervalo do ciclo (3 segundos)
    }
}
