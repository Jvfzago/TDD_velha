// Copyright 2025 João Vitor Frabis Zago

João Vitor Frabis Zago
242039256

Utilize o seguinte comando para rodar o código:
make all

Ou então use essas duas linhas de comando:
g++ -std=c++11 -Wall -c velha.cpp
g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
./testa_velha

Há também uma função adicional no makefile que serve para rodar os três avaliadores de uma só vez:
make check_quality