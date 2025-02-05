#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori()
{
    cout <<"Luodaan notifikaattori" <<endl;
}

void Notifikaattori::lisaa(Seuraaja *seuraaja)
{
    // Lisätään uusi seuraaja listan ensimmäiseksi, joten seuraajan next osoitin laitetaan
    // osoittamaan seuraajat osoitinta, mikä toimii osoittimena listan ensimmäiseen solmuun.
    seuraaja->next = seuraajat;

    // Päivitetään seuraajat osoitin osoittamaan juuri lisättyä uutta seuraaja solmua, jotta
    // seuraaja solmusta tulisi listan uusi ensimmäinen solmu
    seuraajat = seuraaja;
    cout <<"Lisataan seuraaja: " <<seuraaja->getNimi() <<endl;
}

void Notifikaattori::poista(Seuraaja *seuraaja)
{
    // Tarkistetaan, että lista ei ole tyhjä kun aletaan poistamaan seuraajaa
    if(seuraajat != nullptr)
    {
        // Alustetaan väliaikainen pointteri, jonka avulla käydään listan solmut läpi
        Seuraaja *solmuptr = seuraajat;

        // Luodaan pointteri previous, johon myöhemmin tallennetaan poistettavan seuraajan edellinen solmu
        Seuraaja *previous;

        // Tarkistetaan, että niin kauan kun solmuptr ei ole poistettava seuraaja, käydään listaa läpi
        while(solmuptr != seuraaja)
        {
            // Tarkistetaan, onko tämän hetkisen solmun seuraava solmu poistettava seuraaja
            if(solmuptr->next == seuraaja)
            {
                // Mikäli näin oli, tallennetaan tämän hetkinen solmu previous pointteriin
                previous = solmuptr;
            }
            // Siirrytään seuraavaan solmuun
            solmuptr = solmuptr->next;
        }

        cout <<"Poistetaan seuraaja: " <<solmuptr->getNimi() <<endl;

        // Yhdistetään poistettavan seuraajan edellinen ja seuraava solmu, ja näin ollen
        // poistetaan haluttu seuraaja listalta
        previous->next = solmuptr->next;
    }
    else
    {
        cout <<"Listalla ei ole seuraajia, joita poistaa" <<endl;
    }
}

void Notifikaattori::tulosta()
{
    cout <<"Notifikaattorin seuraajat: " <<endl;
    Seuraaja *solmuptr = seuraajat;
    while(solmuptr != nullptr)
    {
        cout <<solmuptr->getNimi() <<endl;
        solmuptr = solmuptr->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    cout <<"Postataan viesti: " <<viesti <<endl;
    Seuraaja *solmuptr = seuraajat;
    while(solmuptr != nullptr)
    {
        solmuptr->paivitys(viesti);
        solmuptr = solmuptr->next;
    }
}
