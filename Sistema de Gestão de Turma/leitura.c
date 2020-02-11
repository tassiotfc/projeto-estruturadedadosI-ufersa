#include <stdio.h>
#include <string.h> /* strlen */
#include <ctype.h> /* isdigit */
#include "leitura.h"
#include "interacao.h" /* le_string - limpa_buffer - le_double */
#include "aluno.h" /*CARACTERES_EM_MATRICULA*/

/**
* Fun��o: valida_nome
* Descri��o: recebe um caracter e verifica se
*            n�o � um n�mero, se for retorna 0
* Par�metros: caracter
* Retorno: 0 ou 1
**/
int valida_nome(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z') || c == ' ');
}

/**
* Fun��o: le_nome
* Descri��o: le um nome, usando as fun��es:
*            le_string e fun��o valida_nome
* Par�metros: nada
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
* Fun��o: valida_matricula
* Descri��o: a incrementa i at� encotrar uma letra
* Par�metros: string matricula
* Retorno: o valor de i
**/
int valida_matricula(char* mat){
	int i = 0;
	while(isdigit(mat[i]))
	    i++;
	return i;
}

/**
* Fun��o: le_matricula
* Descri��o: le uma matricula usando le_string e
*            validando com valida matricula
* Par�metros: nada
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
* Fun��o: le_nota
* Descri��o: le uma nota e valida a mesma,
*            obrigando o us�rio digitar nota
*            >=0 e <=10
* Par�metros: nada
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
