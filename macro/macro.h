typedef struct{
  int dia;
  int mes;
  int ano;
} data;

typedef struct{
  data nascimento;
  char nome[40],email[50],tel[45],tipoTel[30];
  int idade;
}agendaUsuarios;

void lista(agendaUsuarios agendUsu[], int qntdAgenda, int numUsuarios){
  int i;
  if (numUsuarios == 0){
	printf("== Agenda vazia!! ==\n\n");
  } else {
  	for (i = 0; i < qntdAgenda; i++){
		printf("\nUsuario %i\n", i);
  		printf("Nome: %s\n", agendUsu[i].nome);
		printf("Email: %s\n", agendUsu[i].email);
		printf("Idade: %i\n", agendUsu[i].idade);
		printf("Data de Nascimento: %i/%i/%i\n", agendUsu[i].nascimento.dia,agendUsu[i].nascimento.mes,agendUsu[i].nascimento.ano);
		printf("Telefone: %s %s\n\n", agendUsu[i].tel, agendUsu[i].tipoTel);
  	}
  }
  return;
}

void menu(){
  printf("=== Menu ===\n\n");
  printf("1 - Inserir um usuario\n");
  printf("2 - Editar um usuario\n");
  printf("3 - Apagar um usuario\n");
  printf("4 - Sair\n");
  printf("Digite uma opcao: ");
  return;
}

void grava(agendaUsuarios agendUsu[], int *qntdAgenda, int *qntdImpress, int *numUsuarios){
  int qntdUsu, i, escolhaTel;
  printf("Quantos usuarios quer adicionar? ");
  scanf("%i", &qntdUsu);
  for(i = 0; i < qntdUsu; i++){
	system("cls");
	printf("==== Inserir Usuarios ====\n\n");
	printf("Nome: ");
  	scanf("%s", &agendUsu[*qntdImpress].nome);
	printf("Idade: ");
	scanf("%i", &agendUsu[*qntdImpress].idade);
	printf("Digite a data de nascimento: \n");
	printf("Dia: ");
	scanf("%i", &agendUsu[*qntdImpress].nascimento.dia);
	printf("Mes: ");
	scanf("%i", &agendUsu[*qntdImpress].nascimento.mes);
	printf("Ano: ");
	scanf("%i", &agendUsu[*qntdImpress].nascimento.ano);
	printf("Email: ");
	scanf("%s", &agendUsu[*qntdImpress].email);
	printf("Numero de telefone: ");
	scanf("%s", &agendUsu[*qntdImpress].tel);
	printf("1- Telefone fixo\n");
	printf("2- Celular\n");
	printf("3- Residencia\n");
	printf("4- Trabalho\n");
	printf("Selecione seu tipo de telefone: ");
	scanf("%i", &escolhaTel);

	switch(escolhaTel){
		case 1:
		  strcpy(agendUsu[*qntdImpress].tipoTel, "Telefone fixo");
		  break;
		case 2:
		  strcpy(agendUsu[*qntdImpress].tipoTel, "Celular");
		  break;
		case 3:
		  strcpy(agendUsu[*qntdImpress].tipoTel, "Residencia");
		  break;
		case 4:
		  strcpy(agendUsu[*qntdImpress].tipoTel, "Trabalho");
		  break;
		default:
		  printf("Escolha inválida! Altere o valor no menu se necessário!");
	}

	(*qntdImpress)++;
	(*numUsuarios)++;
  }
  *qntdAgenda =  *qntdAgenda + qntdUsu;
  return;
}

void altera(int escolhaAlt, agendaUsuarios agendUsu[]){
  
  int alt,escolhaTel;
  printf("Lista de alteracoes: \n");
  printf("1- Nome\n");
  printf("2- Email\n");
  printf("3- Idade\n");
  printf("4- Data de nascimento\n");
  printf("5- Telefone\n");
  printf("6- Tipo do telefone\n");
  printf("Escolha uma alteracao que queria fazer: ");
  scanf("%i", &alt);

  switch(alt){
	case 1:
	  printf("Digite um novo nome: ");
	  scanf("%s", &agendUsu[escolhaAlt].nome);
	  break;
	case 2:
	  printf("Digite um novo email: ");
	  scanf("%s", &agendUsu[escolhaAlt].email);
	  break;
	case 3:
	  printf("Digite uma nova idade: ");
	  scanf("%i", &agendUsu[escolhaAlt].idade);
	  break;
	case 4:
	  printf("Digite uma nova data de nascimento (modelo dd/mm/yyyy): ");
	  printf("Dia: ");
	  scanf("%i", &agendUsu[escolhaAlt].nascimento.dia);
	  printf("Mes: ");
	  scanf("%i", &agendUsu[escolhaAlt].nascimento.mes);
	  printf("Ano: ");
	  scanf("%i", &agendUsu[escolhaAlt].nascimento.ano);
	  break;
	case 5:
	  printf("Digite um novo número de telefone: ");
	  scanf("%s", &agendUsu[escolhaAlt].tel);
	  break;
	case 6:
	  printf("Altere seu tipo de telefone: \n");
	  printf("1- Telefone fixo\n");
	  printf("2- Celular\n");
	  printf("3- Residencia\n");
	  printf("4- Trabalho\n");
	  printf("Selecione seu tipo de telefone: ");
	  scanf("%i", &escolhaTel);

	  switch(escolhaTel){
		case 1:
		  strcpy(agendUsu[escolhaAlt].tipoTel, "Telefone fixo");
		  break;
		case 2:
		  strcpy(agendUsu[escolhaAlt].tipoTel, "Celular");
		  break;
		case 3:
		  strcpy(agendUsu[escolhaAlt].tipoTel, "Residencia");
		  break;
		case 4:
		  strcpy(agendUsu[escolhaAlt].tipoTel, "Trabalho");
		  break;
		default:
		  printf("Escolha inválida! Altere o valor no menu se necessário!");
	  }
	  break;
	default:
	  printf("Escolha inválida! Altere o valor no menu se necessário!");
  }	

  printf("Alteração concluida!!\n");
  system("cls");
  return;
}

void apaga(int escolhaExc, agendaUsuarios agendUsu[], int *qntdAgenda, int *qntdImpress, int *numUsuarios){
  int i;
  strcpy(agendUsu[escolhaExc].nome, "\0");
  strcpy(agendUsu[escolhaExc].email, "\0"); 
  agendUsu[escolhaExc].idade = 0;
  agendUsu[escolhaExc].nascimento.dia = 0;
  agendUsu[escolhaExc].nascimento.mes = 0;
  agendUsu[escolhaExc].nascimento.ano = 0;
  strcpy(agendUsu[escolhaExc].tel, "\0");
  strcpy(agendUsu[escolhaExc].tipoTel, "\0");
  getchar();
  *qntdAgenda = *qntdAgenda - 1;
  *qntdImpress = *qntdImpress - 1;
  
  for (i = *numUsuarios; i < 10; i++){
	int valorDepois = i + 1;
	strcpy(agendUsu[i].nome, agendUsu[valorDepois].nome);
	agendUsu[i].idade = agendUsu[valorDepois].idade;
	agendUsu[i].nascimento.dia = agendUsu[valorDepois].nascimento.dia;
	agendUsu[i].nascimento.mes = agendUsu[valorDepois].nascimento.mes;
	strcpy(agendUsu[i].email, agendUsu[valorDepois].email);
	strcpy(agendUsu[i].tel, agendUsu[valorDepois].tel);
	strcpy(agendUsu[i].tipoTel, agendUsu[valorDepois].tipoTel);
  }
  (*numUsuarios)--;
  return;
}