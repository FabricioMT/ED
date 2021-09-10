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
Cria uma nova Matriz e inicializa suas variaveis.

celula* criaCel(int valor, int coluna, int linha);
Cria uma nova celula e recebe os valores informados pelo usuario.

Matriz* criaCab(Matriz *M);
Cria uma Celula cabela com Linha e coluna -1.

celula* preencheColuna(int c);
Cria uma cabeça coluna na Matriz na coluna informada pelo usuario.

celula* preencheLinha(int l);
Cria uma cabeça linha na Matriz na linha informada pelo usuario.

Matriz* Inserir(Matriz* M, celula* NovaCel);
Insere o elemento novo na Matriz.

Matriz* ApagaMatriz(Matriz *M);
Percorre decrescendo a Matriz do ultimo ao primeiro liberando as celulas.

void imprimeMatriz(Matriz* M);
Imprime a Matriz;

Matriz* SomaMatriz(Matriz *A,Matriz *B,Matriz *C);
