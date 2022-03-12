#include "linked_liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

rep_tele *rep = NULL ;

//-----initialise_repertoire-----
rep_tele* initialiser_rep(void)
{
	return NULL ;
}

//-------return_the_adresse_of_previous_area----
rep_tele* adresse_avant(rep_tele *adr)
{
	rep_tele *temp = initialiser_rep() ;

	if(rep == initialiser_rep())
	{
		printf("Erreur :: repertoire est vide!!\n") ;
		return NULL ;
	}else{
		if(rep == adr) // if user give us adress of the first zone [there's not any area before] 
		{
			printf("Erreur :: aucun element element detecter!!\n");
			printf("Atention ::: [vous me donne adresse de 1er element!!]\n") ;
			return NULL ;
		}else{
			temp = rep ;
			while(temp->suivant != adr)
			{
				temp = temp->suivant ;
			}

			return adr ;
		}
	}
}

//-----create_new_area-----
rep_tele* creer_zone(int code , char *nom_zone)
{
	rep_tele *zone = initialiser_rep() ;
	zone = (rep_tele *) malloc(sizeof(rep_tele)) ;

	if(zone == initialiser_rep()) 
	{
		printf("Erreur :: Manque de memoire!!\n") ; 
		return NULL ;
	}else{
		zone->nom_zone = (char *) malloc(strlen(nom_zone)*sizeof(char)) ;
		if(zone->nom_zone == NULL) 
		{
			printf("Erreur :: Manque de memoire!!\n") ;
			return NULL ;
		}else{
			strcpy(zone->nom_zone , nom_zone) ;
			zone->code = code ;
			zone->debut_abonne = NULL ;
			zone->fin_abonne = NULL ;
			zone->suivant = NULL ;
			zone->nb_abonnes = 0 ;
			return zone ;
		}
	}
}

//------create_new_client----------
abonne* creer_abonne(int num_tel , char *nom_abonne , char *adresse)
{
	abonne *abn = NULL ;
	abn = (abonne *) malloc(sizeof(abonne)) ;

	if(abn == NULL)
	{
		printf("Erreur :: |Manque de memoire!!|\n") ;
		return NULL ;
	}else{
		abn->nom_abonne = (char *) malloc(strlen(nom_abonne)*sizeof(char)) ;
		abn->adresse = (char *) malloc(strlen(adresse)*sizeof(char)) ;

		if((abn->nom_abonne == NULL)||(abn->adresse == NULL))
		{
			printf("Erreur :: Manque de memoire!!\n") ;
			return NULL ;
		}else{
			abn->num_tel = num_tel ; 
			strcpy(abn->nom_abonne , nom_abonne) ;
			strcpy(abn->adresse , adresse) ;
			abn->precedent = NULL ;
			abn->suivant = NULL ;
			return abn ; 
		}		
	}
}

//------add_new_area_inside_our_repertorie------
int ajouter_zone(int code_zone , char *nom_zone) 
{
	rep_tele *p = creer_zone(code_zone , nom_zone) ;
	rep_tele *temp = initialiser_rep() ;

	if(p == NULL)
	{
		return -1 ;
	}else{
		if(rep == initialiser_rep())
		{
			rep = p ; 
		}else{
			temp = rep ;
			while(temp->suivant != NULL)
			{
				temp = temp->suivant ;
			}
			temp->suivant = p ;
		}
		return 1 ;
	}
}

