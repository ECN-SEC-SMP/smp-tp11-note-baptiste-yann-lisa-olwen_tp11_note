#pragma once
#include <string>

enum class CouleurCarte
{
    Bleu,
    Blanc,
    Rouge,
    Noir,
    Jaune,
    Vert,
    Locomotive
};

inline std::string couleurToString(CouleurCarte couleur)
{
    switch (couleur) {
        case CouleurCarte::Bleu:       return "Bleu";
        case CouleurCarte::Blanc:      return "Blanc";
        case CouleurCarte::Rouge:      return "Rouge";
        case CouleurCarte::Noir:       return "Noir";
        case CouleurCarte::Jaune:      return "Jaune";
        case CouleurCarte::Vert:       return "Vert";
        case CouleurCarte::Locomotive: return "Locomotive";
        default:                       return "Inconnu";
    }
}
