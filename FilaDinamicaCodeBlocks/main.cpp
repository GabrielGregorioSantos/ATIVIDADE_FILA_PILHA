#include <iostream>
#include <cstdio>
#include "Fila.h"
#include "Pilha.h"

using namespace std;

int main() {
    // Declaração de uma fila e de uma pilha
    Fila fila;
    Pilha pilha;

    // Variáveis para armazenar as entradas de matrícula e nota
    TipoDado matriculaNota;
    char continuar;

    cout << "Bem-vindo ao sistema de ordenação de notas!" << endl;

    // Loop para enfileirar matrículas e notas
    do {
        cout << "Digite a matrícula do aluno: ";
        cin >> matriculaNota.matricula;
        cout << "Digite a nota do aluno: ";
        cin >> matriculaNota.nota;

        // Enfileirar na fila
        if (fila.Enfileirar(matriculaNota)) {
            cout << "Aluno com matrícula " << matriculaNota.matricula << " enfileirado com sucesso!" << endl;
        } else {
            cout << "Erro ao enfileirar aluno!" << endl;
        }

        // Perguntar se o usuário deseja continuar
        cout << "Deseja adicionar mais alunos? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    // Desenfileirar e empilhar na ordem correta
    while (!fila.FilaVazia()) {
        fila.Desenfileirar(matriculaNota);
        pilha.EmpilharOrdenado(matriculaNota);  // Empilhar os dados na pilha ordenadamente
    }

    // Desempilhar e mostrar os elementos
    cout << "Ordem final dos alunos (do maior para o menor):" << endl;
    while (!pilha.PilhaVazia()) {
        pilha.Desempilhar(matriculaNota);
        cout << "Matricula: " << matriculaNota.matricula << " - Nota: " << matriculaNota.nota << endl;
    }

    return 0;
}
