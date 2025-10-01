// Copyright 2025 João Vitor Frabis Zago

/**
 * \file  velha.cpp
 */


#include "velha.hpp"
#include <iostream>
#include <cmath>

/**
 * @brief verifica situacao do jogo da velha
 * @author Programador
 * @param  velha descreve o parametro
 *
 *  Descrever o que a funcao faz
 */

//  Verifica vitoria de jogador linha

int ContaPecas(int velha[3][3], int jogador) {
  int num = 0;

  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      if (velha[linha][coluna] == jogador) num++;
    }
  }

  return num;
}

int VerificaLinha(int velha[3][3], int jogador) {
  int num = 0;
  int vitorias = 0;

  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      if (velha[linha][coluna] == jogador) num++;
    }
    if (num == 3) {
      vitorias++;
    }
    num = 0;
  }

  return vitorias;
}

//  Verifica vitoria de jogador coluna
int VerificaColuna(int velha[3][3], int jogador) {
  int num = 0;
  int vitorias = 0;

  for (int coluna = 0; coluna < 3; coluna++) {
    for (int linha = 0; linha < 3; linha++) {
      if (velha[linha][coluna] == jogador) num++;
    }
    if (num == 3) {
      vitorias++;
    }
    num = 0;
  }
  return vitorias;
}

int VerificarDiagonais(int velha[3][3], int jogador) {
  int num = 0;

  if (velha[0][0] == jogador) num++;
  if (velha[1][1] == jogador) num++;
  if (velha[2][2] == jogador) num++;
  if (num == 3) return 1;
  num = 0;

  if (velha[0][2] == jogador) num++;
  if (velha[1][1] == jogador) num++;
  if (velha[2][0] == jogador) num++;
  if (num == 3) return 1;

  return 0;
}

int VerificaEmpate(int velha[3][3]) {
  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      if (velha[linha][coluna] == 0) return 0;
    }
  }
  return 1;
}

int VerificaImpDiferenca(int velha[3][3], int jogador1, int jogador2) {
  int num1 = 0;
  int num2 = 0;

  for (int linha = 0; linha < 3; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      if (velha[linha][coluna] == jogador1) num1++;
      if (velha[linha][coluna] == jogador2) num2++;
    }
  }

  if (abs(num1 - num2) > 1) return 1;
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

  //  Verifica se X e O diferem em mais de 1


  int vitoriasDeX = 0;
  int vitoriasDeO = 0;

  int numX = ContaPecas(velha, jogadorX);
  int numO = ContaPecas(velha, jogadorO);

  vitoriasDeX = VerificaLinha(velha, jogadorX) +
  VerificaColuna(velha, jogadorX) +
  VerificarDiagonais(velha, jogadorX);
  vitoriasDeO = VerificaLinha(velha, jogadorO) +
  VerificaColuna(velha, jogadorO) +
  VerificarDiagonais(velha, jogadorO);

  // 1. Múltiplos Vencedores: Se X e O ganharam simultaneamente
  if (vitoriasDeX > 0 && vitoriasDeO > 0) {
    return -2;
  }

  // 2. Se X ou O possuem mais de uma vitória
  if (vitoriasDeX > 1 || vitoriasDeO > 1) return impossivel;


  //
  if (VerificaImpDiferenca(velha, jogadorO, jogadorX)) return impossivel;

  // Vitória Inconsistente com a Contagem de Peças (X sempre começa)
  // if (vitoriasDeX > 0 && numX < numO) {
  //   return impossivel;
  // }
  // if (vitoriasDeO > 0 && numO < numX) {
  //   return impossivel;
  // }

  //  Vitoria de um deles
  if (vitoriasDeX > 0) {
        return vencedorX;
    }

  if (vitoriasDeO > 0) {
      return vencedorO;
  }


  //  Verifica empate (deve estar depois dos códigos que verificam vitoria)
  if (VerificaEmpate(velha)) return empatado;

  //  Retorna indefinido
  //  Já verificou-se se o jogo não é impossível, se alguém ganhou e
  //  se deu empate, logo, necessariamente o jogo
  //  tem que estar ainda indefinido
  return indefinido;

  return -3;  // Nao caiu em nenhum caso (-3)
}
