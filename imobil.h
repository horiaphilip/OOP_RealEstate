#pragma once

#include <string>

class Imobil
{
public:
    Imobil(const std::string& adresa, double pret, double suprafata);
    virtual ~Imobil() {}
    virtual void afiseazaDetalii() const = 0;
    virtual double calculeazaPretPeMetruPatrat() const = 0;
    virtual double calculeazaComision() const = 0;
    std::string getAdresa() const;
    void setAdresa(const std::string& adresa);
    double getPret() const;
    void setPret(double pret);
    double getSuprafata() const;
    void setSuprafata(double suprafata);
    virtual Imobil& operator=(const Imobil& other) ;
protected:
    std::string m_adresa;
    double m_pret;
    double m_suprafata;
};

