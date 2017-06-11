#include "header.h"
#include "structure.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>


#define WOTE_EKAN 725
#define LAJE_EKRAN 1224
#define GWOSE_KAZ 40
#define GWOSE_PYON 60
#define WOUJ al_map_rgb(255,0,0)


void Deplase(vekte liSoti, vekte liPrale);
int kazlabloke(vekte kazla);
int arithmetik(vekte sibLa,vekte atakan);

// varyab global nap gen bezwen yo
ALLEGRO_DISPLAY *ekran; // ekran an
ALLEGRO_FONT *arial72; // ekriti yo
ALLEGRO_EVENT_QUEUE *event_queue; // evenman yo
ALLEGRO_COLOR couleur;

void orijin_plato (vekte *orijin) {
    // fonksyon sa kreye orijin plato jwet la
    orijin->x = (LAJE_EKRAN - GWOSE_KAZ * 8) / 2;
    orijin->y = (WOTE_EKAN - GWOSE_KAZ * 16) / 2;
}

void kalkile_pozisyon_kaz (vekte *vek, int i, int j) {
    // fonksyon kalkile pozisyon yon kaz sou plato jwet la
    vekte orijin;

    orijin_plato(&orijin);
    vek->x = GWOSE_KAZ * i + GWOSE_KAZ / 2 + orijin.x;
    vek->y = GWOSE_KAZ * j + GWOSE_KAZ / 2 + orijin.y;

}

/*void kare(int x, int y, ALLEGRO_COLOR koule){
    al_draw_filled_rectangle(x-GWOSE_KAZ/3, y-GWOSE_KAZ/3, x+GWOSE_KAZ /3, y+GWOSE_KAZ/3,koule);

}*/

pyon *init_pyon (int i, int j) {
    //fonksyon mete pyon yo nan premye pozisyon yo sou plato a
    if (i >= 0 && j > 1 && i < 1 && j < 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 49;
        return pyon;
    } else if (i >= 1 && j > 1 && i < 2 && j < 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 121;
        return pyon;

    } else if (i >= 0 && j > 1 && i < 1 && j < 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 28;
        return pyon;
    } else if (i >= 1 && j > 1 && i < 2 && j < 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 66;
        return pyon;
    } else if (i > 5 && j > 1 && i < 7 && j < 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 225;
        return pyon;
    } else if (i > 6 && j > 1 && i <= 7 && j < 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 361;
        return pyon;
    } else if (i > 5 && j > 2 && i < 7 && j < 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 120;
        return pyon;
    } else if (i > 6 && j > 2 && i <= 7 && j < 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = NWA;
        pyon->nimewo = 0;
        return pyon;
    } else if (i > 1 && j > 2 && i < 3 && j < 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 36;
        return pyon;
    } else if (i == 3 && j == 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 30;
        return pyon;
    } else if (i == 4 && j == 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 56;
        return pyon;
    } else if (i == 5 && j == 3) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 64;
        return pyon;
    } else if (i == 0 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 16;
        return pyon;
    } else if (i == 1 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 12;
        return pyon;
    } else if (i == 6 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 90;
        return pyon;
    } else if (i == 7 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = NWA;
        pyon->nimewo = 100;
        return pyon;
    } else if (i == 2 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 9;
        return pyon;
    } else if (i == 3 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 25;
        return pyon;
    } else if (i == 4 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 49;
        return pyon;
    } else if (i == 5 && j == 4) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 81;
        return pyon;
    } else if (i == 2 && j == 5) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 3;
        return pyon;
    } else if (i == 3 && j == 5) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 5;
        return pyon;
    } else if (i == 4 && j == 5) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 7;
        return pyon;
    } else if (i == 5 && j == 5) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = NWA;
        pyon->nimewo = 9;
        return pyon;
    } else if (i == 2 && j == 10) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 8;
        return pyon;
    } else if (i == 3 && j == 10) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 6;
        return pyon;
    } else if (i == 4 && j == 10) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 4;
        return pyon;
    } else if (i == 5 && j == 10) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 2;
        return pyon;
    } else if (i == 2 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 64;
        return pyon;
    } else if (i == 3 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 36;
        return pyon;
    } else if (i == 4 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 16;
        return pyon;
    } else if (i == 5 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = WON;
        pyon->koule = BLAN;
        pyon->nimewo = 4;
        return pyon;
    } else if (i == 0 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 81;
        return pyon;
    } else if (i == 1 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 72;
        return pyon;
    } else if (i == 6 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 6;
        return pyon;
    } else if (i == 7 && j == 11) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 9;
        return pyon;
    } else if (i == 2 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 49;
        return pyon;
    } else if (i == 3 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 42;
        return pyon;
    } else if (i == 4 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 20;
        return pyon;
    } else if (i == 5 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = TRIYANG;
        pyon->koule = BLAN;
        pyon->nimewo = 25;
        return pyon;
    } else if (i == 0 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 153;
        return pyon;
    } else if (i == 1 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 0;
        return pyon;
    } else if (i == 6 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 45;
        return pyon;
    } else if (i == 7 && j == 12) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 15;
        return pyon;
    } else if (i == 0 && j == 13) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 289;
        return pyon;
    } else if (i == 1 && j == 13) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 169;
        return pyon;
    } else if (i == 6 && j == 13) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 81;
        return pyon;
    } else if (i == 7 && j == 13) {
        pyon *pyon = al_malloc(sizeof(pyon));
        pyon->fom = KARE;
        pyon->koule = BLAN;
        pyon->nimewo = 25;
        return pyon;
    } else {
        return NULL;
    }


}

