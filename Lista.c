#include <stdlib.h>
#include <stdio.h>
#include "TAD-Mat.h"

celula* criaCel(int valor, int coluna, int linha){
	celula *NovaCel = (celula*)malloc(sizeof(celula));
	if(NovaCel != NULL){
		NovaCel->valor = valor;
		NovaCel->linha = linha;
		NovaCel->coluna = coluna;
		NovaCel->Cprox = NULL;
		NovaCel->Lprox = NULL;	
	}else{
		printf("Não foi possivel alocar nova celula");
	}
	return NovaCel;
}

Matriz* criaMat(){
	Matriz *M = (Matriz*)malloc(sizeof(Matriz));
	if(M != NULL){
		M->inicio = NULL;
		M->Fcoluna = NULL;
		M->Flinha = NULL;
	}else{
		printf("Não foi possivel alocar o Espaço de Memoria");
		return 0;
	}
	return criaCab(M);
}

Matriz* criaCab(Matriz *M){
	celula *cab = (celula*)malloc(sizeof(celula));
	if(cab != NULL){
		cab->coluna = -1;
		cab->linha = -1;
		M->inicio = cab;
		M->Fcoluna = cab;
		M->Flinha = cab;		 
	}
	return M;
}

celula* preencheColuna(int c){
	celula *cab = (celula*)malloc(sizeof(celula));
	if(cab != NULL){
		cab->coluna = c;
		cab->linha = -1;
	}
	return cab;
}

celula* preencheLinha(int l){
	celula *cab = (celula*)malloc(sizeof(celula));
	if(cab != NULL){
		cab->coluna = -1;
		cab->linha = l;
	}
	return cab;
}

int Vazia(Matriz *M){
	if((M->coluna == -1) && (M->linha == -1)) return 0; 
}

Matriz* Inserir(Matriz	*M, celula *NovaCel){
	celula* Caux = preencheColuna(NovaCel->coluna); // Coluna Cabeça aux
	celula* Laux = preencheLinha(NovaCel->linha);  // Linha Cabeça aux
	if(!Vazia(M)){	
		M->inicio->Cprox = Caux;
		M->inicio->Lprox = Laux;
		M->Flinha = Laux;
		M->Fcoluna = Caux;
		M->coluna = 1;
		M->linha = 1;
		Caux->Lprox = NovaCel;
		Laux->Cprox = NovaCel;
		Caux->Cprox = M->inicio;
		Laux->Lprox = M->inicio;
		NovaCel->Cprox = Laux;
		NovaCel->Lprox = Caux;
	}else{		
		celula *aux, *ant, *pC, *antC, *pL, *antL;
		ant = M->inicio;
		aux = M->inicio->Cprox;	
		while(aux!= M->inicio){
			if(aux->coluna > NovaCel->coluna) break;
			ant = aux;
			aux = aux->Cprox;
			if(aux->coluna == NovaCel->coluna){
				antC=aux;
				pC = aux->Lprox;
				while(pC!= aux){
					if(pC->linha > NovaCel->linha) break;
					antC = pC;
					pC = pC->Lprox;
				}
				if(pC->linha != NovaCel->linha){
					antC->Lprox = NovaCel;
					NovaCel->Lprox = pC;
				}
			break;
			}
		}
		if(aux->coluna > NovaCel->coluna){
			Caux->Lprox = NovaCel;
			Caux->Cprox = aux;
			NovaCel->Lprox = Caux;
			ant->Cprox = Caux;		
		}else if(aux->coluna < NovaCel->coluna){
					Caux->Lprox = NovaCel;
					Caux->Cprox = aux;
					NovaCel->Lprox = Caux;
					ant->Cprox = Caux;
					M->Fcoluna = Caux;
				}
		
		// busca insere nas linhas
		ant = M->inicio;
		aux = M->inicio->Lprox;
		while(aux!= M->inicio){
			if(aux->linha > NovaCel->linha) break;
			ant = aux;
			aux = aux->Lprox;
			if(aux->linha == NovaCel->linha){
				antL=aux;
				pL = aux->Cprox;
				while(pL!= aux){
					if(pL->coluna > NovaCel->coluna) break;
					antL = pL;
					pL = pL->Cprox;
				}
				if(pL->coluna != NovaCel->coluna){
					antL->Cprox=NovaCel;
					NovaCel->Cprox = pL;
				}
			break;
			}
		}
		if(aux->linha > NovaCel->linha){
			Laux->Cprox = NovaCel;
			Laux->Lprox = aux;
			NovaCel->Cprox = Laux;
			ant->Lprox = Laux;
		}else if(aux->linha < NovaCel->linha){
					Laux->Cprox = NovaCel;
					Laux->Lprox = aux;
					NovaCel->Cprox = Laux;
					ant->Lprox = Laux;
					M->Flinha = Laux;
				}
	}
	return M;
}

