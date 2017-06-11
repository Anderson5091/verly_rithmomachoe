
//
// Created by zeta on 5/18/2017.
//

#ifndef ARITHMOMACHIE_STRUCTURE_H
#define ARITHMOMACHIE_STRUCTURE_H
#define LARGEUR_FENETRE 1224
#define LONGEUR_FENETRE 750

#define LONGEUR_ECHIQUIER 635
#define LARGEUR_ECHIQUIER 327.5

#define NONB_LIYN 16
#define NONB_KOLON 8

#define COIN_SUPERIEUR_X() (LARGEUR_FENETRE-LARGEUR_ECHIQUIER)/2;
#define COIN_SUPERIEUR_Y() (LONGEUR_FENETRE-LONGEUR_ECHIQUIER)/2;
#define LONG_CASE 38.4375
#define LONG_PIECE 22.4375

#define CBLANC() al_map_rgb(160, 0, 240)
#define CNOIR()  al_map_rgb(0,0,0)
#define EP 1.5
#define _PI  3.14
//#include "header.h"
//#include "constante.h"
//#include "affichage.h"

typedef struct {
    int fom;
    int koule;
    int nimewo
     ;
} pyon;

typedef struct{
    int x;
    int y;
}vekte;

typedef struct
{
    vekte pozisyon;
    vekte endis;
    pyon* pyon;
}Kaz;




enum{KARE, TRIYANG, PYRAMID, WON};
enum{NWA,   BLAN};








#endif //ARITHMOMACHIE_AFFICHAGE_H
