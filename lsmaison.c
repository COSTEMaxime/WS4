#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main (int argc, char** argv)	{

	struct dirent *contenuRepertoire;
	DIR *repertoire;

	if (argc == 2)	{
		repertoire = opendir(argv[1]);
		if (repertoire == NULL)	{
			printf("Erreur lors de l'ouverture du repertoire");
			return -1;
		}

		while ((contenuRepertoire = readdir(repertoire)) != NULL){
			printf("Nom :  %s | ID : %d\n", contenuRepertoire->d_name, contenuRepertoire->d_ino);
		}
		closedir(repertoire);
	}
	else	{
		printf("Nombre d'arguments incorrect");
	}
	return 0;
}
