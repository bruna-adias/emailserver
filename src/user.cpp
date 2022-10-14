#include "user.hpp"

/**
 * @brief Construct a new User:: User object
 * 
 */
User::User(){
    proximo = NULL;
    caixadeentrada = new Caixa();
};

/**
 * @brief Destroy the User:: User object
 * 
 */
User::~User(){};

/**
 * @brief Chama a função leitura da caixa de entrada.
 * 
 * @return string Texto do email.
 */
string User::leremail(){
    return caixadeentrada->leitura();
};

/**
 * @brief Chama a função receber da caixa de entrada.
 * 
 * @param prioridade Prioridade do email a ser recebido.
 * @param mensagem Texto do email a ser recebido.
 */
void User::receberemail(int prioridade, string mensagem){
    caixadeentrada->receber(prioridade, mensagem);
};

/**
 * @brief Construct a new User:: User object
 * 
 * @param id Identificador do usuário.
 */
User::User(int id){
    this->id = id;
    this->proximo = NULL;
    caixadeentrada = new Caixa();
}