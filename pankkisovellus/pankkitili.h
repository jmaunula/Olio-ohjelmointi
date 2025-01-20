#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>

using namespace std;

class Pankkitili
{
public:
    Pankkitili(string, string, double);
    void talleta(double);
    void nosta(double);
    void tulostaTilitiedot();
    string getTilinumero();
    double getSaldo();
    bool siirra(Pankkitili&, double);


private:
    string tilinumero;
    string tilinomistaja;
    double saldo;
};

#endif // PANKKITILI_H
