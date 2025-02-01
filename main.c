// link wokwi: https://wokwi.com/projects/421686218869483521

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// Definições da UART
#define UART_ID uart1
#define BAUD_RATE 115200

// Pinos da UART
#define UART_TX_PIN 4
#define UART_RX_PIN 5

// Definição dos LEDs do semáforo
#define LED_RED 13    // Vermelho
#define LED_BLUE 12   // Azul
#define LED_GREEN 11  // Verde

volatile int estado = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar o estado
    gpio_put(LED_RED, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);

    // Alterna o estado do semáforo
    switch (estado) {
        case 0: // Vermelho ligado
            gpio_put(LED_RED, 1);
            printf("Semáforo Vermelho Ligado\n");
            estado = 1;
            break;
        case 1: // Azul ligado
            gpio_put(LED_BLUE, 1);
            printf("Semáforo Azul Ligado\n");
            estado = 2;
            break;
        case 2: // Verde ligado
            gpio_put(LED_GREEN, 1);
            printf("Semáforo Verde Ligado\n");
            estado = 0;
            break;
    }
    return true; // Continua repetindo o ciclo
}

int main() {
    stdio_init_all();

    // Configuração da UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    uart_puts(UART_ID, "Iniciando sistema de semáforo\n");

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Configura um timer para alternar os LEDs a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(-3000, repeating_timer_callback, NULL, &timer);

    // Loop principal que imprime informações a cada 1 segundo
    while (true) {
        printf("Passou 1 segundo\n");
        sleep_ms(1000);
    }
}
