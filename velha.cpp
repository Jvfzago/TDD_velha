// Copyright 2025 João Vitor Frabis Zago

/**
 * \file  velha.cpp
 */


#include "velha.hpp"

/**
 * @brief verifica situacao do jogo da velha
 * @author Programador
 * @param  velha descreve o parametro
 *
 *  Descrever o que a funcao faz
 */

//  Verifica vitoria de jogador linha
int VerificaLinha(int velha[3][3], int jogador) {
  int num = 0;

  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      if (velha[linha][coluna] == jogador) num++;
    }
    if (num == 3) {
      return 1;
    }
    num = 0;
  }
  return 0;
}

//  Verifica vitoria de jogador coluna
int VerificaColuna(int velha[3][3], int jogador) {
  int num = 0;

  for (int coluna = 0; coluna < 3; coluna++) {
    for (int linha = 0; linha < 3; linha++) {
      if (velha[linha][coluna] == jogador) num++;
    }
    if (num == 3) {
      return 1;
    }
    num = 0;
  }
  return 0;
}

int VerificaVelha(int velha[3][3]) {
  int jogadorX = 1;
  int vencedorX = 1;
  int jogadorO = 2;
  int vencedorO = 2;

  int empatado = 0;
  int indefinido = -1;
  int impossivel = -2;

  //  Verifica se X ganha na linha
  if (VerificaLinha(velha, jogadorX)) return vencedorX;

  //  Verifica se X ganha na coluna
  if (VerificaColuna(velha, jogadorX)) return vencedorX;

  //  Verifica se O ganha na linha
  if (VerificaLinha(velha, jogadorO)) return vencedorO;

  //  Verifica se O ganha na coluna
  if (VerificaColuna(velha, jogadorO)) return vencedorO;


  return 0; /*!< retorna zero para teste */
}
