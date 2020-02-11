#ifndef LEITURA_H_INCLUDED
#define LEITURA_H_INCLUDED
#include "interacao.h"
#include "aluno.h"

int valida_nome(char c);
char* le_nome(void);
int valida_matricula(char* mat);
char* le_matricula(void);
float le_nota(void);

#endif // LEITURA_H_INCLUDED
