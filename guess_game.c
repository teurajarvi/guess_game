// Write a number guess game. User is asked to guess for a number
// between given numbers (say 1-100). The program has randomly selected
// one number and gives hints if the guess is wrong. In the end it
// displays the number of guesses that it took.

/* yleiset kirjastot */
#include <stdio.h>  /* lukemista ja tulostusta varten                */
#include <stdlib.h> /* random funtion käyttö                         */
#include <time.h>   /* time muuttujaa rand generaattorin alustukseen */

/* omat headerit */
#include "guess_game.h"

/* tässä tiedostossa näkyvät muuttujat */
int user_luku;
int oikea_luku;

/* ohjelman pääfunktio */
int main(void)
	{
    bool oikein = FALSE;
    int i = 1;

    oikea_luku = arvonta( );
	printf( " Arvaa luku väliltä 1-100. \n" );
	printf( "\n Luku: " );
    scanf( "%d", &user_luku );
    oikein = tarkista_luku( );

    while( FALSE == oikein )
        {
        i++;
        anna_vihje( );
	    printf( " Arvaa uudelleen luku väliltä 1-100. \n" );
	    printf( "\n Luku: " );
    	scanf( "%d", &user_luku );
        oikein = tarkista_luku( );
        }

    printf( "\n ARVASIT OIKEIN! oikea luku oli %d\n", oikea_luku );
    printf( "\n Käytit yhteensä %d arvausta!\n", i );

	return 0;
	}

int arvonta( )
    {
    int luku = 0;
    time_t t;
   
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    luku = rand( ) % 100;

    return luku;
    }

bool tarkista_luku()
    {
    if ( user_luku == oikea_luku )
        {
        return TRUE;
        }
    else
        {
        return FALSE;
        }
    }

void anna_vihje()
    {
    if ( user_luku > oikea_luku )
        {
        printf("\n pienempi luku tarvis olla.\n");
        if ( ( user_luku - oikea_luku ) > 30 )
            {
            printf(" kaukana ollaan vielä oikeasta arvauksesta\n");
            }
        else if ( ( user_luku - oikea_luku ) > 10)
            {
            printf(" nyt alkaa olla lähellä!\n");
            }
        else if ( 5 < ( user_luku - oikea_luku ) && ( user_luku - oikea_luku ) < 10 )
            {
            printf(" polttaa, polttaa!\n");
            }
        else
            {
            printf(" vielä kerran?\n");
            }
        }
    else if ( oikea_luku > user_luku )
        {
        printf("\n suurempi luku tarvis olla.\n");
        if ( 30 < ( oikea_luku - user_luku ) )
            {
            printf(" kaukana ollaan vielä oikeasta arvauksesta\n");
            }
        else if ( ( oikea_luku - user_luku ) > 10)
            {
            printf(" nyt alkaa olla lähellä!\n");
            }
        else if ( 5 < ( oikea_luku - user_luku ) && ( oikea_luku - user_luku ) < 10 )
            {
            printf(" polttaa, polttaa!\n");
            }
        else
            {
            printf(" vielä kerran?\n");
            }
        }
    }
