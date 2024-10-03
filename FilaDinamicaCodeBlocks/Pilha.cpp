#include "Pilha.h"
#include <cstdlib>

// Construtor: Inicializa a pilha vazia
Pilha::Pilha() {
    topo = nullptr;
}

// Destrutor: Libera a memória alocada pela pilha
Pilha::~Pilha() {
    CelulaPilha* aux;
    while (topo != nullptr) {
        aux = topo;
        topo = topo->prox;
        delete aux;
    }
}

// Verifica se a pilha está vazia
bool Pilha::PilhaVazia() {
    return (topo == nullptr);
}

// Insere um novo elemento na pilha
bool Pilha::Empilhar(TipoDado dado) {
    CelulaPilha* nova = new CelulaPilha;
    if (nova == nullptr) return false;  // Falha na alocação de memória

    nova->item = dado;
    nova->prox = topo;
    topo = nova;
    return true;
}

// Remove o elemento do topo da pilha
bool Pilha::Desempilhar(TipoDado& dado) {
    if (PilhaVazia()) return false;  // Pilha vazia

    CelulaPilha* aux = topo;
    dado = topo->item;
    topo = topo->prox;
    delete aux;
    return true;
}

// Retorna o elemento no topo da pilha
TipoDado Pilha::Topo() {
    if (!PilhaVazia()) {
        return topo->item;
    }
    TipoDado vazio;
    vazio.matricula = -1;  // Retorna valor inválido se a pilha estiver vazia
    vazio.nota = -1;
    return vazio;
}
