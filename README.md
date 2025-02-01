# Semáforo com Temporizador Periódico

Este projeto foi desenvolvido utilizando o **microcontrolador Raspberry Pi Pico W** e a ferramenta educacional **BitDogLab** com base em projeto proposto pelo EmbarcaTech, 
com o objetivo de simular o funcionamento de um semáforo.
A temporização de 3 segundos para cada alteração de sinal foi implementada utilizando a função **`add_repeating_timer_ms()`** do **Pico SDK**.

## 📝 Enunciado do Projeto

O objetivo é criar um sistema de semáforo que alterne entre três sinais (vermelho, azul e verde) a cada 3 segundos, conforme o fluxograma de atuação do semáforo.

### 🔧 Componentes Utilizados
- **Microcontrolador Raspberry Pi Pico W**.
- **LED Vermelho**: Conectado à GPIO 13.
- **LED Azul**: Conectado à GPIO 12.
- **LED Verde**: Conectado à GPIO 11.
- **Resistores de 330 Ω**.

---
**Link Wokwi:**
<https://wokwi.com/projects/421686218869483521>

## 🎯 Funcionalidades do Projeto

1. **Acionamento dos LEDs**  
   O semáforo inicia com o LED vermelho aceso, alternando para o LED azul, e depois para o verde, repetindo o ciclo a cada 3 segundos.

2. **Temporização do Semáforo**  
   A mudança de estado dos LEDs ocorre através de um temporizador periódico configurado com 3 segundos de intervalo.

3. **Impressão de Mensagens**  
   A cada 1 segundo, uma mensagem é enviada para a porta serial, indicando que o sistema está em execução.

4. **Uso de Interrupções**  
   O controle dos LEDs é realizado por uma função de call-back do temporizador, garantindo a alternância automática de sinais.

---

## 📂 Organização do Código

### Arquivos Incluídos
- **`main.c`**: Código principal com a implementação do temporizador, controle de LEDs e mensagens na UART.

---

## 📋 Requisitos do Projeto

1. **Temporizador Periódico**  
   O temporizador é configurado para alternar os LEDs a cada 3 segundos, com controle realizado por meio da função `repeating_timer_callback()`.

2. **Impressão a cada 1 segundo**  
   O loop principal imprime uma mensagem a cada segundo para monitoramento.

3. **Configuração de UART**  
   O projeto utiliza a UART para enviar mensagens de status à porta serial.

4. **Estrutura do Código:**
   - **Inicialização dos componentes**: LEDs e UART.
   - **Função de Call-back**: Alterna os LEDs de acordo com o estado.
   - **Loop principal**: Controla a impressão das mensagens na UART.

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
- **Microcontrolador Raspberry Pi Pico W**.
- Ambiente de desenvolvimento configurado com **Pico SDK**.

### Passos
1. Clone este repositório:
   ```bash
   git clone <https://github.com/queirozPatrick/temp_periodico>
   ```

2. Compile e carregue o código no Raspberry Pi Pico W.

3. Conecte os LEDs nas GPIOs correspondentes (13, 12 e 11) e o monitor serial.

4. Execute o código e observe o semáforo alternando a cada 3 segundos, com mensagens sendo impressas a cada segundo.

---
