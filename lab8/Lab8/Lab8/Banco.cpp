#include "Banco.hpp"
#include <iostream>

using namespace std;

int NumConta = 1000;

Banco :: Banco(){
    this -> lc = new ListaContaSemLimite();
    this -> lcc = new ListaContaCorrente();
    this -> lcp = new ListaContaPoupanca();

}
Banco :: Banco(ListaContaSemLimite* _lc, ListaContaCorrente* _lcc, ListaContaPoupanca* _lcp){
    this -> lc = new ListaContaSemLimite();
    this -> lcc = new ListaContaCorrente();
    this -> lcp = new ListaContaPoupanca();
}

void Banco :: setListaContaSemLimite(ListaContaSemLimite* _lc){
    this -> lc = _lc;
}
ListaContaSemLimite* Banco :: getListaContaSemLimite(){
    return this -> lc;
}

void Banco :: setListaContaCorrente(ListaContaCorrente* _lcc){
    this -> lcc = _lcc;
}
ListaContaCorrente* Banco :: getListaContaCorrente(){
    return this -> lcc;
}

void Banco :: setListaContaPoupanca(ListaContaPoupanca* _lcp){
    this -> lcp = _lcp;
}
ListaContaPoupanca* Banco :: getListaContaPoupanca(){
    return this -> lcp;
}

void Banco :: cadastroC(){
    string nome;
    //ContaSemLimite* c = getListaContaSemLimite()-> getPrimeiro();

    cin.ignore();
    cout << "\nDigite seu nome:" << endl;
    getline(cin, nome);


    cout << "\n\t!ATENCAO!" << endl;
    cout << "\nNUMERO DA SUA CONTA:" << NumConta << endl;
    cout << "\n--------------------------------------------------------------------------------"<< endl;

        ContaSemLimite* novaC = new ContaSemLimite(nome, NumConta);
        lc->inserirFinal(novaC);

    NumConta++;
}

void Banco :: cadastroCC(){
    string nome, saldo;
    double limite, limiteAux = 0;
    int error;
    //ContaCorrente* cc = getPrimeiro();

        cin.ignore();
        cout << "\nDigite seu nome:" << endl;
        getline(cin, nome);
        do{
            error = 0;
            cout << "\nDigite seu limite:" << endl;
            cin >> limite;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO" << endl;
                error = 1;
                cin.clear();
                cin.ignore(80, '\n');
            }
        }while(error == 1);
        
        limiteAux = limite;

        cout << "\n\t!ATENCAO!" << endl;
        cout << "\nNUMERO DA SUA CONTA:" << NumConta << endl;
        cout << "\n--------------------------------------------------------------------------------"<< endl;
        ContaCorrente* novaCC = new ContaCorrente(nome, NumConta, limite, limiteAux);

        NumConta++;

        lcc -> inserirFinal(novaCC);

}

void Banco :: cadastroCP(){
    string nome, aniversario;
    //ContaPoupanca* cp = getPrimeiro();

        cin.ignore();
        cout << "\nDigite seu nome:" << endl;
        getline(cin, nome);
        cout << "\nDigte seu aniversario no formato (XX/XX/XXXX):" << endl;
        getline(cin, aniversario);

        cout << "\n\t!ATENCAO!" << endl;
        cout << "\nNUMERO DA SUA CONTA:" << NumConta << endl;
        cout << "\n--------------------------------------------------------------------------------"<< endl;

        ContaPoupanca* novaCP = new ContaPoupanca();
        novaCP -> setNome(nome);
        novaCP -> setAniversario(aniversario);
        novaCP -> setNumeroDaConta(NumConta);
        NumConta++;
        
        lcp -> inserirFinal(novaCP);
}



