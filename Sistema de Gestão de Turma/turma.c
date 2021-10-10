#include <stdio.h>
#include <stdlib.h> /* free */
#include <string.h> /* strcmp */
#include "aluno.h" /* aluno_cria - aluno_matricula - aluno_imprime - aluno_media
                      aluno_nota1 - aluno_nota2 - aluno_nota3 - aluno_edita
                      aluno_nome */
#include "turma.h"

struct no{
    Aluno* a;
    struct no* prox;
};


/**
* Função:turma_cria
* Descrição: função que cria uma turma vazia
* Parâmetros: nada
* Retorno: NULL para criar a turma vazia
**/
Turma turma_cria(void){
    return NULL;
}

/**
* Função:turma_carrega
* Descrição: função que carrega dados de alunos
*            que estão cadastrados em um arquivo
*            passando esses dados para uma lista
*            que representa uma turma
*            A turma está recebendo os alunos
*            já em orden alfabetica dos nomes
* Parâmetros: Ponteiro para o arquivo
* Retorno: turma com alunos inseridos
**/
Turma turma_carrega(FILE* fp){

    Turma tur = turma_cria();
    char linha[151],nome[101], mat[9];
    float n1,n2,n3;

    while(fgets(linha,150,fp) != NULL){
        sscanf(linha,"%100[^\t]\t%8[^\t]\t%f\t%f\t%f",nome,mat,&n1,&n2,&n3);
        Aluno* alu = aluno_cria(nome,mat,n1,n2,n3);
        tur = turma_insere(tur,alu);
    }
    return tur;
}

/**
* Função:turma_insere
* Descrição: função que insere alunos na turma
*            mantendo a turma com os nomes ordenados alfabeticamente
* Parâmetros: turma, aluno
* Retorno: turma ordenada
**/
Turma turma_insere(Turma turma, Aluno* aluno){
        No* alu = (No*) malloc(sizeof(No));
        alu->a = aluno;

        No* ant = NULL;
        Turma p = turma;
        while(p != NULL && (strcmp(aluno_nome(aluno),aluno_nome(p->a))>0)){
            ant = p;
            p = p->prox;
        }
        if(ant == NULL){
            alu->prox = turma;
            turma= alu;
        }else{
            ant->prox = alu;
            alu->prox = p;
        }
        return turma;
}

/**
* Função:turma_busca
* Descrição: dado a turma e uma matricula valida a
*            função retorna o nó no qual se encontra
*            o aluno com essa matricula
* Parâmetros: turma, matricula
* Retorno: nó
**/
No* turma_busca(Turma turma, char* matricula){
    No* t = turma;
    while(t != NULL){
        if(strcmp(aluno_matricula(t->a),matricula) == 0)
            return t;
        t = t->prox;
    }
    return NULL;
}

/**
* Função:turma_remove
* Descrição: dado a turma e uma matricula valida a
*            função retorna remove o nó no qual se
*            encontra o aluno com essa matricula
* Parâmetros: turma, matricula
* Retorno: turma atualizada
**/
Turma turma_remove(Turma turma, char* matricula){
    Turma ant = NULL;
    Turma aluno = turma;
    while(aluno!=NULL && strcmp(aluno_matricula(aluno->a), matricula) != 0){
        ant = aluno;
        aluno = aluno->prox;
    }

    if(aluno == NULL)
        return turma;

    if(ant==NULL)
        turma = aluno->prox;
    else
        ant->prox = aluno->prox;
    free(aluno);
    return turma;
}

/**
* Função:turma_edita
* Descrição: dado um nó, nome e notas
*            a função atualiza os dados desse nó
* Parâmetros: nó, nome, nota1, nota2, nota3
* Retorno: nada
**/
void turma_edita(No* no, char* nome, float nota1, float nota2, float nota3){
    aluno_edita(no->a,nome,nota1,nota2,nota3);
}

/**
* Função:turma_imprime
* Descrição: dado uma turma a função imprime
*            os alunos que estão cadastrados,
*            Obs.: Se não tover aluno, imprime
*            mensagem avisando
* Parâmetros: turma
* Retorno: nada
**/
void turma_imprime(Turma turma){
        Turma aux = turma;
        if(aux == NULL){
            printf("Turma nao possui nenhum aluno cadastrado!\n");
        }else{
            printf("DADOS DOS ALUNOS DA TURMA:");
            while(aux != NULL){
                aluno_imprime(aux->a);
                aux = aux->prox;
            }
        }
}

/**
* Função:turma_media
* Descrição: dado uma turma a função
*            calcula a media dos alunos
*            que estão cadastrados e a retorna
*            Obs.: Se não tiver aluno a função retorna -1
* Parâmetros: turma
* Retorno: media
**/
float turma_media(Turma turma){
    Turma t = turma;
    int n = 0;
    float acm = 0.0f;
    while(t != NULL){
        acm += aluno_media(t->a);
        n++;
        t = t->prox;
    }
    if(!n)
        return -1;
    return (acm/n);
}

/**
* Função:turma_salva
* Descrição: dado uma turma e o ponteiro para
*            o arquivo de saida, a função
*            salva os dados da turma no arquivo
* Parâmetros: turma
* Retorno: media
**/
void turma_salva(FILE* fp, Turma turma){
    Turma t = turma;
    while(t != NULL){
        fprintf(fp,"%s\t\t%s\t\t%.2f\t%.2f\t%.2f\n",aluno_nome(t->a),aluno_matricula(t->a),
                aluno_nota1(t->a),aluno_nota2(t->a),aluno_nota3(t->a));
        t = t->prox;
    }
}
