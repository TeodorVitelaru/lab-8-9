#include "utils.h"
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
using namespace std;

#ifndef LAB6_REPO_H
#define LAB6_REPO_H

typedef Oferta ElemType;

class RepoAbstract
{
    public:
    RepoAbstract() = default;
    RepoAbstract (const RepoAbstract& ot) = delete;
    virtual void store(const Oferta& oferta) = 0;
    virtual void del(const Oferta& of) = 0;
    virtual void modify(const Oferta& oferta) = 0;
    virtual const vector<Oferta>& get_all_oferte() const = 0;
    virtual const Oferta& find(string denumire, string destinatie) = 0;
    virtual bool exists(const Oferta& oferta) = 0;
    virtual ~RepoAbstract() = default;
};

class Repo : public RepoAbstract
{
private:
    vector<Oferta> allOferte;
    friend class Service;
public:
    Repo() = default;
    Repo(const Repo& ot) = delete;

    /*
     * Functia de stoare a ofertei
     * oferta: oferta care se stocheaza
     * return: -
     */
    void store(const Oferta& oferta) override;

    /*
     * Functia de sterfere a ofertei
     * poz: pozitia ofertei ce urmeaza a fi stearsa
     * return: -
     */
    void del(const Oferta& of) override;

    /*
     * Functia de modificare a ofertei
     * oferta: oferta cu care se modifica
     * return: -
     */
    void modify(const Oferta& oferta) override;

    /*
     * functia de returnare a ofertelor
     * return: lista de oferte
     */
    const vector<Oferta>& get_all_oferte() const override;

    /*
     * functia de cautare a unei oferte
     * denumire: denumirea dupa care se cauta
     * destinatie: destinatia dupa care se cauta
     * return: oferta gasita
     */
    const Oferta& find(string denumire, string destinatie) override;

    /*
     * functie de verificare daca exista o oferta
     * oferta: oferta care se cauta
     * return: true sau false
     */
    bool exists(const Oferta& oferta) override;

};

class RepoFile : public Repo
{
private:
    string filename;
    void loadFromFile();
    void writeToFile();
    public:
    /*
     * constructor pt RepoFile
     */
    explicit RepoFile(string filename) : Repo(), filename{filename}
    {
        loadFromFile();
    }

    /*
     * functie de stocare a unei oferte
     * oferta: oferta care se stocheaza
     * return: -
     */
    void store(const Oferta& oferta) override
    {
        Repo::store(oferta);
        writeToFile();
    }

    /*
     * functie de stergere a unei oferte
     * of: oferta care se sterge
     * return: -
     */
    void del(const Oferta& of) override
    {
        Repo::del(of);
        writeToFile();
    }

    /*
     * functie de modificare a unei oferte
     * oferta: oferta care se modifica
     * return: -
     */
    void modify(const Oferta& oferta) override
    {
        Repo::modify(oferta);
        writeToFile();
    }
};

/*
 * clasa de exceptii pt repo
 */
class RepoException
{
private:
    string errorMsg;
public:
    RepoException(string errorMsg) :errorMsg{ errorMsg } {};
    string getErrorMessage()
    {
        return this->errorMsg;
    }
};


#endif //LAB6_REPO_H