void Banco :: depositoC(){
    int Nconta, aux = 0, error, error2;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaSemLimite* c = getListaContaSemLimite() -> getPrimeiro();

    if(getListaContaSemLimite() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            do{
                error = 0;
                cout << "\nDigite o numero da sua conta: " << endl;
                cin >> Nconta;
                if(cin.fail()){
                    cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                    error = 1;
                    cin.clear();
                    cin.ignore(80,'\n');
                }
            }while(error == 1);

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                do{
                    error2 = 0;
                    cout << "\nDigite o valor do deposito" << endl;
                    cin >> valor;
                    if(cin.fail()){
                        cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                        error2 = 1;
                        cin.clear();
                        cin.ignore(80,'\n');
                    }
                }while(error2 == 1);
                
                
                cin.ignore();
                cout << "\nDigite a data do deposito: " << endl;
                getline(cin, data);
                cout << "\nDescrição: " << endl;
                getline(cin, descricao);

                c -> setSaldo(c -> getSaldo() + valor);

                string _valorString (to_string(valor));

                transacao.append("Data: ");
                transacao.append(data);
                transacao.append(" | ");
                transacao.append("Deposito: +");
                transacao.append(_valorString);
                transacao.append(" | ");
                transacao.append("Descrição: ");
                transacao.append(descricao);
                transacao.append("\n");

                c -> setTransacao(c -> getTransacao() + transacao);
                //c -> deposito(valor);
                aux = 1;
                break;
            }
            c = c -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}

void Banco :: depositoCC(){
    int Nconta, aux = 0, cont = 0, auxSaldo = 0, auxSL = 0, error, error2;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaCorrente* cc = lcc -> getPrimeiro();


    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(cc){
            if(cc -> getNumeroDaConta() == Nconta){
                do{
                    error2 = 0;
                    cout << "\nDigite o valor do deposito" << endl;
                    cin >> valor;
                    if(cin.fail()){
                        cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                        error2 = 1;
                        cin.clear();
                        cin.ignore(80,'\n');
                    }
                }while(error2 == 1);

                cc -> deposito(valor);

                    if(cc->getLimiteAux() > cc->getLimite()){
                        if((cc->getLimite() + valor) < cc->getLimiteAux()){
                            cc->setSaldo(0);
                            cc->setLimite(cc->getLimite() + valor);
                        }
                        else if((cc->getLimite() + valor) == cc->getLimiteAux()){
                            cc->setSaldo(0);
                            cc->setLimite(cc->getLimiteAux());
                        }
                        else{
                            cc->setSaldo((cc->getLimite() + valor) - cc->getLimiteAux());
                            cc->setLimite(cc->getLimiteAux());
                        }
                    }
                    cont = 1;
                    break;
            }
            cc = cc -> getProximo();
        }
        /*else if(aux == 0){
            cout << "\nO valor do deposito esta maior que o limite" << endl;
        }*/
    }
    if(cont == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
    }
} 

/*void Banco :: depositoCC(){
    int Nconta, aux = 0, cont = 0;
    double valor;
    ContaCorrente* c = lcc -> getPrimeiro();


    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                cout << "\nDigite o valor do deposito" << endl;
                cin >> valor;
                cont = 1;
                if(c -> getLimite() >= valor){
                    c -> deposito(valor);
                    aux = 1;
                    break;
                }
            }
            c = c -> getProximo();
        }
        if(cont == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(aux == 0){
            cout << "\nO valor do deposito esta maior que o limite" << endl;
        }

    }
} */

