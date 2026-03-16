#include <stdio.h>

// Protótipo da função
void func(int n);

int main() {
    func(5); // Exemplo de chamada
    return 0;
}

void func(int n) {
    if (n == 0) // CASO BASE
        printf("fim");
    else {
        printf("%d ", n); // Adicionei espaço para melhor visualização
        func(n - 1); // PASSO RECURSIVO
    }
}
