#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cadastrados=0;
    typedef struct telefone{
        int DDD;
        int numero;
    }telefone;

    typedef struct nascimento{
        int dia;
        int mes;
        int ano;
    }nascimento;

    typedef struct contato{
        char nome[50];
        char email[50];
        telefone numeroTelefone;
        nascimento data;
        char observaçao [50];
    }contato;

void cadastro(contato *agenda, int qtdCont){
    int i;
    if(qtdCont == cadastrados){
        agenda=(contato*)realloc(agenda, (sizeof(contato) *qtdCont+1));
        qtdCont++;
    }

        getc(stdin);
        printf("\nNome do contato:\n");
        fgets(agenda[cadastrados].nome, 50, stdin);
        agenda[cadastrados].nome[strlen(agenda[cadastrados].nome)-1]= '\0';

        printf("\nEmail de contato\n");
        fgets(agenda[cadastrados].email, 50, stdin);
        agenda[cadastrados].email[strlen(agenda[cadastrados].email)-1]= '\0';

        printf("\nTelefone de contato\n");
        scanf("%d", &agenda[cadastrados].numeroTelefone.numero);

        printf("\nDDD do telefone\n");
        scanf("%d", &agenda[cadastrados].numeroTelefone.DDD);

        printf("\nDia do aniversario:\n");
        scanf("%d", &agenda[cadastrados].data.dia);

        printf("\nMes do aniversario:\n");
        scanf("%d", &agenda[cadastrados].data.mes);

        printf("\nAno do aniversario:\n");
        scanf("%d", &agenda[cadastrados].data.ano);

        getc(stdin);
        printf("\nDigite uma observaçao se desejar:\n");
        fgets(agenda[cadastrados].observaçao, 50, stdin);
        agenda[cadastrados].observaçao[strlen(agenda[cadastrados].observaçao)-1]= '\0';

        printf("\nNOME: %s\n", agenda[cadastrados].nome);
        printf("\nEMAIL: %s\n", agenda[cadastrados].email);
        printf("\nTELEFONE: %d %d\n", agenda[cadastrados].numeroTelefone.DDD, agenda[cadastrados].numeroTelefone.numero);
        printf("\nDATA DE NASCIMENTO: %d/%d/%d\n", agenda[cadastrados].data.dia, agenda[cadastrados].data.mes, agenda[cadastrados].data.ano);
        printf("\nOBSERVAÇAO: %s\n",agenda[cadastrados].observaçao);
        cadastrados++;
}