// sa se matris kaz ki sou plato a
Kaz tablo[8][16];

void init_kaz () {
    //fonksyon mete kaz plato a
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++) {
            kalkile_pozisyon_kaz(&(tablo[i][j].pozisyon), i, j);
            tablo[i][j].pyon = init_pyon(i, j);
            tablo[i][j].endis = (vekte){i, j};
        }

    }
}


// FOnksyon sa dwe retounen 0 si te gen yon ere kelkonk
// se la nou inisyalize tout sa nou pral bezwen nan bibliyotek la
int init () {
    al_init();
    ekran = al_create_display(LAJE_EKRAN, WOTE_EKAN);
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    arial72 = al_load_ttf_font("arial.ttf", 10, 0);
    al_install_mouse();
    al_install_keyboard();
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_mouse_event_source());
    init_kaz();

    return 1;
}

int seleksyone = 0;
vekte endis_seleksyon = {-1, -1};

void efase_seleksyon () {
    seleksyone = 0;
    endis_seleksyon.x = -1;
    endis_seleksyon.y = -1;
}

// Fonksyon sa dwe modifye varyab selman li pa dwe rele pyes fonksyon pou afiche
int mizajou (ALLEGRO_EVENT *event) {
    vekte orijin;
    int i, j, a, b;
    int result = 0;
    int bouton_klike = 0;
    int x = -1, y = -1;
    orijin_plato(&orijin);
    switch (event->type) {
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP: // Moun nan klike bouton an
            bouton_klike = 1;
            x = event->mouse.x;
            y = event->mouse.y;
            // case ALLEGRO_EVENT_KEY_UP: // Moun nan peze yon bouton
    }
    if (bouton_klike && event->mouse.button == 1) {

        if (((orijin.x <= x) && (x <= orijin.x + GWOSE_KAZ * 8)) && ((orijin.y <= y) && (y <= orijin.y + GWOSE_KAZ * 16))) {
            // jwenn endis tablo a
            a = (x - orijin.x) / GWOSE_KAZ;
            b = (y - orijin.y) / GWOSE_KAZ;
            Kaz *  nouvo_kaz = &tablo[a][b];
            if (seleksyone) {
                // Nou gentan gen yon kaz deja ki seleksyone
                Kaz * ansyen_kaz = &tablo[endis_seleksyon.x][endis_seleksyon.y]; //Kaz ki te seleksyone a
                // Verifye ke kote nou klike a pa gen pyon
                if (nouvo_kaz->pyon == NULL) {
                    // Nou ka deplase
                    Deplase(ansyen_kaz->endis,nouvo_kaz->endis);

                }
                else if(nouvo_kaz->pyon->koule!=ansyen_kaz->pyon->koule&&kazlabloke(nouvo_kaz->endis)){
                    Deplase(ansyen_kaz->endis,nouvo_kaz->endis);
                }
                else if(nouvo_kaz->pyon->koule!=ansyen_kaz->pyon->koule &&arithmetik(nouvo_kaz->endis,ansyen_kaz->endis)){
                    Deplase(ansyen_kaz->endis,nouvo_kaz->endis);
                }


                efase_seleksyon();
                result = 1;

            } else {
                //Nou poko seleksyone
                if (nouvo_kaz->pyon != NULL) {
                    // Gen pyon la
                    seleksyone = 1;
                    endis_seleksyon.x = a;
                    endis_seleksyon.y = b;
                    result = 1;
                }
            }
        }
    }

    return result;
}


