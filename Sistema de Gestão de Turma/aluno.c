#include <stdio.h>
#include <stdlib.h> /* free - exit */
#include <string.h> /* strcpy */
#include "aluno.h"

struct aluno{
    char nome[101];
    char mat[CARACTERES_EM_MATRICULA+1];
    float n1, n2, n3, med;
};

/**
* Função:aluno_cria
* Descrição: aloca  dinamicamente  uma  estrutura  do  tipo  Aluno,
*            configurando as suas informações com valores passados
*            por parâmetro
* Parâmetros: matricula, nota1, nota 2, nota 3
* Retorno: estrutura do aluno alocada
**/
Aluno*  aluno_cria(char* nome,char* matricula,float nota1,float nota2,float nota3){
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));
    if(a == NULL){
        printf("Espaço insuficiente!");
        exit(1);
    }
    strcpy(a->nome,nome);
    strcpy(a->mat,matricula);
    a->n1 = nota1;
    a->n2 = nota2;
    a->n3 = nota3;
    a->med = aluno_media(a);
    return a;
}

/**
* Função:aluno_imprime
* Descrição: imprimir aluno
* Parâmetros: aluno
* Retorno:nada
**/
void aluno_imprime(Aluno* aluno){
    printf("\nNome: %s",aluno->nome);
    printf("\nMatricula: %s",aluno->mat);
    printf("\nNotas: %.2f - %.2f - %.2f",aluno->n1,aluno->n2,aluno->n3);
    printf("\nMedia: %.2f\n",aluno_media(aluno));
}

/**
* Função:aluno_edita
* Descrição: edita os dados de um aluno
* Parâmetros: aluno, nome, nota1, nota 2, nota 3
* Retorno: nada
**/
void aluno_edita(Aluno* aluno, char* nome, float nota1, float nota2, float nota3){
    strcpy(aluno->nome,nome);
    aluno->n1 = nota1;
    aluno->n2 = nota2;
    aluno->n3 = nota3;
    aluno->med = aluno_media(aluno);
}

/**
* Função:aluno_nome
* Descrição: dado um registro aluno a função
*            retorna o nome do aluno
* Parâmetros: *aluno
* Retorno: nome do aluno
**/
char* aluno_nome(Aluno* aluno){
    return aluno->nome;
}

/**
* Função:aluno_matricula
* Descrição: dado um registro aluno a função
*            retorna a matricula do aluno
* Parâmetros: *aluno
* Retorno: matricula do aluno
**/
char* aluno_matricula(Aluno* aluno){
    return aluno->mat;
}

/**
* Função:aluno_nota1
* Descrição: dado um registro aluno a função
*            retorna a nota1 do aluno
* Parâmetros: *aluno
* Retorno: nota1 do aluno
**/
float aluno_nota1(Aluno* aluno){
    return aluno->n1;
}

/**
* Função:aluno_nota2
* Descrição: dado um registro aluno a função
*            retorna a nota2 do aluno
* Parâmetros: *aluno
* Retorno: nota2 do aluno
**/
float aluno_nota2(Aluno* aluno){
    return aluno->n2;
}

/**
* Função:aluno_nota3
* Descrição: dado um registro aluno a função
*            retorna a nota3 do aluno
* Parâmetros: *aluno
* Retorno: nota3 do aluno
**/
float aluno_nota3(Aluno* aluno){
    return aluno->n3;
}

/**
* Função:aluno_media
* Descrição: dado um registro aluno a função
*            retorna a media do aluno
* Parâmetros: *aluno
* Retorno: media do aluno
**/
float aluno_media(Aluno* aluno){
    aluno->med = (aluno->n1 + aluno->n2 + aluno->n3)/3;
    return aluno->med;
}

/**
* Função:aluno_libera
* Descrição: dado um registro aluno a função
*            libera esse registro
* Parâmetros: *aluno
* Retorno: nada
**/
void aluno_libera(Aluno* aluno){
    free(aluno);
}


