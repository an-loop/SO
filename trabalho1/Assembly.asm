section .data
    prompt db "Digite um número inteiro: ", 0
    even_msg db "é par.", 10, 0
    odd_msg db "é ímpar.", 10, 0

section .bss
    num resd 1
    char_in resb 1

section .text
    global _start

_start:
    ; Escreve a mensagem de prompt na tela
    mov eax, 4 ; sys_write
    mov ebx, 1 ; stdout
    mov ecx, prompt ; endereço da string
    mov edx, 27 ; tamanho da string
    int 0x80 ; chama a syscall
read_num:
    ; Lê um caractere do teclado
    mov eax, 3; sys_read
    mov ebx, 0; stdin
    mov ecx, char_in
    mov edx, 1
    int 0x80; chama a syscall

    ; Verifica se o caractere é uma quebra de linha
    cmp byte [char_in], 10
    je paridade; pula para paridade

    ; Converte o caractere ASCII para número
    sub byte [char_in], '0'

    ; Atualiza num (num = num*10 + char_in)
    mov eax, [num]
    imul eax, eax, 10
    add eax, [char_in]
    mov [num], eax

    jmp read_num
paridade:
    ; Lê o número digitado pelo usuário
    mov eax, 3 ; sys_read
    mov ebx, 0 ; stdin
    mov ecx, num ; endereço do buffer de leitura
    mov edx, 4 ; tamanho do buffer de leitura (4 bytes para um inteiro)
    int 0x80 ; chama a syscall

    ; Verifica se o número é par ou ímpar e escreve o resultado na tela
    mov eax, [num]
    and eax, 1 ; verifica o bit menos significativo (1 para ímpar, 0 para par)
    jz even ; se for zero (par), pula para a label "even"
    
odd:
    ; Escreve a mensagem "ímpar" na tela
    mov eax, 4 ; sys_write
    mov ebx, 1 ; stdout
    mov ecx, odd_msg ; endereço da string "ímpar"
    mov edx, 12 ; tamanho da string "ímpar"
    int 0x80 ; chama a syscall
    
exit:
    ; Sai do programa
    mov eax, 1 ; sys_exit
    xor ebx, ebx ; código de saída (zero indica sucesso)
    int 0x80 ; chama a syscall

even:
    ; Escreve a mensagem "par" na tela
    mov eax, 4 ; sys_write
    mov ebx, 1 ; stdout
    mov ecx, even_msg; endereço da string "par"
    mov edx, 9; tamanho da string "par"
    int 0x80 ; chama a syscall

jmp exit