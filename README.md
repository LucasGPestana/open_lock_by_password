# Open Lock by Password

Código que implementa a lógica de destrancar um cadeado a partir de uma senha de 4 dígitos, a qual é comparada com uma senha inteira não sinalizada de 32 bits decodificada em um registro de campo de bits dos dados do cadeado (Data Padlock).

## Como funciona

Um valor inteiro não sinalizado de 32 bits é armazenado em uma constante. Cada conjunto de bits desse valor na base binária é extraído e associado a um dado do cadeado.

O cadeado possui os seguintes dados:

- Ordem do primeiro número (2 bits, posições 1 e 2)
- Ordem do segundo número (2 bits, posições 3 e 4)
- Ordem do terceiro número (2 bits, posições 5 e 6)
- Ordem do quarto número (2 bits, posições 7 e 8)
- Primeiro número (4 bits, posições 9 a 12)
- Segundo número (4 bits, posições 13 a 16)
- Terceiro número (4 bits, posições 17 a 20)
- Quarto número (4 bits, posições 21 a 24)
- Estado "Aberto" (1 bit, sendo '0' equivalente a "não" e '1' a "sim")

As ordens determinam a sequência dos números extraídos da senha a qual a senha de 4 dígitos informada na entrada deve ser equivalente.

Exemplificando, se a senha armazenada for 15976339, os dados do cadeado serão:

- Ordem do primeiro número = 2
- Ordem do segundo número = 1
- Ordem do terceiro número = 0
- Ordem do quarto número = 3
- Primeiro número = 15
- Segundo número = 3
- Terceiro número = 12
- Quarto número = 7
- Estado "Aberto" = 0

Isso significa que, apesar dos dados sugerirem uma sequência de números 15, 3, 12, 7 necessária para destrancar o cadeado, na verdade a sequência válida seria 12, 3, 15, 7.

Ao informar os 4 dígitos da senha como entrada, caso os números e as ordens de cada número sejam equivalentes aos da senha armazenada, o estado "Aberto" do cadeado será '1', ou seja, ela estará aberta.

## Estrutura do Projeto

[main.c](./main.c) - Arquivo com a função principal do programa que recebe os dígitos da senha como entrada e informa o estado do cadeado como saída (Aberta ou Fechada)
[padlock.h](./padlock.h) - Arquivo de interface com a declaração do registro de campo de bits dos dados do cadeado (Data Padlock) e os protótipos das sub-rotinas relacionadas a esse registro
[padlock.c](./padlock.c) - Arquivo de implementação das sub-rotinas associadas ao registro do campo de bits dos dados do cadeado (Data Padlock)

## Requisitos do Projeto

- Criação de um registro para controle do cadeado como um campo de bits (`struct dataPadlock` em [padlock.h](./padlock.h))
- Criação de registros de auxílio para decodificação da senha (União `passwordDecoder` com membros `unsigned int password` e `struct dataPadlock dLockDecoded`, localizado na sub-rotina `extractDataPadlockFromPassword` em [padlock.c](./padlock.c))
- Implementação com sub-rotinas (Protótipos declarados em [padlock.h](./padlock.h) e implementados em [padlock.c](./padlock.c))

## Restrições

- Todos os 4 digítos da senha informada como entrada devem ser positivos (maiores ou iguais a '0')
- As ordens extraídas da senha armazenada não podem ser repetidas

## Compilação

GCC: `gcc main.c padlock.c -o nome_binario`
