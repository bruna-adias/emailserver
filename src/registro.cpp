#include "registro.h"

/**
 * @brief Construct a new Registro:: Registro object
 * 
 */
Registro::Registro(){
    primeiro = NULL;
};


/**
 * @brief Destroy the Registro:: Registro object
 * 
 */
Registro::~Registro(){
    while(primeiro != NULL){
        User* aux = primeiro;
        primeiro = primeiro->proximo;
        delete aux;
    }
};


/**
 * @brief Cria um usuário e insere na ordem descrescente em relação ao ID. Se o ID já existir o usuário 
 * não é inserido e é printado no terminal uma mensagem de erro.
 * 
 * @details Inicialmente cria um usuário e depois verifica se existe um usuário na primeira posição.
 * Se não existir, ele atribui a primeira posição a um usuário recém criado e, se existir ele verifica
 * primeiro se o ID a ser inserido é maior que o ID da primeira posição, se for ele posiciona o novo 
 * usuário na primeira posição, se não ele percorre a lista até encontrar a posição em que o ID do
 * próximo usuário é menor que o ID do usuário a ser inserido e insere nessa nova posição.
 * 
 * @param id identificador do usuário.
 */
void Registro::criaruser(int id){
    User* usuario = new User(id);
    if (primeiro == NULL){
        primeiro = usuario;
        cout << "OK: CONTA " << id << " CADASTRADA"<< endl;
    }

    else {
        if (id > primeiro->id){
            usuario->proximo = primeiro;
            primeiro = usuario;
            cout << "OK: CONTA " << id << " CADASTRADA"<< endl;
    }
    else{
        User* aux = primeiro;
        while(aux->proximo != NULL){
            if(aux->id == id){
                cout << "ERRO: CONTA " << id << " JA EXISTENTE" << endl;
                return;
            }

            if(aux->proximo->id < id)
                break;
            
            aux = aux->proximo;
        }
        usuario->proximo=aux->proximo;
        aux->proximo=usuario;
        cout << "OK: CONTA " << id << " CADASTRADA"<< endl;

    }
}
};

/**
 * @brief Deleta o usuário com o ID passado como parametro. Se o ID não existir, retorna e printa
 * uma mensagem de erro.
 * 
 * @details Percorre a lista até encontrar a posição em que o ID da próxima posição é igual ao ID
 * passado e faz com que essa posição aponte para a posição seguinte a posição do ID a ser removido.
 * 
 * @param id identificador do usuário.
 */
void Registro::deletaruser(int id){
    User* aux = primeiro;
    if(aux->id==id){
        primeiro=aux->proximo;
        cout << "OK: CONTA " << id <<" REMOVIDA" << endl;
        return;
    }

    while(aux->proximo != NULL){
        if(aux->proximo->id==id){
            aux->proximo=aux->proximo->proximo;
            cout << "OK: CONTA " << id <<" REMOVIDA" << endl;
            return;
        }

        if(aux->proximo->id < id){
            cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl; 
            return;
        }

        aux = aux->proximo;

    }
};

/**
 * @brief Chama a função receber da caixa de entrada do usuário que contém o ID passado como parametro.
 * 
 * @details Percorre a lista até encontrar o usuário que possui o ID passado como parametro,
 * e chama a função receber da caixa de entrada dele com os parametros referentes ao email a ser enviado.
 * 
 * @param id identificador do usuário a receber email.
 * @param prioridade prioridade do email a ser enviado.
 * @param mensagem texto do email a ser enviado.
 */
void Registro::enviarmensagem(int id, int prioridade, string mensagem){
    User* aux = primeiro;
    while(aux->proximo != NULL){

        if(aux->id==id){
            aux->caixadeentrada->receber(prioridade, mensagem);
            cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << endl;
            return;
        }

        if(aux->proximo->id < id){
            cout << "ERRO: CONTA " << id << "NAO EXISTE" << endl; 
            return;
        }

        aux = aux->proximo;
    }

    if(aux->id==id){
            aux->caixadeentrada->receber(prioridade, mensagem);
            cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << endl;
            return;
    }

};

/**
 * @brief Chama a função leitura da caixa de entrada do usuário referente ao ID passado como parametro.
 * 
 * @details Percorre a lista até encontrar o usuário que possui o ID passado como parametro,
 * e chama a função leitura da caixa de entrada dele.
 * 
 * @param id identificador do usuário.
 */
void Registro::lermensagem(int id){
    if(primeiro == NULL){
        cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl; 
        return;
    }

    User* aux = primeiro;
    while(aux->proximo != NULL){
        if(aux->id == id){
            cout << "CONSULTA " << id << ": ";
            cout << aux->caixadeentrada->leitura() << endl;
            return;
        }

        if(aux->proximo->id < id){
            cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl; 
            return;
        }


        aux = aux->proximo;
    }

    if(aux->id == id){
            cout << "CONSULTA " << id << ": ";
            cout << aux->caixadeentrada->leitura() << endl;
            return;
    }

};
 
