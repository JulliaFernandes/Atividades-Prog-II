#include "FilaPessoa.hpp"

using namespace std;

int main(){
	int op = 0;
	FilaPessoa* fp = new FilaPessoa();
	FilaPessoa* prioridade = new FilaPessoa();
	Pessoa* novo;
	string nome;
	Pessoa* p1;
	//Pessoa* p =  fp-> getPrimeiro();.
	Pessoa* p;
	long long int cpf;
	int pri, aux = 0, error, error2, aux2=0, contador = 0, error3, aux3 = 0, cont = 0;

	do{
		do{
			error = 0;
			cout << "\n\t BEM VINDO " << endl;
			cout << "\n[1] Inserir Pessoa" << endl;
			cout << "[2] Remover Pessoa" << endl;
			cout << "[3] Imprimir Pessoas" << endl;
			cout << "[4] Status da fila" << endl;
			cout << "[0] Sair" << endl;
			cin >> op;

			if(cin.fail()){
				cout << "\nDIGITE SOMENTE NUMERO" << endl;
				error = 1;
				cin.clear();
				cin.ignore(80, '\n');
			}
		}while(error == 1);
        
	
		switch(op){
			case 1:
				aux2 = 0;
				p = fp -> getPrimeiro();
				p1 = prioridade -> getPrimeiro();

				cin.ignore();
				cout << "Digite seu nome:" << endl;
				getline(cin, nome);
				do{
					error2 = 0;
					cout << "Digite seu CPF: " << endl;
					cin >> cpf;

					if(cin.fail()){
						cout << "\nDIGITE SOMENTE NUMERO" << endl;
						error2 = 1;
						cin.clear();
						cin.ignore(80, '\n');
					}
				}while(error2 == 1);

				while(p){
					if((p -> getCPF() == cpf)){
						cout << "\nCPF JA CADASTRADO" << endl;
						aux2 = 1;
					}
					p = p -> getProximo();
				}

				while(p1){
					if(p1 -> getCPF() == cpf){
						cout << "\nCPF JA CADASTRADO" << endl;
						aux2 = 1;
					}
					p1 = p1 -> getProximo();
				}

				if(aux2 == 0){
					do{
						error3 = 0;
						cout << "Voce possui prioridade?" << endl;
						cout << "[1]-Sim \n[2]-Não" << endl;  
						cin >> pri;
						if(cin.fail()){
							cout << "\nDIGITE SOMENTE NUMERO" << endl;
							error3 = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
					}while(error3 == 1);

					novo = new Pessoa(nome, cpf);

					if(pri == 1){
						prioridade -> CadastrarPessoas(novo);
						cout << "Existem " << prioridade-> getItens() -1 << " pessoas na sua frente" << endl; 
					}
					else if(pri == 2){
						fp -> CadastrarPessoas(novo);
						aux = prioridade -> getItens();
						aux += fp -> getItens() -1;
						cout << "Existem " << aux << " pessoas na sua frente" << endl;
					}
					else{
						cout << "NUMEROS DIGITADOS DIFERENTES DE 1 E 2" << endl;
					}
				}
				break;

			case 2:
				cont = ((fp -> getItens() + prioridade -> getItens()) -1);
				if( (prioridade -> vazia()) && (fp -> vazia())){
					cout << "[FILA VAZIA]" << endl;
				}
				else if(prioridade -> vazia()){
					fp -> Retirar();
				}
				else{
					prioridade -> Retirar();
				}
				cout << "Restam " << cont << " pessoas a serem atendidas" << endl;

				break;

			case 3:

				if( (prioridade -> vazia()) && (fp -> vazia())){
					cout << "\n[FILA VAZIA]" << endl;
				}
				else{
					cout << "\t[FILA DE PESSOAS]" << endl;
					prioridade -> ImprimirPessoas();
					fp -> ImprimirPessoas();	
				}
				break;
			
			case 4:
				if( (prioridade -> vazia()) && (fp -> vazia())){
					cout << "\n[FILA VAZIA]" << endl;
				}
				else{
					contador = fp -> getItens() + prioridade -> getItens();
					cout << "Existem " << contador << " pessoas na fila" << endl;
				}
				break;
		}
	}while(op != 0);
}