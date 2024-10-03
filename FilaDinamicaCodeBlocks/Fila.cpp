#include "Fila.h"
#include <stdlib.h>  // Substituir <cstdlib> por <stdlib.h> dependendo do ambiente

// Construtor: Inicializa a fila vazia
Fila::Fila() {
    frente = nullptr;
    tras = nullptr;
    contador = 0;
}

// Destrutor: Libera a memória alocada pela fila
Fila::~Fila() {
    TipoCelula* aux;
    while (frente != nullptr) {
        aux = frente;
        frente = frente->prox;
        delete aux;
    }
    tras = nullptr;
}

// Verifica se a fila está vazia
bool Fila::FilaVazia() {
    return (frente == nullptr);
}

// Insere um novo elemento na fila
bool Fila::Enfileirar(TipoDado dado) {
    TipoCelula* nova = new TipoCelula;
    if (nova == nullptr) return false;  // Falha na alocação de memória

    nova->item = dado;
    nova->prox = nullptr;

    if (FilaVazia()) {
        frente = nova;  // Primeira inserção
    } else {
        tras->prox = nova;  // Liga o último elemento da fila ao novo
    }

    tras = nova;  // Atualiza o ponteiro tras
    contador++;
    return true;
}

// Remove um elemento da fila
bool Fila::Desenfileirar(TipoDado& dado) {
    if (FilaVazia()) return false;  // Fila vazia

    TipoCelula* aux = frente;
    dado = frente->item;  // Retorna o dado do primeiro elemento
    frente = frente->prox;

    if (frente == nullptr) tras = nullptr;  // Caso a fila tenha ficado vazia

    delete aux;
    contador--;
    return true;
}

// Retorna o tamanho da fila
int Fila::TamanhoFila() {
    return contador;
}