//Fonksyon sa dwe afiche sou ekran an san li pa modifye pyes varyab jwet la tankou tablo a
void afiche () {
    al_clear_to_color(al_map_rgb(0, 0, 97));

    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++) {
            Kaz kazye = tablo[i][j];
            int x = tablo[i][j].pozisyon.x;
            int y = tablo[i][j].pozisyon.y;


            ALLEGRO_COLOR color = (i % 2 == j % 2) ? al_map_rgb(76, 56, 67) : al_map_rgb(40, 42, 1);

            if (seleksyone && i == endis_seleksyon.x && j == endis_seleksyon.y) color = al_map_rgb(0, 255, 0);

            al_draw_filled_rectangle(x - GWOSE_KAZ / 2, y - GWOSE_KAZ / 2, x + GWOSE_KAZ / 2, y + GWOSE_KAZ / 2,
                                     color);


            if (kazye.pyon != NULL) {

                pyon *pyon = kazye.pyon;
                ALLEGRO_COLOR koule = pyon->koule == NWA ? al_map_rgb(0, 0, 0) : al_map_rgb(255, 255, 255);

                switch (pyon->fom) {
                    case KARE:
                        al_draw_filled_rectangle(x - GWOSE_KAZ / 3, y - GWOSE_KAZ / 3, x + GWOSE_KAZ / 3,
                                                 y + GWOSE_KAZ / 3, koule);
                        break;
                    case TRIYANG :
                        al_draw_filled_triangle(x, y - GWOSE_PYON / 3.0, x - (sqrt(3) * GWOSE_PYON) / 6.0,
                                                y + GWOSE_PYON / 6.0, x + (sqrt(3) * GWOSE_PYON) / 6.0,
                                                y + GWOSE_PYON / 6.0, koule);
                        break;
                    case WON:
                        al_draw_filled_circle(x, y, GWOSE_KAZ / 3, koule);

                }
                //al_draw_filled_rectangle(x-GWOSE_KAZ/3, y-GWOSE_KAZ/3, x+GWOSE_KAZ /3, y+GWOSE_KAZ/3, al_map_rgb(0, 0, 0));
                //kare(x, y, al_map_rgb(250, 250, 250));
                al_draw_textf(arial72, WOUJ, x, y, ALLEGRO_ALIGN_CENTER, "%d", pyon->nimewo);
            }


        }

    }


    al_flip_display();
}

//Fout detwi tout sa ou te kreye yo la
void deinit () {
    al_destroy_display(ekran);
    al_destroy_event_queue(event_queue);

}


int main () {
    if (!init()) {
        return 1;
    }
    int fini = 0;
    int premye_afichaj = 1;
    int counter = 0;
    while (!fini) {
        counter++;
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        int reafiche = mizajou(&event);
        if (reafiche || premye_afichaj) afiche();
        premye_afichaj = 0;
        // Gade si jwet la fini
        switch (event.type) {
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                if (event.mouse.button == 2) fini = 1;
        }
        al_rest(1.0 / 60);
    }
    deinit();
    return 0;
}

