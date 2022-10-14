#include "mensagem.hpp"

/**
 * @brief Construct a new Mensagem:: Mensagem object
 * 
 */
Mensagem::Mensagem(){
    proximo = NULL;
    prioridade = -1;
    mensagem = "";
};

/**
 * @brief Construct a new Mensagem:: Mensagem object
 * 
 * @param prioridade Prioridade do email a ser criado.
 * @param mensagem Texto do email a ser criado.
 */
Mensagem::Mensagem(int prioridade, string mensagem){
    this->proximo = NULL;
    this->mensagem = mensagem;
    this->prioridade = prioridade;
};

/**
 * @brief Destroy the Mensagem:: Mensagem object
 * 
 */
Mensagem::~Mensagem(){};