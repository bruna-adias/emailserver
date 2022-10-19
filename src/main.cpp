#include "registro.h"
#include <string.h>

int main(){
    Registro Registro;
    FILE* arquivo = fopen("../input.txt", "rt");

    if(arquivo == NULL){
        cout << "Arquivo não encontrado" << endl;
        return -1;
    }

    while(!feof(arquivo)){
        char comando[20];
        fscanf(arquivo, "%s", comando);

        if(strcmp(comando, "CADASTRA") == 0){
            int IDacriar;
            fscanf(arquivo, " %d", &IDacriar);
            Registro.criaruser(IDacriar);
        }

        else if(strcmp(comando, "REMOVE") == 0){
            int IDaremover;
            fscanf(arquivo, " %d", &IDaremover);
            Registro.deletaruser(IDaremover);
        }
       
            else if(strcmp(comando, "ENTREGA") == 0){
                int IDaenviar;
                int prioridade;
               
                fscanf(arquivo, " %d %d", &IDaenviar, &prioridade);
                char palavra[20] = "";

                string mensagem = "";
                fscanf(arquivo, " %s", palavra);
                while(strcmp(palavra, "FIM") != 0){
                    mensagem += palavra;
                    fscanf(arquivo, " %s", palavra);
                    
                    if(strcmp(palavra, "FIM") != 0)
                        mensagem += " ";
                }

                Registro.enviarmensagem(IDaenviar, prioridade, mensagem);
            }

                else if(strcmp(comando, "CONSULTA") == 0){
                    int ID;
                    fscanf(arquivo, " %d", &ID);
                    Registro.lermensagem(ID);
                }
   
    }

}