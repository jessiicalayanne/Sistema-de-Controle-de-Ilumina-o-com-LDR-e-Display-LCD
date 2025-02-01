# Sistema-de-Controle-de-Ilumina-o-com-LDR-e-Display-LCD

## Desenvolva um sistema que monitore a intensidade luminosa do ambiente utilizando um sensor LDR e controle o acionamento de uma lâmpada com base em uma lógica com histerese, exibindo informações detalhadas no display LCD.
 O sensor LDR será utilizado para medir a luminosidade do ambiente. A tensão analógica gerada será lida pelo ADC do microcontrolador.
 
 A lâmpada será acionada pelo acionamento de um relé conforme a lógica de histerese:
 Valor_1: Acima deste valor, a lâmpada será desligada.
 
 Valor_2: Abaixo deste valor, a lâmpada será ligada.
 
A histerese evita o acionamento/desligamento constante da lâmpada em situações de flutuação próxima ao limiar.
[Opcional] Os valores dos limiares podem ser ajustados em tempo real pelo usuário, utilizando botões.

## O display LCD exibirá as seguintes informações:

Valor da luminosidade lido pelo sensor (em unidades ADC).

Estado da lâmpada: "Ligada" ou "Desligada".

Valores dos limiares de acionamento.
## Montagem