void Deplase(vekte liSoti, vekte liPrale)
{
    int deplase=0;
    printf("verifie deplasman...\n");
    if(tablo[liSoti.x][liSoti.y].pyon)
    {
        printf("verifier deplasman an\n");
        if(tablo[liSoti.x][liSoti.y].pyon->fom==WON)
        {
            if((liPrale.x==liSoti.x+1&&(liPrale.y==liSoti.y+1||liPrale.y==liSoti.y-1))||
               (liPrale.x==liSoti.x-1&&(liPrale.y==liSoti.y+1||liPrale.y==liSoti.y-1)))
            {
               deplase=1;
            }
        }
        else if(tablo[liSoti.x][liSoti.y].pyon->fom==TRIYANG)
        {
            if((liPrale.y==liSoti.y+2 || liPrale.y==liSoti.y-2)&&(liPrale.x==liSoti.x+1 || liPrale.x==liSoti.x-1))
            {
                deplase=1;
            }
            else if( liPrale.y==liSoti.y && ((liPrale.x==liSoti.x+2 && tablo[liSoti.x+1][liSoti.y].pyon==NULL) ||(liPrale.x==liSoti.x+2&&tablo[liSoti.x][liSoti.y].pyon==NULL)))
            {
               deplase=1;
            }
        }
    }
    if(deplase)
    {
        tablo[liPrale.x][liPrale.y].pyon=tablo[liSoti.x][liSoti.y].pyon;
        tablo[liSoti.x][liSoti.y].pyon=NULL;
    }
}

int kazlabloke(vekte kazla)
{
    printf("nap verifye blokaj la\n");
    vekte pozisyon;
    float ang;
    int blokaj=0, longe, direksyon, distans, i, j,fom;
    fom=tablo[kazla.x ][kazla.y].pyon->fom;
    distans=(fom==0)?3:((fom==1)?2:1);

        for(ang=0,direksyon=0;direksyon<8;direksyon++,ang=ang+_PI/4.0){

            for(longe=0;longe<distans;longe++){
                pozisyon.y=(int)floor(cos(ang)+0.5);
                pozisyon.x=(int)-floor(sin(ang)+0.5);
                pozisyon.y=(pozisyon.y>0)?pozisyon.y+longe:((pozisyon.y<0)?pozisyon.y-longe:pozisyon.y);
                pozisyon.x=(pozisyon.x>0)?pozisyon.x+longe:((pozisyon.x<0)?pozisyon.x-longe:pozisyon.x);

                if((kazla.x+pozisyon.x<0 ||kazla.x+pozisyon.x>7)||(kazla.y+pozisyon.y<0||kazla.y+pozisyon.y>15)){
                    blokaj=1;
                    continue;
                }

                blokaj=0;
                switch(fom){
                    case 0: if(direksyon==0||direksyon==2||direksyon==4||direksyon==6 ){
                                if(tablo[kazla.x+pozisyon.x ][kazla.y+pozisyon.y].pyon){
                                    if(tablo[kazla.x+pozisyon.x ][kazla.y+pozisyon.y].pyon->koule!=tablo[kazla.x ][kazla.y].pyon->koule)
                                      blokaj=1;
                                }
                            }
                            else
                                blokaj=1;
                        break;

                    case 1: if(direksyon==0||direksyon==2||direksyon==4||direksyon==6 ){
                                if(tablo[kazla.x+pozisyon.x][kazla.y+pozisyon.y].pyon){
                                    if(tablo[kazla.x+pozisyon.x][kazla.y+pozisyon.y].pyon->koule!=tablo[kazla.x ][kazla.y].pyon->koule)
                                      blokaj=1;
                                }
                            }
                            else
                                blokaj=1;
                        break;

                    case 2:  if(tablo[kazla.x+pozisyon.x][kazla.y+pozisyon.y].pyon){
                                    if(tablo[kazla.x+pozisyon.x][kazla.y+pozisyon.y].pyon->koule!=tablo[kazla.x ][kazla.y].pyon->koule)
                                      blokaj=1;
                                }
                        break;

                    case 3: if(direksyon==1||direksyon==3||direksyon==5||direksyon==7 ){
                                if(tablo[kazla.x+pozisyon.x ][kazla.y+pozisyon.y].pyon){
                                    if(tablo[kazla.x+pozisyon.x ][kazla.y+pozisyon.y].pyon->koule!=tablo[kazla.x ][kazla.y].pyon->koule)
                                      blokaj=1;
                                }
                            }
                            else
                                blokaj=1;
                        break;
                }
                if(blokaj)
                    break;
            }

                if(!blokaj&&longe==distans)
                    break;
        }
        if(blokaj)
            printf("ou AAA\n");
        else
            printf("Epa kounya\n");

        return blokaj;
}