Matriz* ApagaMatriz(Matriz *M){
	celula *aux, *ant;
	int rev = 0;
	ant = M->Fcoluna;
	aux = M->Fcoluna->Lprox;	
	while(aux != M->Fcoluna){
		if(M->Fcoluna == M->Fcoluna->Lprox) break;
		if(aux->Lprox == M->Fcoluna){
			ant->Lprox = aux->Lprox;
			free(aux);
			rev = 1;
			ant = M->Fcoluna;
			aux = M->Fcoluna->Lprox;
		}
		if(rev != 1){ 
			ant = aux;
			aux = aux->Lprox;
		}
		rev = 0;
	}
	if(M->Fcoluna == M->Fcoluna->Lprox){
		ant = M->inicio;
		aux = M->inicio->Cprox;
		while(aux != M->inicio){
			if(M->inicio == M->inicio->Cprox) break;
			if(aux == M->Fcoluna){
				ant->Cprox = aux->Cprox;
				free(aux);
				rev = 1;
				M->Fcoluna = ant;
				ant = M->inicio;
				aux = M->inicio->Cprox;
			}
			if(rev != 1){ 
				ant = aux;
				aux = aux->Cprox;
			}
			rev = 0;
		}
	}
	if(M->inicio == M->inicio->Cprox){
		ant = M->inicio;
		aux = M->inicio->Lprox;
		while(aux != M->inicio){
			if(M->inicio == M->inicio->Lprox) break;
			if(aux == M->Flinha){
				ant->Lprox = aux->Lprox;
				free(aux);
				rev = 1;
				M->Flinha = ant;
				ant = M->inicio;
				aux = M->inicio->Lprox;
			}
			if(rev != 1){ 
				ant = aux;
				aux = aux->Lprox;
			}
			rev = 0;
		}
	}
	if((M->inicio == M->inicio->Lprox) && (M->inicio == M->inicio->Cprox)){
		printf("\n");
		printf("* - Remoção Completa - *\n");
		printf("\n");
	}
	return M;
}

Matriz* SomaMatriz(Matriz *A,Matriz *B,Matriz *C){
	celula	*aux, *ant;
}

void imprimeMatriz(Matriz* M){
	celula *aux1, *aux2;
	aux1=M->inicio->Cprox;
	printf("[L C V]\n");
	for(aux1; aux1 != M->inicio; aux1 = aux1->Cprox){
		for(aux2 = aux1->Lprox; aux2 != aux1; aux2 = aux2->Lprox){
			printf("[%d %d %d]", aux2->linha,aux2->coluna,aux2->valor);
		}
		printf("\n");
	}
}

void ERRADO(Matriz* A){
	celula* lin=A->inicio;
	celula* col=A->inicio;
	int i=1,j=1,max=0;
	while(lin!=NULL){
		printf("[%d|%d|%d] ",col->linha,col->coluna,col->valor);
		if(col->Cprox!=NULL){
			while((col->Cprox->coluna)>((col->coluna)+i)){
				printf("  [0]   ");
				i++;
			}
			i=1;
			col=col->Cprox;
		}
		else {
			if(max<col->coluna)	max=col->coluna;
			if(col->coluna<max){
				i=col->coluna;
				while(i<max){
					printf("  [0]   ");
					i++;
				}
				i=1;
			}
			printf("\n");
			i=1;
			if(lin->Lprox!=NULL){
				while((lin->Lprox->linha)>((lin->linha)+i)){
					printf("  [0]   ");
					j=1;
					while(j<=max){
						printf("  [0]   ");
						j++;
					}
					i++;
					printf("\n");
				}
				i=1;
				col=col->Cprox;
			}
			lin=lin->Lprox;
			col=lin;
		}
	}
}



