#include <stdio.h>
#include <stdlib.h> /* strtod */
#include <string.h> /* strlen - strcpy */
#include <ctype.h>  /* isalpha */
#include <stdarg.h>
#include "interacao.h"

/**
* Fun��o:apresenta_programa
* Descri��o: dado uma string a fun��o
*            imprime na saida padr�o
* Par�metros: msg
* Retorno: nada
**/
void apresenta_programa(char* msg){
    printf("%s\n",msg);
}

/**
* Fun��o:mensagem_despedida
* Descri��o: dado uma string a fun��o
*            imprime na saida padr�o
* Par�metros: msg
* Retorno: nada
**/
void mensagem_despedida(char* msg){
    printf("\n%s\n",msg);
}

/**
* Fun��o: limpa_tela
* Descri��o: fun��o repons�vel por
*            limpar a tela
* Par�metros: nada
* Retorno: nada
**/
void limpa_tela(void){
    system("cls");
}

/**
* Fun��o: limpa_buffer
* Descri��o: fun��o que limpa o buffer
*            evitando que alguns bugs
* Par�metros: nada
* Retorno: nada
**/
void limpa_buffer(void){
	int valorLido;
    do{
        valorLido = getchar();
    }while ((valorLido != '\n') && (valorLido != EOF));
}

/**
* Fun��o: le_opcao
* Descri��o: l� uma op��o digitada pelo
*            usu�rio e valida conforme
*            as condi��es dadas
* Par�metros: menor_valor, maior_valor
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
* Fun��o: le_string
* Descri��o: l� uma string, calcula seu tamanho,
*            aloca uma string do tamanho da
*            string lida e transfere a string
*            lida para esta alocada
* Par�metros: nada
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
* Fun��o: le_double
* Descri��o: le uma string usando a le_string,
*            verifica se tem letra na string,
*            converte a string para um numero,
*            armazena esse valor em uma var do tipo float
* Par�metros: msg
* Retorno: nada
**/
double le_double(void){
    double v;
    char* str = le_string();
	int i = 0;
	while(str[i] != '\0'){
        if(isalpha(str[i]) != 0) //retorna 0 se caracter � numero
            return -1;
        i++;
	}
	v = strtod(str, NULL); //Converte pra a string at� encontrar um caracter
	return v;
}

/**
* Fun��o: apresenta_menu
* Descri��o: dado a quant. de itens do menu,
*            a menor op��o e argumento strings,
*            a fun��o exibe o menu na tela
* Par�metros: n_itens, menor_op��o e argumentos
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
