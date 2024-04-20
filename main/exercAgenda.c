#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"

int main (void){
  
  int escolha, i, escolhaAlt, escolhaExc;
  int tam = 10;
  int qntdAgenda = 0;
  int qntdImpress = 0;
  int numUsuarios = 0;

  agendaUsuarios agendUsu[tam];

  do{
  	printf("==== Agenda ====\n\n");
	printf("==== Limite 10 espacos ====\n\n");
  	lista(agendUsu, qntdAgenda, numUsuarios);
  	menu(escolha);
	scanf("%i", &escolha);

  	switch (escolha){
		case 1:
	  	  grava(agendUsu, &qntdAgenda, &qntdImpress, &numUsuarios);
	  	  break;
		case 2:
		  system("cls");
		  if (numUsuarios == 0){
			printf("Nao ha usuarios na agenda!\n ");
			system("pause");
			system("cls");
		  } else {
		  	printf("=== USUARIOS ===");
		  	lista(agendUsu, qntdAgenda, numUsuarios);
		  	printf("\nDigite o usuario que quer alterar: ");
		  	scanf("%i", &escolhaAlt);
	  	  	altera(escolhaAlt, agendUsu);
		  }
	  	  break;
		case 3:
		  system("cls");
		  if (numUsuarios == 0){
			printf("Nao ha usuarios na agenda!\n");
			system("pause");
			system("cls");
		  } else {
		  	printf("=== USUARIOS ===\n\n");
		  	lista(agendUsu, qntdAgenda, numUsuarios);
		  	printf("\nDigite o usuario que quer excluir: ");
		  	scanf("%i", &escolhaExc);
	  	  	apaga(escolhaExc, agendUsu, &qntdAgenda, &qntdImpress, &numUsuarios);
	  	  }
		  break;
		case 4:
		  printf("Obrigado por usar a agenda!");
		  return 0;
		default:
		  printf("Essa opção não existe!");
		  escolha = 0;
		  break;
  	}
  }while(escolha < 1 || escolha < 4);

  return 0;
}