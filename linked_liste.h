#ifndef __linked__
#define __linked__

//------------
typedef struct elementabonne
{
	int num_tel ;
	char *nom_abonne ;
	char *adresse ;
	struct elementabonne *precedent ;
	struct elementabonne *suivant ;
}abonne ;

//------------
typedef struct zone
{
	int code ;
	char *nom_zone ;
	abonne *debut_abonne ;
	abonne *fin_abonne ;
	int nb_abonnes ;
	struct zone *suivant ;
}rep_tele ;

extern rep_tele *rep;

//--------------
rep_tele* initialiser_rep(void) ;
rep_tele* adresse_avant(rep_tele *adr) ;
rep_tele* creer_zone(int code , char *nom_zone) ;
abonne* creer_abonne(int num_tel , char *nom_abonne , char *adresse) ;
int ajouter_zone(int code_zone , char *nom_zone) ;
int ajouter_abonne(int num_tel , char *nom_abonne , char *adresse , int code_zone) ;
int enregistrer_abonne(char *nom , int code_zone) ;
int enlever_abonne(int numero) ;
int enlever_zone(int code_zone) ;
void main_menu(void) ;
void afficher(rep_tele *rep1) ;
 
#endif