int cheke_oprasyon(int nimewoSibLa,int nimewoAtakan, int nimewoKolon){
    if(nimewoSibLa==nimewoAtakan+nimewoKolon||nimewoSibLa==nimewoAtakan-nimewoKolon||nimewoSibLa==nimewoKolon-nimewoAtakan||
       nimewoSibLa==nimewoAtakan*nimewoKolon||nimewoSibLa==nimewoAtakan/nimewoKolon||nimewoSibLa==nimewoKolon/nimewoAtakan)
        return 1;
    else
        return 0;
}

int arithmetik(vekte sibLa,vekte atakan)
{   printf("nap verifye arimetik la\n");
    vekte pozisyon;
    float ang=0;
    int cheke=0, direksyon=0, longe, distans, fom, fomAtakan,fomSibLa;
    fom=tablo[sibLa.x ][sibLa.y].pyon->fom;
    fomAtakan=tablo[atakan.x ][atakan.y].pyon->fom;
    distans=(fom==0)?3:((fom==1)?2:1);

    if(tablo[sibLa.x][sibLa.y].pyon->fom!=tablo[atakan.x][atakan.y].pyon->fom
       &&tablo[sibLa.x][sibLa.y].pyon->nimewo==tablo[atakan.x][atakan.y].pyon->nimewo)
        return 1;

        do{
                for(longe=0;longe<distans;longe++){
                    pozisyon.y=(int)floor(cos(ang)+0.5);
                    pozisyon.x=(int)-floor(sin(ang)+0.5);
                    pozisyon.y=(pozisyon.y>0)?pozisyon.y+longe:((pozisyon.y<0)?pozisyon.y-longe:pozisyon.y);
                    pozisyon.x=(pozisyon.x>0)?pozisyon.x+longe:((pozisyon.x<0)?pozisyon.x-longe:pozisyon.x);

                    if((sibLa.x+pozisyon.x<0 ||sibLa.x+pozisyon.x>7)||(sibLa.y+pozisyon.y<0||sibLa.y+pozisyon.y>15))
                        continue;

                    switch(fom){
                        //1-swithc fom nan 0 kare 1 triyang 2 pyramid 3 won
                            //2-apre gade si li nan yon direksion orizontal(pe) [if...] oubyen dyagonal (enpe) [else...]
                                //3- si gen yon pyon nan pozisyon an  [if...]
                                        //4-verifie li gen yon koule ki diferan de sib la epi verifye li se yon fom ki nan bon distans(bon -longe) deplasman an epi [if ... && ...
                                            //5-cheche aritmetik lan sil bon [if cheke_op..]
                                                //si wi cheke pran vale 1
                                                //sinon li change direksyon pou eseye avek lot pyes
                                                //si li jwen youn li pa eseye anko li fini


                        case 0: if(direksyon==0||direksyon==2||direksyon==4||direksyon==6){
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==0 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==1 && longe==1)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }
                                else{
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==2 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==3 && longe==0)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }

                            break;

                        case 1: if(direksyon==0||direksyon==2||direksyon==4||direksyon==6){
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==0 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==1 && longe==1)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }
                                else{
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==2 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==3 && longe==0)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }

                            break;

                        case 2: if(direksyon==0||direksyon==2||direksyon==4||direksyon==6){
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==0 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==1 && longe==1)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }
                                else{
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==2 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==3 && longe==0)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }

                            break;

                        case 3: if(direksyon==0||direksyon==2||direksyon==4||direksyon==6){
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==0 && longe==2)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==1 && longe==1)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }
                                else{
                                    if(tablo[sibLa.x+pozisyon.x ][sibLa.y+pozisyon.y].pyon){
                                        if(tablo[sibLa.x][sibLa.y].pyon->koule!=tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->koule&&
                                           ((tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==2 && longe==0)||(tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->fom==3 && longe==0)))
                                            if(cheke_oprasyon(tablo[sibLa.x][sibLa.y].pyon->nimewo,tablo[atakan.x][atakan.y].pyon->nimewo,tablo[sibLa.x+pozisyon.x][sibLa.y+pozisyon.y].pyon->nimewo))
                                                cheke=1;
                                    }
                                }

                            break;
                }
            }
            direksyon++;    ang=ang+_PI/4.0;
        }while(direksyon<8&&!cheke);
        if(cheke)
            printf("ou AAA\n");
        else
            printf("Epa kounya\n");

        return cheke;
}

