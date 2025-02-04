#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

//definição dos pinos correspondentes a placa BitDogLab
#define LED_VERMELHO 13
#define LED_AMARELO 12          //Pino correponde a cor azul que será utilizado para representa a cor amarelo na atividade atual
#define LED_VERDE 11

//vetor para organizar a sequência de cores de um semáforo real
const uint8_t semaforo[] = {LED_VERMELHO, LED_AMARELO, LED_VERDE};
int indice = 0;

// Função para alternar o estados dos LEDs
void ligarLed(){
    for (int i = 0; i < 3; i++){
        if (i == indice){
            gpio_put(semaforo[i], true);
        }else{
            gpio_put(semaforo[i], false);
        }
    }
}

// Função de call-back do temporizador, utilizada para realizar a alteração em um tempo determinado
bool repeating_timer_callback(struct repeating_timer *t){
    ligarLed();
    
    indice = ++indice > 2 ? 0 : indice; 
    return true;
}

// Inicialização e configuração dos pinos utilizados para pinos de saída
void inicializacao_pinos(){
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_put(LED_VERMELHO, true);

    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
}

int main(){
    stdio_init_all();
    inicializacao_pinos();

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);   // Irá chamar a função de call-back a cada 3 segundos

    while (true) {
        sleep_ms(1000);
        printf("Novo ciclo\n");
    }
}