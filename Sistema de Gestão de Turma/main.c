/******************************************************************************************
UNIVERSIDADE FEDERAL RURAL DO SEMI-ÁRIDO
CURSO: BACHARELADO EM TECNOLOGIA DA INFORMAÇÃO
DISCIPLINA: LABORATÓRIO DE ALGORITMOS E ESTRUTURA DE DADOS I
PROFESSOR: ME. THIAGO PEREIRA RIQUE
DISCENTE: TÁSSIO FERNANDES COSTA
AVALIAÇÃO 3º UNDIDADE: PROJETO - 2016.1 - PROGRAMA PARA MANIPULAÇÃO DE UMA TURMA DE ALUNOS
*******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>  /* exit */
#include <conio.h> /* getch */
#include "aluno.h"
#include "turma.h"
#include "interacao.h"
#include "leitura.h"

#define TITULO_OPCAO1 "Adicionar um aluno na turma"
#define TITULO_OPCAO2 "Remover um aluno da turma"
#define TITULO_OPCAO3 "Modificar um registro de aluno"
#define TITULO_OPCAO4 "Listar todos os alunos da turma"
#define TITULO_OPCAO5 "Imprimir a media da turma"
#define TITULO_OPCAO6 "Sair do programa"

#define N_OPCOES 6
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'

int main()
{
    unsigned char op;
	unsigned int saida=0;
	char* nome;
	char* mat;
    float n1,n2,n3,media;
    Turma turma;
    Aluno* aluno;
    No* aluno_busca;
    FILE* fp;

    fp = fopen("dados.txt","rt");
    if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    turma = turma_carrega(fp);
    apresenta_programa("Cadastro de Aluno [Versao 1.0]. Copyright (c) 2016");
    apresenta_programa("Desenvolvido por: Tassio F.C. Todos os direitos reservados.");
	do{
		printf("\nMENU:\n");
		apresenta_menu(N_OPCOES, OPCAO1,
					  TITULO_OPCAO1,TITULO_OPCAO2,
					  TITULO_OPCAO3,TITULO_OPCAO4,
					  TITULO_OPCAO5,TITULO_OPCAO6);
		op=le_opcao(OPCAO1, OPCAO1+N_OPCOES-1);
		limpa_tela();
		switch(op){
			case OPCAO1:
			    limpa_buffer();
			    printf("Adicionando um aluno na turma...\n\n");
			    mat = le_matricula();
			    while(turma_busca(turma,mat) != NULL){
                    printf("Matricula ja existe!\n");
                    mat = le_matricula();
			    }
			    nome = le_nome();
			    n1 = le_nota();
                n2 = le_nota();
                n3 = le_nota();
                aluno = aluno_cria(nome,mat,n1,n2,n3);
                turma = turma_insere(turma,aluno);
                printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
                limpa_tela();
				break;

			case OPCAO2:
			    limpa_buffer();
			    printf("Removendo um aluno da turma...\n\n");
			    mat = le_matricula();
			    aluno_busca = turma_busca(turma,mat);
			    if(aluno_busca == NULL){
                    printf("Nao existe nenhum aluno com esta matricula na turma!\n");
			    }else{
                    turma = turma_remove(turma,mat);
                    printf("Aluno removido com sucesso!\n");
			    }
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
                limpa_buffer();
                limpa_tela();
				break;

			case OPCAO3:
			    limpa_buffer();
			    printf("Modificando um registro de um aluno...\n\n");
			    mat = le_matricula();
			    aluno_busca = turma_busca(turma,mat);
			    if(aluno_busca == NULL){
                    printf("Matricula nao registrada!\n");
                }
                else{
                    nome = le_nome();
                    n1 = le_nota();
                    n2 = le_nota();
                    n3 = le_nota();
                    turma_edita(aluno_busca,nome,n1,n2,n3);
                }
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
                limpa_buffer();
                limpa_tela();
				break;

			case OPCAO4:
			    limpa_buffer();
			    turma_imprime(turma);

				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
                limpa_tela();
				break;

            case OPCAO5:
                limpa_buffer();
                media = turma_media(turma);
                if(media != -1)
                    printf("\nMedia da turma: %.2f\n",media);
				else
                    printf("\nTurma vazia, logo, nao e possivel calcular media!\n");

				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
                limpa_tela();
				break;

			case OPCAO6:
				saida = 1;
				mensagem_despedida("Encerrando o programa. Ate breve...");
				break;

			default:
				printf("Este programa possui um bug");
				return 1;
		}
	}while(!saida);

	fp = fopen("dados.txt","wt");
	if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
	}
	turma_salva(fp,turma);
	fclose(fp);
    return 0;
}
