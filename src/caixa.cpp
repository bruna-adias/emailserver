#include "caixa.hpp"

/**
 * @brief Construct a new Caixa:: Caixa object
 * 
 */

Caixa::Caixa(){
    primeiro = NULL;
};

/**
 * @brief Destroy the Caixa:: Caixa object
 * 
 */

Caixa::~Caixa(){
    while(primeiro != NULL){
        Mensagem* aux = primeiro;
        primeiro = primeiro->proximo;
        delete aux;
    }
};

/**
 * @brief Ler o primeiro email da lista e remove depois de lido.
 * 
 * @details Verifica se existe um email na primeira posição e se não existir retorna a 
 * string de caixa vazia. Se existir, retorna a mensagem do primeiro e o remove.
 * 
 * @return string mensagem da primeira posição.
 */
string Caixa::leitura(){
    if(primeiro == NULL){
        string caixavazia = "CAIXA DE ENTRADA VAZIA";
        return caixavazia;
    }

    string lerprimeiro = primeiro->mensagem;
    Mensagem* aux = primeiro;
    primeiro = primeiro->proximo;
    delete aux;
    return lerprimeiro;
};

/**
 * @brief Cria um novo tipo email e adiciona na última posição referente a prioridade.
 * 
 * @details Um novo ponteiro para a mensagem e após isso verifica se a primeira posição já existe, 
 * se não existir, faz com que a primeira posição aponte para essa mensagem criada. Se existir,
 * verifica primeiro se a prioridade da mensagem a ser inserida é maior do que a prioridade do primeiro
 * email da lista. Se for, altera o primeiro para o email recem criado e, se não for, percorre a lista
 * até o último email da prioridade maior já inserida e insere após ele.
 * 
 * @param prioridade Prioridade do email a ser inserido.
 * @param mensagem Texto do email a ser inserido.
 */
void Caixa::receber(int prioridade, string mensagem){
    Mensagem* email = new Mensagem(prioridade, mensagem);
    if (this->primeiro == NULL)
        this->primeiro = email;

    else {
        if (prioridade > primeiro->prioridade){
            email->proximo = primeiro;
            primeiro = email;
    }
    else{
        Mensagem* aux = primeiro;
        while(aux->proximo != NULL){
            if(aux->proximo->prioridade<prioridade)
                break;
            
            aux = aux->proximo;
        }
        email->proximo=aux->proximo;
        aux->proximo=email;

    }
};
};