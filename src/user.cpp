#include "user.hpp"

User::User(){
    proximo = NULL;
    caixadeentrada = new Caixa();
};

User::~User(){};

string User::leremail(){
    return caixadeentrada->leitura();
};

void User::receberemail(int prioridade, string mensagem){
    caixadeentrada->receber(prioridade, mensagem);
};

User::User(int id){
    this->id = id;
    this->proximo = NULL;
    caixadeentrada = new Caixa();
}