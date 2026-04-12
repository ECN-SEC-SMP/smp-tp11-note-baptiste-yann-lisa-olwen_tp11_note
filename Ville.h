#ifndef VILLE_H
#define VILLE_H

#include <string>

class Ville
{
private:
    std::string nom;
    bool coteOuest;
    bool coteEst;
public:
    Ville();
    Ville(const std::string& nom);
    const std::string& getNom() const;
    bool estCoteOuest() const;
    bool estCoteEst() const;
};

#endif