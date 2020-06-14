#ifndef ATOM_HPP
#define ATOM_HPP

struct ATOM{
    double A; // numero de massa = numero de nucleoes
    int Z; // numero atomico = numero de protoes
    const char* name; // nome dos elementos
};
void print(vector<ATOM>);
void print(ATOM);
vector<ATOM> vperiodic();

#endif
