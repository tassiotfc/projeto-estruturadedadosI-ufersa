#include <stdio.h>
#include <string.h> /* strlen */
#include <ctype.h> /* isdigit */
#include "leitura.h"
#include "interacao.h" /* le_string - limpa_buffer - le_double */
#include "aluno.h" /*CARACTERES_EM_MATRICULA*/

/**
* Função: valida_nome
* Descrição: recebe um caracter e verifica se
*            não é um número, se for retorna 0
* Parâmetros: caracter
* Retorno: 0 ou 1
**/
int valida_nome(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z') || c == ' ');
}

/**
* Função: le_nome
* Descrição: le um nome, usando as funções:
*            le_string e função valida_nome
* Parâmetros: nada
* Retorno: nome lido e validado
**/
char* le_nome(void){
    char* nome;
    int t_nome;
    printf("Digite um nome: ");
    nome = le_string();
    t_nome = strlen(nome);

    int i = 0;
    int r = 0;
    while(nome[i] != '\0'){
        r += valida_nome(nome[i]);
        i++;
    }

    while(r != t_nome){
        i = 0;
        r = 0;
        limpa_buffer();
        printf("Entrada incorreta.Digite um nome: ");
        nome = le_string();
        t_nome = strlen(nome);
        while(nome[i] != '\0'){
            r += valida_nome(nome[i]);
            i++;
        }
    }
    return nome;
}

/**
* Função: valida_matricula
* Descrição: a incrementa i até encotrar uma letra
* Parâmetros: string matricula
* Retorno: o valor de i
**/
int valida_matricula(char* mat){
	int i = 0;
	while(isdigit(mat[i]))
	    i++;
	return i;
}

/**
* Função: le_matricula
* Descrição: le uma matricula usando le_string e
*            validando com valida matricula
* Parâmetros: nada
* Retorno: matricula lida e validada
**/
char* le_matricula(void){
    char* mat;
    int t_dig;
    printf("Digite uma matricula com %d digitos: ", CARACTERES_EM_MATRICULA);
    mat = le_string();
    t_dig = valida_matricula(mat);
    while(t_dig != CARACTERES_EM_MATRICULA){
        limpa_buffer();
        printf("Entrada incorreta.Digite uma matricula com %d digitos: ",CARACTERES_EM_MATRICULA);
        mat = le_string();
        t_dig = valida_matricula(mat);
    }
    return mat;
}

/**
* Função: le_nota
* Descrição: le uma nota e valida a mesma,
*            obrigando o usário digitar nota
*            >=0 e <=10
* Parâmetros: nada
* Retorno: nota lida e validada
**/
float le_nota(void){
    float nota;
    printf("Digite um nota entre 0 e 10: ");
    nota = le_double();
    while((nota<0 || nota>10) || (nota == -1)){
        limpa_buffer();
        printf("Entrada incorreta.Digite um valor inteiro entre 0 e 10:");
        nota = le_double();
    }
    limpa_buffer();
    return nota;
}
