#include <stdio.h>

void creer_fichier(){
//créer un fichier "donnees.txt" et rentre les valeurs lu au clavier dans celui-ci
	FILE * fichier;
	int entier=0;
	char nom_fichier[20];
	
	printf("Veuillez donner le nom du fichier\n");
	scanf("%s", nom_fichier);
	fichier = fopen(nom_fichier,"w"); 
	if(fichier){
		while(entier!=-1){
			printf("Veuillez taper une liste d'entier ");
			scanf("%i", &entier);
			if(entier!=-1){
				fprintf(fichier,"%i ",entier);
			} 			
		}
	}
	fclose(fichier);
}

void afficher_fichier(){
	FILE * fichier;
	int entier;
	char nom_fichier[20];
	
	printf("Veuillez donner le nom du fichier\n");
	scanf("%s", nom_fichier);
	fichier=fopen(nom_fichier,"r");
	if(fichier==NULL){
		printf("Erreur ce fichier n'existe pas");
	}else{
		fscanf(fichier,"%d",&entier);
		while(!feof(fichier)){
			printf("%d ", entier);
			fscanf(fichier,"%d",&entier);	
		}
		fclose(fichier);
	}
	printf("\n");
	
}

int main(){

	creer_fichier();
	afficher_fichier();

	return 0;
}
