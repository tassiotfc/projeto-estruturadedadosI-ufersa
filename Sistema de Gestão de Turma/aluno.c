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
* Fun��o:aluno_cria
* Descri��o: aloca  dinamicamente  uma  estrutura  do  tipo  Aluno,
*            configurando as suas informa��es com valores passados
*            por par�metro
* Par�metros: matricula, nota1, nota 2, nota 3
* Retorno: estrutura do aluno alocada
**/
Aluno*  aluno_cria(char* nome,char* matricula,float nota1,float nota2,float nota3){
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));
    if(a == NULL){
        printf("Espa�o insuficiente!");
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
* Fun��o:aluno_imprime
* Descri��o: imprimir aluno
* Par�metros: aluno
* Retorno:nada
**/
void aluno_imprime(Aluno* aluno){
    printf("\nNome: %s",aluno->nome);
    printf("\nMatricula: %s",aluno->mat);
    printf("\nNotas: %.2f - %.2f - %.2f",aluno->n1,aluno->n2,aluno->n3);
    printf("\nMedia: %.2f\n",aluno_media(aluno));
}

/**
* Fun��o:aluno_edita
* Descri��o: edita os dados de um aluno
* Par�metros: aluno, nome, nota1, nota 2, nota 3
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
* Fun��o:aluno_nome
* Descri��o: dado um registro aluno a fun��o
*            retorna o nome do aluno
* Par�metros: *aluno
* Retorno: nome do aluno
**/
char* aluno_nome(Aluno* aluno){
    return aluno->nome;
}

/**
* Fun��o:aluno_matricula
* Descri��o: dado um registro aluno a fun��o
*            retorna a matricula do aluno
* Par�metros: *aluno
* Retorno: matricula do aluno
**/
char* aluno_matricula(Aluno* aluno){
    return aluno->mat;
}

/**
* Fun��o:aluno_nota1
* Descri��o: dado um registro aluno a fun��o
*            retorna a nota1 do aluno
* Par�metros: *aluno
* Retorno: nota1 do aluno
**/
float aluno_nota1(Aluno* aluno){
    return aluno->n1;
}

/**
* Fun��o:aluno_nota2
* Descri��o: dado um registro aluno a fun��o
*            retorna a nota2 do aluno
* Par�metros: *aluno
* Retorno: nota2 do aluno
**/
float aluno_nota2(Aluno* aluno){
    return aluno->n2;
}

/**
* Fun��o:aluno_nota3
* Descri��o: dado um registro aluno a fun��o
*            retorna a nota3 do aluno
* Par�metros: *aluno
* Retorno: nota3 do aluno
**/
float aluno_nota3(Aluno* aluno){
    return aluno->n3;
}

/**
* Fun��o:aluno_media
* Descri��o: dado um registro aluno a fun��o
*            retorna a media do aluno
* Par�metros: *aluno
* Retorno: media do aluno
**/
float aluno_media(Aluno* aluno){
    aluno->med = (aluno->n1 + aluno->n2 + aluno->n3)/3;
    return aluno->med;
}

/**
* Fun��o:aluno_libera
* Descri��o: dado um registro aluno a fun��o
*            libera esse registro
* Par�metros: *aluno
* Retorno: nada
**/
void aluno_libera(Aluno* aluno){
    free(aluno);
}


