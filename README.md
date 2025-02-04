# 🚦 Projeto: Semáforo com Temporizador Periódico

Este projeto implementa um semáforo utilizando o **Raspberry Pi Pico W**, controlando três LEDs (vermelho, amarelo e verde) com um temporizador periódico. A troca de estados ocorre a cada **3 segundos** usando a função `add_repeating_timer_ms()` do **Pico SDK**.

## 📌 Objetivos
- Simular um semáforo usando **LEDs e temporização**.
- Utilizar **interrupções por temporizador** para controle do sistema.
- Demonstrar o funcionamento através da ferramenta educacional **BitDogLab**.

## 🛠 Componentes Utilizados
- 🖥 **Microcontrolador:** Raspberry Pi Pico W
- 🔴 **LEDs:** Vermelho, Amarelo e Verde
- ⚡ **Resistores:** 3x 330 Ω  
- 🛠 **Ferramentas:** Pico SDK, Wokwi, BitDogLab

## 📜 Funcionamento
1. O **LED vermelho** acende primeiro.
2. Após **3 segundos**, acende o **LED amarelo**.
3. Após **mais 3 segundos**, acende o **LED verde**.
4. O ciclo **recomeça do início** automaticamente.
5. O **LED RGB** (GPIOs 11, 12 e 13) também pode ser utilizado na simulação com o BitDogLab.
6. O terminal exibe mensagens informativas **a cada 1 segundo**.

## 🔧 Configuração e Execução
1. Conecte os LEDs aos **GPIOs do Raspberry Pi Pico W** conforme a tabela:
   | LED   | GPIO |
   |-------|------|
   | 🔴 Vermelho | 13 |
   | 🟡 Amarelo  | 12 |
   | 🟢 Verde    | 11 |

2. Compile e carregue o código no Raspberry Pi Pico W.
3. Abra o monitor serial para visualizar as mensagens de status.
4. Observe a **troca automática de estados do semáforo**.

## 📌 Requisitos
- Raspberry Pi Pico W  
- Pico SDK instalado  
- Ambiente de desenvolvimento configurado  