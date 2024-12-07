
#pragma once

#include <string>
#include <vector>
#include "casa.h"
#include "teren.h"
#include "apartament.h"
#include "client.h"
#include <memory>

class AgentVanzari
{
public:
    AgentVanzari(const std::string& nume, const std::string& prenume, const std::string& cod);
    void adaugaCasa(const Casa& casa);
    void adaugaMultumit(std::shared_ptr<ClientMultumit>multumit);
    void adaugaNemultumit(std::shared_ptr<ClientNemultumit>nemultumit);
    void adaugaTeren(const Teren& teren);
    void adaugaApartament(const Apartament& apartament);
    void afiseazaCase() const;
    void afiseazaTerenuri() const;
    void afiseazaApartamente() const;
    void afiseazaDetaliiImobile() const;
    double calculeazaPretFinal() const;
    void setProcentCastigPersonal( double procent);
    double calculeazaPretFinalImobil(const int tip,const int nr) const;
    std::string getNume() const;
    double getProcentCastig() const;
    std::string getPrenume() const;
    std::string getCod() const;
    std::vector<std::shared_ptr<ClientMultumit>> getClientiMultumiti() const;
    std::vector<std::shared_ptr<ClientNemultumit>> getClientiNemultumiti() const;
private:
    std::string m_nume;
    std::string m_prenume;
    std::string m_cod;
    std::vector<Casa> m_case;
    std::vector<std::shared_ptr<ClientMultumit>> m_multumiti;

    std::vector<Teren> m_terenuri;
    std::vector<Apartament> m_apartamente;
    std::vector<std::shared_ptr<ClientNemultumit>> m_nemultumiti;
    static double m_procentCastigPersonal ;
};