void Banco :: depositoCP(){
    int Nconta, aux = 0, error, error2;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaPoupanca* cp = getListaContaPoupanca() -> getPrimeiro();

    if(getListaContaPoupanca() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(cp){
            if(cp -> getNumeroDaConta() == Nconta){
                do{
                    error2 = 0;
                    cout << "\nDigite o valor do deposito" << endl;
                    cin >> valor;
                    if(cin.fail()){
                        cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                        error2 = 1;
                        cin.clear();
                        cin.ignore(80,'\n');
                    }
                }while(error2 == 1);

                cin.ignore();
                cout << "\nDigite a data do deposito: " << endl;
                getline(cin, data);
                cout << "\nDescrição: " << endl;
                getline(cin, descricao);

                cp -> setSaldo(cp -> getSaldo() + valor);

                string _valorString (to_string(valor));

                transacao.append("Data: ");
                transacao.append(data);
                transacao.append(" | ");
                transacao.append("Deposito: +");
                transacao.append(_valorString);
                transacao.append(" | ");
                transacao.append("Descrição: ");
                transacao.append(descricao);
                transacao.append("\n");

                cp -> setTransacao(cp -> getTransacao() + transacao);
                aux = 1;
                break;
            }
            cp = cp -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}



void Banco :: extratoC(){
    ContaSemLimite* c = lc -> getPrimeiro();
    int Nconta, aux = 0, error;

    if(getListaContaSemLimite() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                cout << "\n\t[DADOS PESSOAIS]" << endl;
                cout << ">Nome: " << c -> getNome() << endl;
                cout << ">Numero da Conta: " << c -> getNumeroDaConta() << endl;
                cout << ">Saldo: " << c -> getSaldo() << endl;
                cout << ">Transacao: " << endl;
                cout << c -> getTransacao() << endl;
                aux = 1;
                break;
            }
            c = c -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}

void Banco :: extratoCC(){
    ContaCorrente* cc = lcc -> getPrimeiro();
    int Nconta, aux = 0, error;

    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(cc){
            if(cc -> getNumeroDaConta() == Nconta){
                cout << "\n\t[DADOS PESSOAIS]" << endl;
                cout << ">Nome: " << cc -> getNome() << endl;
                cout << ">Numero da Conta: " << cc -> getNumeroDaConta() << endl;
                cout << ">Saldo: " << cc -> getSaldo() << endl;
                cout << ">Limite: " << cc -> getLimite() << endl;
                cout << ">Transacao: " << endl;
                cout << cc -> getTransacao() << endl;
                aux = 1;
                break;
            }
            cc = cc -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}

void Banco :: extratoCP(){
    ContaPoupanca* cp = lcp -> getPrimeiro();
    int Nconta, aux = 0, error;

    if(getListaContaPoupanca() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(cp){
            if(cp -> getNumeroDaConta() == Nconta){
                cout << "\n\t[DADOS PESSOAIS]" << endl;
                cout << ">Nome: " << cp -> getNome() << endl;
                cout << ">Numero da Conta: " << cp -> getNumeroDaConta() << endl;
                cout << ">Saldo: " << cp -> getSaldo() << endl;
                cout << ">Aniversario: " << cp -> getAniversario() << endl;
                cout << ">Transacao: \n"<< endl;
                cout << cp -> getTransacao() << endl;
                aux = 1;
                break;
            }
            cp = cp -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}



void Banco :: retiradaC(){
    int Nconta, aux = 0, auxSaldo = 0, error, error2;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaSemLimite* c = getListaContaSemLimite() -> getPrimeiro();

    if(getListaContaSemLimite() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                aux = 1;
                do{
                    error2 = 0;
                    cout << "\nDigite o valor do saque: " << endl;
                    cin >> valor;
                    if(cin.fail()){
                        cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                        error2 = 1;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }while(error2 == 1);

                if(valor <= c -> getSaldo()){
                    auxSaldo = 1;

                    cin.ignore();
                    cout << "\nDigite a data do saque: " << endl;
                    getline(cin, data);
                    cout << "\nDescrição: " << endl;
                    getline(cin, descricao);

                    c -> setSaldo(c -> getSaldo() - valor);

                    string valorString (to_string(valor));

                    transacao.append("Data: ");
                    transacao.append(data);
                    transacao.append(" | ");
                    transacao.append("Saque: -");
                    transacao.append(valorString);
                    transacao.append(" | ");
                    transacao.append("Descrição: ");
                    transacao.append(descricao);
                    transacao.append("\n");

                    c -> setTransacao(c -> getTransacao() + transacao);
                                    
                                    
                    //c -> retirada(valor);
                    break;
                }
            }
            c = c -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(auxSaldo == 0){
            throw SaqueSemLimite();
        }
    }
}

void Banco :: retiradaCP(){
    int Nconta, aux = 0, auxSaldo = 0, error, error2;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaPoupanca* cp = getListaContaPoupanca() -> getPrimeiro();

    if(getListaContaPoupanca() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(cp){
            if(cp -> getNumeroDaConta() == Nconta){
                aux = 1;
                do{
                    error2 = 0;
                    cout << "\nDigite o valor do saque: " << endl;
                    cin >> valor;
                    if(cin.fail()){
                        cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                        error2 = 1;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }while(error2 == 1);

                if(valor <= cp -> getSaldo()){
                    auxSaldo = 1;

                    cin.ignore();
                    cout << "\nDigite a data do saque: " << endl;
                    getline(cin, data);
                    cout << "\nDescrição: " << endl;
                    getline(cin, descricao);

                    cp -> setSaldo(cp -> getSaldo() - valor);

                    string valorString (to_string(valor));

                    transacao.append("Data: ");
                    transacao.append(data);
                    transacao.append(" | ");
                    transacao.append("Saque: -");
                    transacao.append(valorString);
                    transacao.append(" | ");
                    transacao.append("Descrição: ");
                    transacao.append(descricao);
                    transacao.append("\n");

                    cp -> setTransacao(cp -> getTransacao() + transacao);
                    //cp -> retirada(valor);
                    break;
                }
            }
            cp = cp -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(auxSaldo == 0){
            throw SaqueSemLimite();
        }
    }
}

void Banco :: retiradaCC(){
    int Nconta, aux = 0, auxSaldo = 0, cont = 0, error, error2, aux2 = 0, controle = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaCorrente* cc = getListaContaCorrente() -> getPrimeiro();

    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
        do{
            error = 0;
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;
            if(cin.fail()){
                cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                error = 1;
                cin.clear();
                cin.ignore(80,'\n');
            }
        }while(error == 1);

        while(cc){
            if(cc -> getNumeroDaConta() == Nconta){
                controle = 1;
                do{
                    error2 = 0;
                    cout << "\nDigite o valor do saque: " << endl;
                    cin >> valor;
                    if(cin.fail()){
                        cout << "\nDIGITE UM NUMERO VALIDO"<< endl;
                        error2 = 1;
                        cin.clear();
                        cin.ignore(80, '\n');
                    }
                }while(error2 == 1);
                

                if((cc -> getSaldo() - valor) < 0){
                    if((cc -> getLimite() - valor) < 0){
                        cout << "Impossivel realizar saque. Saldo e limite indisponivel" << endl;
                    }

                    else {
                        cc -> setLimite(cc -> getLimite() - valor + cc -> getSaldo());
                        cc -> setSaldo(0);
                        aux = 1;
                    }
                }
                else{
                    cc -> setSaldo(cc -> getSaldo() - valor);
                    aux  = 1;
                }

                if(aux == 1){
                    cin.ignore();
                    cout << "\nDigite a data do saque: " << endl;
                    getline(cin, data);
                    cout << "\nDescrição: " << endl;
                    getline(cin, descricao);

                    //cc -> setSaldo(cc -> getSaldo() - valor);

                    string valorString (to_string(valor));

                    transacao.append("Data: ");
                    transacao.append(data);
                    transacao.append(" | ");
                    transacao.append("Saque: -");
                    transacao.append(valorString);
                    transacao.append(" | ");
                    transacao.append("Descrição: ");
                    transacao.append(descricao);
                    transacao.append("\n");

                    cc -> setTransacao(cc -> getTransacao() + transacao);
                    //cp -> retirada(valor);
                    aux2 = 1;
                    break;
                }
            }
            cc = cc -> getProximo();
        }
    }
    if(controle == 0){
        cout << "\nNumero de conta nao cadastrado" << endl;
    }

    if(aux2 == 0){
        throw SaqueSemLimite();
    }
}

