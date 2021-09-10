#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"

void main(){
	Matriz *M,*N,*S;
	celula *I;
	int x,stop = 1,c,l,v,p;
    char f;

	while(stop){    
        printf("\nMENU\n");
        printf("1- Criar Matriz\n");
        printf("2- Insere Matriz\n");
        printf("3- Apaga Matriz\n");
        printf("4- Soma Matriz\n");
        printf("5- Imprime Matriz\n");
        printf("6-Sair\n");
        printf("Escolha:");
        scanf("%d",&x);
        switch(x){
            case(1):
            system("clear"); 
            M = criaMat();
            printf("Matriz [A] Criada\n");
            N = criaMat();
            printf("Matriz [B] Criada\n");
            break;

            case(2):
            system("clear"); 
            l = 0;
            printf("Qual Matriz Deseja Inserir ? [Matriz A] ou [Matriz B]\n");
            while(1){
                scanf("%c",&f);
                if((f == 'A') || (f == 'a')){
                    while(1){
                        printf("Informe os valores para Matriz A :[Linha e Coluna e Valor] Parar Inserção = [-1]\n");
                        scanf("%d",&l);
                        if(l == -1) break;
				        scanf("%d%d",&c,&v);
				        I = criaCel(v,c,l);
				        M = Inserir(M,I);
                    }
                }
                if(l == -1) break;
                if((f == 'B') || (f == 'b')){
                    while(1){
				        printf("Informe os valores para Matriz B :[Linha e Coluna e Valor] Parar Inserção = [-1]\n");
                        scanf("%d",&l);
                        if(l == -1) break;
				        scanf("%d%d",&c,&v);
				        I = criaCel(v,c,l);
				        N = Inserir(N,I);
                    }
                }
                if(l == -1) break;
            }
            break;

            case(3):
            system("clear");
            printf("Qual Matriz Deseja Apagar ? [Matriz A] ou [Matriz B]\n");
            while(1){
                scanf("%c",&f);
                if((f == 'A') || (f == 'a')){
                    if(!Vazia(M)){
                        printf("ERROR - Matriz A - Vazia\n");
                        break;
                    }else{
                        M = ApagaMatriz(M);
                        printf("Matriz A - Apagada Com Sucesso\n");
                        if(Vazia(M)) break;
                    }
                }
                if((f == 'B') || (f == 'b')){
                    if(!Vazia(N)){
                        printf("ERROR - Matriz B - Vazia\n");
                        break;
                    }else{
                        N = ApagaMatriz(N);
                        printf("Matriz B - Apagada Com Sucesso\n");
                        if(Vazia(N)) break;
                    }
                }
            }
            break;

            case(4):
            imprimeMatriz(M);  

            break;
                
            case(5):
            system("clear");
			printf("Qual Matriz Deseja Imprimir ? [Matriz A] ou [Matriz B]\n");
            while(1){
                scanf("%c",&f);
                if((f == 'A') || (f == 'a')){
                    if(!Vazia(M)){
                        printf("ERROR - Matriz A - Vazia\n");
                        break;
                    }else{
                        imprimeMatriz(M);
                        break;
                    }
                }
                if((f == 'B') || (f == 'b')){
                    if(!Vazia(N)){
                        printf("ERROR - Matriz B - Vazia\n");
                        break;
                    }else{
                        imprimeMatriz(N);
                        break;
                    }
                }
            }
            break;

            case(6):
				stop=0;
            break;
        }
    }
}