//----------add_new_client_inside_an_area------
int ajouter_abonne(int num_tel , char *nom_abonne , char *adresse , int code_zone) 
{
	rep_tele *temp = NULL ;
	abonne *abn = NULL ;

	if(rep == initialiser_rep()) 
	{
		printf("Erreur :: |le repertoire est vide!!|\n") ;
		return -1 ;
	}else{
		temp = rep ;
		while((temp->code != code_zone)&&(temp != NULL))
		{
			temp = temp->suivant ;
		}

		if(temp == NULL)
		{
			printf("Erreur :: |zone introvable!!|\n") ;
			return -1 ;
		}else{
			abn = creer_abonne(num_tel , nom_abonne , adresse) ;
			if(abn == NULL)
			{
				return -1 ;
			}else{
				if(temp->debut_abonne == NULL)
				{
					temp->debut_abonne = abn ;
					temp->fin_abonne = abn ;
				}else{
					temp->fin_abonne->suivant = abn ;
					abn->precedent = temp->fin_abonne ;
					temp->fin_abonne = temp->fin_abonne->suivant ;
				}
				temp->nb_abonnes++ ;
				return 	1 ;
			}
		}
	}
}

//--------cheking_if_client_exits_inside_an_area_or_not----------
int enregistrer_abonne(char *nom , int code_zone) 
{
	rep_tele *temp = initialiser_rep() ;
	abonne *temp_abn = NULL ;

	if(rep == NULL)
	{
		printf("Erreur :: le repertoire est vide !!\n") ;
		return -1 ;
	}else{
		temp = rep ;
		while((temp->code != code_zone)&&(temp != NULL))
		{
			temp = temp->suivant ;
		}

		if(temp == NULL)
		{
			printf("Erreur :: |zone introvable!!|\n") ;
			return -1 ;
		}else{
			temp_abn = temp->debut_abonne ;

			while((temp_abn != NULL)&&(strcmpi(temp_abn->nom_abonne,nom)!=0))
			{
				temp_abn = temp_abn->suivant ;
			}

			if(temp_abn == NULL)
			{
				printf("Erreur :: |client introvable!!|\n") ;
				return -1 ;
			}else{
				return temp_abn->num_tel ;
			}
		}
	}
}

//------Remove_client_from_our_liste----------
int enlever_abonne(int numero) 
{
	rep_tele *temp = NULL ;
	abonne *temp_abn = NULL ;
	int i ;

	if(rep == initialiser_rep())
	{
		printf("Erreur :: |le repertoire est vide!!|\n") ;
		return -1 ;
	}else{
		temp = rep ;

		while(temp != NULL)
		{
			temp_abn = temp->debut_abonne ;
			i = 0 ;

			while((temp_abn != NULL)&&(temp_abn->num_tel != numero))
			{
				i++ ;
				temp_abn = temp_abn->suivant ;
			}

			if(temp_abn != NULL) //we found our client (temp_abn)
				break ;

			temp = temp->suivant ;  /// we did not fond him\her in this area (That's why we should go to next area)
		}

		if(temp == NULL) //we do not find client
		{
			printf("Erreur :: |client introvable!!|\n") ;
			return -1 ;
		}else{ // we find it
			if(i == 0) //if client is [the first one] who connect to this area
			{
				temp->debut_abonne = temp->debut_abonne->suivant ;
				temp->debut_abonne->precedent = NULL ;
				free(temp_abn) ;
				temp_abn = NULL ;
			}else{
				if(temp_abn->suivant == NULL) //if client is the [last one] who conect to this area
				{
					temp->fin_abonne = temp->fin_abonne->precedent ;
					temp->fin_abonne->suivant = NULL ;
					free(temp_abn) ;
					temp_abn = NULL ;
				}else{ // no first no lasta [middle]
					temp_abn->precedent->suivant = temp_abn->suivant ;
					temp_abn->suivant->precedent = temp_abn->precedent ;
					free(temp_abn) ;
					temp_abn = NULL ;
				}
			}
			temp->nb_abonnes-- ;
			return 1 ; 
		}
	}
}

