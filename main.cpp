#include <iostream>

using namespace std;

#include "header.hpp"


int main () {
    giocatore g;
    partita p;

    p.CaricaGiocatore(2);
    p.Gioco();
}
