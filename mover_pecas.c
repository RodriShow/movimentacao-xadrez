#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char board[8][8];

void iniciarTabuleiro() {
    memset(board, '.', sizeof(board));
    board[6][4] = 'P'; // Peão em e2 (índice invertido: linha 6, coluna 4)
    board[7][3] = 'Q'; // Rainha em d1
    board[0][4] = 'k'; // Rei inimigo em e8
}

void posParaIndice(char *pos, int *linha, int *coluna) {
    *coluna = pos[0] - 'a';
    *linha = 8 - (pos[1] - '0');
}

bool isEmpty(char *pos) {
    int l, c;
    posParaIndice(pos, &l, &c);
    return board[l][c] == '.';
}

bool move(char *origem, char *destino) {
    int lo, co, ld, cd;
    posParaIndice(origem, &lo, &co);
    posParaIndice(destino, &ld, &cd);

    if (board[lo][co] == '.') {
        printf("Erro: nenhuma peça em %s\n", origem);
        return false;
    }

    board[ld][cd] = board[lo][co];
    board[lo][co] = '.';
    printf("Movido %s -> %s\n", origem, destino);
    return true;
}

void imprimirTabuleiro() {
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

void estrategiaPeao() {
    if (isEmpty("e3")) {
        move("e2", "e3");
    }
}

void ataqueRainha() {
    if (isEmpty("d4")) {
        move("d1", "d4");
    }
    if (isEmpty("e7")) {
        move("d4", "e7"); // Rainha vai para perto do rei
    }
}

int main() {
    iniciarTabuleiro();
    imprimirTabuleiro();

    estrategiaPeao();
    ataqueRainha();

    imprimirTabuleiro();
    return 0;
}
