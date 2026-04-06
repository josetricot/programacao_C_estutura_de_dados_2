/*Escreva uma função recursiva que determine quantas vezes um CARATERE X ocorre em um STRING Y. 
 
 Por exemplo, o caractere A ocorre 3 vezes em "abacate".

Faça a representação Gráfica das chamadas recursivas.*/

#include <stdio.h>

int contarCaractere(char *str, char caractere) {
    // caso base: se chegou ao fim da string (caractere nulo)
    if (*str == '\0') {
        return 0;
    }
    
    // caso recursivo: verifica o caractere atual e soma com o resto da string
	if (*str == caractere) {
        return 1 + contarCaractere(str + 1, caractere);
    } else {
        return 0 + contarCaractere(str + 1, caractere);
    }
}

int main() {
    char texto[] = "abacate";
    char caractere = 'a';
    int resultado;
    
    resultado = contarCaractere(texto, caractere);
    
    printf("String: %s\n", texto);
    printf("Caractere: %c\n", caractere);
    printf("O caractere '%c' ocorre %d vezes na string.\n", caractere, resultado);
    
    return 0;
}
