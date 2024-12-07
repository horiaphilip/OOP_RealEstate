// agent_vanzari.cpp
#include "agent_vanzari.h"
#include <iostream>

AgentVanzari::AgentVanzari(const std::string& nume, const std::string& prenume, const std::string& cod)
    : m_nume(nume), m_prenume(prenume), m_cod(cod) {}

void AgentVanzari::adaugaCasa(const Casa& casa) {
    m_case.push_back(casa);
}

void AgentVanzari::adaugaTeren(const Teren& teren) {
    m_terenuri.push_back(teren);
}

void AgentVanzari::adaugaApartament(const Apartament& apartament) {
    m_apartamente.push_back(apartament);
}

void AgentVanzari::afiseazaCase() const {
    std::cout << "Casele agentului " << m_nume << " " << m_prenume << " (Cod: " << m_cod << "):\n";
    for (const auto& casa : m_case) {
        std::cout << "----------------\n";
        casa.afiseazaDetalii();
    }
    std::cout << "----------------\n";
}

void AgentVanzari::afiseazaTerenuri() const {
    std::cout << "Terenurile agentului " << m_nume << " " << m_prenume << " (Cod: " << m_cod << "):\n";
    for (const auto& teren : m_terenuri) {
        std::cout << "----------------\n";
        teren.afiseazaDetalii();
    }
    std::cout << "----------------\n";
}

void AgentVanzari::afiseazaApartamente() const {
    std::cout << "Apartamentele agentului " << m_nume << " " << m_prenume << " (Cod: " << m_cod << "):\n";
    for (const auto& apartament : m_apartamente) {
        std::cout << "----------------\n";
        apartament.afiseazaDetalii();
    }
    std::cout << "----------------\n";
}

void AgentVanzari::afiseazaDetaliiImobile() const {
    afiseazaCase();
    afiseazaTerenuri();
    afiseazaApartamente();
}

double AgentVanzari::calculeazaPretFinalImobil(size_t index) const {
    double pretFinal = 0.0;

    // Calculează prețul final pentru imobilul de la indexul dat în fiecare categorie
    if (index < m_case.size()) {
        pretFinal = m_case[index].calculeazaPretPeMetruPatrat() + m_case[index].calculeazaComision();
    } else if (index < m_case.size() + m_terenuri.size()) {
        index -= m_case.size();
        pretFinal = m_terenuri[index].calculeazaPretPeMetruPatrat() + m_terenuri[index].calculeazaComision();
    } else if (index < m_case.size() + m_terenuri.size() + m_apartamente.size()) {
        index -= (m_case.size() + m_terenuri.size());
        pretFinal = m_apartamente[index].calculeazaPretPeMetruPatrat() + m_apartamente[index].calculeazaComision();
    } else {
        throw std::out_of_range("Indexul dat depășește numărul de imobile.");
    }

    return pretFinal;
}
