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

int VerificaVelha(int velha[3][3]) {
  int num = 0;

  for (int coluna = 0; coluna < 3; coluna++) {  // Verifica vitoria de X coluna
    for (int linha = 0; linha < 3; linha++) {
      if (velha[linha][coluna] == 1) num++;
    }
    if (num == 3) {
      return 1;
    }
    num = 0;
  }

  for (int linha = 0; linha < 3; linha++) {  // Verifica vitoria de X linha
      for (int coluna = 0; coluna < 3; coluna++) {
        if (velha[linha][coluna] == 1) num++;
      }
      if (num == 3) {
        return 1;
      }
      num = 0;
  }

  for (int coluna = 0; coluna < 3; coluna++) {  // Verifica vitoria de O coluna
    for (int linha = 0; linha < 3; linha++) {
      if (velha[linha][coluna] == 2) num++;
    }
    if (num == 3) {
      return 2;
    }
    num = 0;
  }

  for (int linha = 0; linha < 3; linha++) {  // Verifica vitoria de O linha
    for (int coluna = 0; coluna < 3; coluna++) {
      if (velha[linha][coluna] == 2) num++;
    }
    if (num == 3) {
      return 2;
    }
    num = 0;
  }

  return 0; /*!< retorna zero para teste */
}
