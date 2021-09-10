typedef struct c{
	int valor;
	int linha, coluna;
	struct c* Cprox;
	struct c* Lprox;
}celula;

typedef struct mat{
	celula *inicio;
	celula *Fcoluna;
	celula *Flinha;
	int linha,coluna;
}Matriz;

Matriz* criaMat();
celula* criaCel(int valor, int coluna, int linha);
Matriz* criaCab(Matriz *M);
celula* preencheColuna(int c);
celula* preencheLinha(int l);
Matriz* Inserir(Matriz* M, celula* NovaCel);
Matriz* ApagaMatriz(Matriz *M);
void imprimeMatriz(Matriz* M);
Matriz* SomaMatriz(Matriz *A,Matriz *B,Matriz *C);