//------drop_area(zone)_from_our_repertury---
int enlever_zone(int code_zone) 
{
	rep_tele *temp = initialiser_rep() ;
	rep_tele *temp_1 = initialiser_rep() ;
 	int i ;

	if(rep == NULL)
	{
		printf("Erreur :: [Repertoire est vide!!]\n") ;
		return -1 ;
 	}else{
 		temp = rep ;
 		i = 0 ; //it used to determine the position of our area(zone) if it's in [front , midlle , end]

 		while((temp != NULL)&&(temp->code != code_zone)) //find oour specifc area(zone)
 		{
 			i++ ;
 			temp = temp->suivant ;
 		}

 		if(temp == NULL)
 		{
 			printf("Erreur :: |zone introvable!!| \n") ;
 			return -1 ;
 		}else{ 
 			
 			if(temp->nb_abonnes != 0) //if area(zone) has some clients (abonments) ::> to remove them
 			{
 				while(temp->debut_abonne->suivant != NULL) 
 				{
 					temp->debut_abonne = temp->debut_abonne->suivant ;
 					free(temp->debut_abonne->precedent) ;
 					temp->debut_abonne->precedent = NULL ;
 				}

 				free(temp->debut_abonne) ;
 				temp->debut_abonne = NULL ;
 				temp->fin_abonne = NULL ;
 				temp->nb_abonnes = 0 ; 
 			}

 			if(i == 0) // about area(zone)'s position 
 			{
 				rep = rep->suivant ;
 				free(temp) ;
 				temp = NULL ;
 			}else{
 				if(temp->suivant == NULL) // the end
 				{
 					temp_1 = adresse_avant(temp) ;
 					temp_1->suivant = NULL ;
 					free(temp) ;
 					temp = NULL ;
 				}else{ // the middle 
 					temp_1 = adresse_avant(temp) ; // return adress of previouse area(zone) 
 					temp_1->suivant = temp->suivant ;
 					free(temp) ;
 					temp = NULL ;
 				}
 			}
 			return 1 ;
 		}
 	}
}


//------------display_our_main_programe----------
void main_menu(void)
{
	int choix ;

	printf("\t\t\t\t+-----------------------------------------------+\n") ;
	printf("\t\t\t\t|                   MAIN_MENU                   |\n") ;
	printf("\t\t\t\t+-----------------------------------------------+\n") ;
	printf("\t\t\t\t|1->Chercher le numero de abonne .              |\n") ;
	printf("\t\t\t\t|2->Enlever un abonne .                         |\n") ;
	printf("\t\t\t\t|3->Enlever une zone .                          |\n") ;
	printf("\t\t\t\t|4->Afficher le repertoire telephonique .       |\n") ;
	printf("\t\t\t\t|5->Quiter le programe .                        |\n") ;
	printf("\t\t\t\t+-----------------------------------------------+\n") ;

}

//-------Display_our_repertory-----
void afficher(rep_tele *rep1)
{
	rep_tele *temp = initialiser_rep() ;

	if(rep == NULL)
	{
		printf("Erreur :: repertoire est vide [Rien a afficher]\n") ;
	}else{
		temp = rep ;
		while(temp != NULL)
		{
			printf("\t\t\t\t+-----------------------------+\n") ;
			printf("\t\t\t\t|            %s           |\n", temp->nom_zone) ;
			printf("\t\t\t\t+-----------------------------+\n") ;
			while(temp->debut_abonne != NULL)
			{
				printf("\t\t\t\t|    +-----------------+      |\n") ;
				printf("\t\t\t\t|    |      %s   |      |\n", temp->debut_abonne->nom_abonne) ;
				printf("\t\t\t\t|    +-----------------+      |\n") ;
				printf("\t\t\t\t|    |%d        |      |\n" ,temp->debut_abonne->num_tel );
				printf("\t\t\t\t|    |%s       |      |\n" ,temp->debut_abonne->adresse );
				printf("\t\t\t\t|    +-----------------+      |\n") ;
				temp->debut_abonne = temp->debut_abonne->suivant ;
			}
			printf("\t\t\t\t+-----------------------------+\n") ;
			temp = temp->suivant ;
		}
		temp = NULL ;
	}
}