#ifndef FILA_H
#define FILA_H

// Estrutura para armazenar o dado (matr�cula e nota)
struct TipoDado {
    int matricula;
    float nota;
};

// Estrutura de uma c�lula da fila
struct TipoCelula {
    TipoDado Item;
    TipoCelula *Prox;
};

// Classe para manipular a Fila
class Fila {
private:
    TipoCelula *Frente, *Tras;  // Ponteiros para controlar o in�cio e o fim da fila
    int Contador;  // Contador para armazenar o n�mero de elementos

public:
    Fila();  // Construtor
    ~Fila();  // Destrutor
    bool Fila_Vazia();  // Verifica se a fila est� vazia
    bool Fila_Enfileirar(TipoDado Elemento);  // Enfileira um novo elemento
    bool Fila_Desenfileirar(TipoDado &Elemento);  // Desenfileira o elemento da frente
    int Fila_Tamanho();  // Retorna o tamanho da fila
};

#endif
