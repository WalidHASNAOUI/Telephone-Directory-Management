#include "linked_liste.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tab[5] ; 
	tab[0] = ajouter_zone(39 , "zagora") ;
	tab[1]= ajouter_zone(33 , "agadir") ;
	tab[2]= ajouter_zone(32 , "essaou") ;

	/*printf("Nom de zone N=[%d] est ::> [%s] \n" , rep->code , rep->nom_zone) ;
	printf("Nom de zone N=[%d] est ::> [%s] \n" , rep->suivant->code , rep->suivant->nom_zone);*/

	//-----add_a_new_client-------
	tab[0] = ajouter_abonne(661833484 , "ahmed_ha" , "mly_rachid" , 39) ;
	tab[1] = ajouter_abonne(662415629 , "hajar_hs" , "hy_elkodss" , 39) ;
	tab[2]= ajouter_abonne(642054980 , "hassan_e" , "hy_elhouda" , 33) ;
	tab[3]= ajouter_abonne(661040506 , "omar_elf" , "hy_tassila" , 33) ;
	tab[4] = ajouter_abonne(642097088 , "walid_hs" , "el_ghazoua" , 32) ;

	afficher(rep) ;

	printf("\t\t\t\t-------Cherchrer_Numero-------\n") ;
	tab[0] = enregistrer_abonne("omar_elf" , 33) ;
	printf("\t\t\t\tle resultas est ::>|%d|\n" , tab[0]) ;
	printf("\t\t\t\t------------------------------\n") ;

	printf("\t\t\t\t-------Enlever_un_client------\n") ;
	tab[1] = enlever_abonne(662415629) ;
	printf("\t\t\t\tle resultas est ::> |%d|\n" , tab[1]) ;
	printf("\t\t\t\t------------------------------\n") ;

	printf("\t\t\t\t-------Enlever_un_zone------\n") ;
	tab[2] = enlever_zone(33) ;
	printf("\t\t\t\tle resultas est ::> |%d|\n" , tab[2]) ;
	afficher(rep) ;
	printf("\t\t\t\t------------------------------\n") ;

	return 0 ;
	
}

