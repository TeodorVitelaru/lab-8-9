#pragma once
#include "domain.h"
#include <vector>

class cosOferte
{
private:
    vector<Oferta> cos;
public:
    /*
     * Constructorul clasei cosOferte
     */
    cosOferte() = default;

    /*
     * Functie de adaugare a unei oferte in cos
     * of: obiect de tip Oferta
     * return: -
     */
    void adauga_oferta_cos(const Oferta& of);

    /*
     * Functie de adaugare a unui numar random de oferte in cos
     * of: vector de oferte
     * numar: numarul de oferte care se adauga
     * return: -
     */
    void adauga_random_cos(vector<Oferta>, int numar);

    /*
     * Functie de stergere a tuturor ofertelor din cos
     * return: -
     */
    void sterge_cos();

    /*
     * Functie de returnare a tuturor ofertelor din cos
     * return: vector de oferte
     */
    const vector<Oferta>& get_all_cos();

    /*
     * Destructorul clasei cosOferte
     */
    ~cosOferte() = default;
};