void excluir(contato *agenda, int qtdCont){
    int i, contatoExcluido, j;
    if(cadastrados == 0){
        printf("\nNenhum contato cadastrado ate o momento. Cadastre algum contato primeiro\n");
    }
    else{
        for(i=0; i<cadastrados; i++){
            printf("\n[%d]",i);
            printf("\nNOME: %s\n", agenda[i].nome);
            printf("\nEMAIL: %s\n", agenda[i].email);
            printf("\nTELEFONE: %d %d\n", agenda[i].numeroTelefone.DDD, agenda[i].numeroTelefone.numero);
            printf("\nDATA DE NASCIMENTO: %d/%d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("\nOBSERVAÇAO: %s\n",agenda[i].observaçao);
    }

    printf("\nDigite qual contato deseja excluir:\n");
    scanf("%d", &contatoExcluido);

    for(i=0; i<cadastrados; i++){
			if(i == contatoExcluido){
				if(agenda[i+1].numeroTelefone.DDD != -1){
					for(j=contatoExcluido; j<cadastrados; j++){
						agenda[j].numeroTelefone.DDD=agenda[j+1].numeroTelefone.DDD;
						agenda[j].numeroTelefone.numero=agenda[j+1].numeroTelefone.numero;
                        agenda[j].data.dia = agenda[j+1].data.dia;
                        agenda[j].data.mes = agenda[j+1].data.mes;
                        agenda[j].data.ano = agenda[j+1].data.ano;
						strcpy(agenda[j].nome, agenda[j+1].nome);
						strcpy(agenda[j].email, agenda[j+1].email);
                        strcpy(agenda[j].observaçao, agenda[j+1].observaçao);
					}
				}
				else{
					agenda[i].numeroTelefone.DDD = -1;
				}
			}
		}
		cadastrados--;
		printf("\nQuantidade de contatos %d\n", cadastrados);
    }
}

void pesquisar(contato *agenda, int qtdCont){
    char comp[50], i, cont=0;
    getc(stdin);
    printf("\nDigite o nome que deseja buscar:\n");
    fgets(comp, 50, stdin);
    comp[strlen(comp)-1]='\0';

    for(i=0; i<cadastrados; i++){
        if(strcmp(comp,agenda[i].nome) == 0){
            printf("\nContato encontrado\n");
            printf("\nNOME: %s\n", agenda[i].nome);
            printf("\nEMAIL: %s\n", agenda[i].email);
            printf("\nTELEFONE: %d %d\n", agenda[i].numeroTelefone.DDD, agenda[i].numeroTelefone.numero);
            printf("\nDATA DE NASCIMENTO: %d/%d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("\nOBSERVAÇAO: %s\n",agenda[i].observaçao);
            cont = 1;
        }
        if(cont == 0){
            printf("\nNenhum contato cadastrado nesse nome\n");
        }
    }
}

void alterar(contato *agenda, int qtdCont){
    int i, contatoAlterado;
    if(cadastrados == 0){
        printf("\nNenhum contato cadastrado ate o momento. Cadastre algum contato primeiro\n");
    }
    else{
        for(i=0; i<cadastrados; i++){
            printf("\n[%d]",i);
            printf("\nNOME: %s\n", agenda[i].nome);
            printf("\nEMAIL: %s\n", agenda[i].email);
            printf("\nTELEFONE: %d %d\n", agenda[i].numeroTelefone.DDD, agenda[i].numeroTelefone.numero);
            printf("\nDATA DE NASCIMENTO: %d/%d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("\nOBSERVAÇAO: %s\n",agenda[i].observaçao);
        }
    }

    printf("\nDigite qual contato deseja alterar:\n");
    scanf("%d", &contatoAlterado);

    for(i=0; i<cadastrados; i++){
			if(i == contatoAlterado){
                getc(stdin);
                printf("\nNome do contato:\n");
                fgets(agenda[i].nome, 50, stdin);
                agenda[i].nome[strlen(agenda[i].nome)-1]= '\0';

                printf("\nEmail de contato\n");
                fgets(agenda[i].email, 50, stdin);
                agenda[i].email[strlen(agenda[i].email)-1]= '\0';

                printf("\nTelefone de contato\n");
                scanf("%d", &agenda[i].numeroTelefone.numero);

                printf("\nDDD do telefone\n");
                scanf("%d", &agenda[i].numeroTelefone.DDD);

                printf("\nDia do aniversario:\n");
                scanf("%d", &agenda[i].data.dia);

                printf("\nMes do aniversario:\n");
                scanf("%d", &agenda[i].data.mes);

                printf("\nAno do aniversario:\n");
                scanf("%d", &agenda[i].data.ano);

                getc(stdin);
                printf("\nDigite uma observaçao se desejar:\n");
                fgets(agenda[i].observaçao, 50, stdin);
                agenda[i].observaçao[strlen(agenda[i].observaçao)-1]= '\0';

                printf("\nNOME: %s\n", agenda[i].nome);
                printf("\nEMAIL: %s\n", agenda[i].email);
                printf("\nTELEFONE: %d %d\n", agenda[i].numeroTelefone.DDD, agenda[i].numeroTelefone.numero);
                printf("\nDATA DE NASCIMENTO: %d/%d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
                printf("\nOBSERVAÇAO: %s\n",agenda[i].observaçao);
            }
    }

}

void imprimir(contato *agenda, int qtdCont){
    int i;
	if(cadastro == 0){
		printf("\nNenhum carro cadastrado ate o momento. Cadastre algum carro primeiro\n");
	}

    else{
		for(i=0; i<cadastrados; i++){
            printf("\n[%d]",i);
            printf("\nNOME: %s\n", agenda[i].nome);
            printf("\nEMAIL: %s\n", agenda[i].email);
            printf("\nTELEFONE: %d %d\n", agenda[i].numeroTelefone.DDD, agenda[i].numeroTelefone.numero);
            printf("\nDATA DE NASCIMENTO: %d/%d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("\nOBSERVAÇAO: %s\n",agenda[i].observaçao);
        }
    }

}

int main(){
    int qtdCont, op=-1, i;
    contato *agenda;
    
    printf("\nDigite quntos contatos deseja adicionar na sua agenda:\n");
    scanf("%d", &qtdCont);

    agenda=(contato*)malloc(qtdCont*(sizeof(contato)));

    for(i=0; i<qtdCont; i++){
        agenda[i].numeroTelefone.DDD = -1;
    }

    while(op!= 0){
        printf("\nMENU\n");
        printf("\n0- Sair");
        printf("\n1-Cadastrar contato");
        printf("\n2-Excluir contato");
        printf("\n3-Alterar contato");
        printf("\n4-Pesquisar contato pelo nome");
        printf("\n5-Imprimir os contatos\n");
        scanf("%d", &op);

        switch (op){
            case 1:
            cadastro(agenda, qtdCont);
            break;

            case 2:
            excluir(agenda, qtdCont);
            break;

            case 3:
            alterar(agenda, qtdCont);
            break;

            case 4:
            pesquisar(agenda, qtdCont);
            break;

            case 5:
            imprimir(agenda, qtdCont);
            break;

        }
    }

}