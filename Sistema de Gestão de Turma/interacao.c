#include <stdio.h>
#include <stdlib.h> /* strtod */
#include <string.h> /* strlen - strcpy */
#include <ctype.h>  /* isalpha */
#include <stdarg.h>
#include "interacao.h"

/**
* Função:apresenta_programa
* Descrição: dado uma string a função
*            imprime na saida padrão
* Parâmetros: msg
* Retorno: nada
**/
void apresenta_programa(char* msg){
    printf("%s\n",msg);
}

/**
* Função:mensagem_despedida
* Descrição: dado uma string a função
*            imprime na saida padrão
* Parâmetros: msg
* Retorno: nada
**/
void mensagem_despedida(char* msg){
    printf("\n%s\n",msg);
}

/**
* Função: limpa_tela
* Descrição: função reponsável por
*            limpar a tela
* Parâmetros: nada
* Retorno: nada
**/
void limpa_tela(void){
    system("cls");
}

/**
* Função: limpa_buffer
* Descrição: função que limpa o buffer
*            evitando que alguns bugs
* Parâmetros: nada
* Retorno: nada
**/
void limpa_buffer(void){
	int valorLido;
    do{
        valorLido = getchar();
    }while ((valorLido != '\n') && (valorLido != EOF));
}

/**
* Função: le_opcao
* Descrição: lê uma opção digitada pelo
*            usuário e valida conforme
*            as condições dadas
* Parâmetros: menor_valor, maior_valor
* Retorno: o valor lido e validado
**/
int le_opcao(int menor_valor, int maior_valor){
    int op;
        while(1){
            printf("\nDigite sua opcao: ");
            op=getchar();
            if(op>=menor_valor && op<=maior_valor){
                limpa_buffer;
                break;
            }else{
                printf("\nOpcao Invalida. Tente Novamente");
                printf("\nA opcao deve estar entre %c e %c. \n",menor_valor, maior_valor);
                limpa_buffer();
            }
        }
	return op;
}

/**
* Função: le_string
* Descrição: lê uma string, calcula seu tamanho,
*            aloca uma string do tamanho da
*            string lida e transfere a string
*            lida para esta alocada
* Parâmetros: nada
* Retorno: a string lida
**/
char* le_string(void){
    char aux[101];
    scanf(" %100[^\n]", aux);
	int n = strlen(aux); //calcula a quantidade de caracteres inseridos na string
    char* string = (char*) malloc((n+1)*sizeof(char));
    strcpy(string, aux);
    return string;
}

/**
* Função: le_double
* Descrição: le uma string usando a le_string,
*            verifica se tem letra na string,
*            converte a string para um numero,
*            armazena esse valor em uma var do tipo float
* Parâmetros: msg
* Retorno: nada
**/
double le_double(void){
    double v;
    char* str = le_string();
	int i = 0;
	while(str[i] != '\0'){
        if(isalpha(str[i]) != 0) //retorna 0 se caracter é numero
            return -1;
        i++;
	}
	v = strtod(str, NULL); //Converte pra a string até encontrar um caracter
	return v;
}

/**
* Função: apresenta_menu
* Descrição: dado a quant. de itens do menu,
*            a menor opção e argumento strings,
*            a função exibe o menu na tela
* Parâmetros: n_itens, menor_opção e argumentos
* Retorno: nada
**/
void apresenta_menu(int n_itens, int menor_opcao, ...){
	int i;
	va_list argumentos;
	va_start(argumentos,menor_opcao);
	for(i = 0;i<n_itens;++i){
		printf("%c-%s\n",menor_opcao++,va_arg(argumentos, char *));
	}
	va_end(argumentos);
}
