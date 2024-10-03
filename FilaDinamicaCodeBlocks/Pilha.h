#ifndef FILA_H
#define FILA_H

// Estrutura para armazenar a matrícula e a nota
struct TipoDado {
    int matricula;
    float nota;
};

// Estrutura de uma célula da fila
struct TipoCelula {
    TipoDado item;
    TipoCelula* prox;
};

// Classe para a fila dinâmica
class Fila {
private:
    TipoCelula* frente;
    TipoCelula* tras;
    int contador;

public:
    Fila();  // Construtor
    ~Fila();  // Destrutor
    bool FilaVazia();  // Verifica se a fila está vazia
    bool Enfileirar(TipoDado dado);  // Insere na fila
    bool Desenfileirar(TipoDado& dado);  // Remove da fila
    int TamanhoFila();  // Retorna o tamanho da fila
};

#endif
