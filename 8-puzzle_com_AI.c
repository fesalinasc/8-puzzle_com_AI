#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
typedef struct no
{
    int info[3][3];
    struct no *prox;
    struct no *pai;
    int profundidade;
}No;

typedef struct pilha
{
    No *TOPO;
} Pilha;

Pilha* CriaPilha()
{
     Pilha *p;
     p=(Pilha*)malloc(sizeof(Pilha));
     p->TOPO = NULL;
   return p;
}

int vaziaPilha(Pilha *p)
{
    if (p->TOPO==NULL)
    {
        return 1;
    }
    return 0;
}

void copia_matriz(int original[3][3], int copia[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            copia[i][j] = original[i][j];
        }
    }
}

No* ins_ini (No* t, int estado_matriz[3][3], No* pai_do_no)
{
    No* aux = (No*) malloc(sizeof(No));
    copia_matriz(estado_matriz, aux->info);
    aux->prox = t;
    aux->pai = pai_do_no;
    if(pai_do_no == NULL)
    {
        aux->profundidade = 0;
    }
    else
    {
        aux->profundidade = pai_do_no->profundidade+1;
    }
    return aux;
}

void push (Pilha* p, int matriz[3][3], No* pai_do_no)
{
    p->TOPO = ins_ini(p->TOPO,matriz, pai_do_no);
}

No* ret_ini (No* aux)
{
    No* p = aux->prox;
    free(aux);
    return p;
}

No* pop (Pilha *p)
{
    if (vaziaPilha(p) == 1)
    {
        printf("Pilha vazia\n");
        return NULL;
    }
    No*removido = p->TOPO;
    p->TOPO = p->TOPO->prox;
    removido->prox = NULL;
    return removido;
}

typedef struct fila
{
    No *inicio;
    No *fim;
} Fila;

Fila* CriaFila()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

int VaziaFila (Fila* f)
{
    if (f->inicio==NULL)
    {
        return 1;
    }
    return 0;
}

No* ins_fim (No *fim, int estado_matriz[3][3], No* pai_do_no)
{
    No *p = (No*)malloc(sizeof(No));
    copia_matriz(estado_matriz, p->info);
    p->prox = NULL;
    p->pai = pai_do_no;
    if (fim != NULL)
    {
        fim->prox = p;
    }
    return p;
}

void InsereFila (Fila* f, int matriz[3][3], No* pai_do_no)
{
    f->fim = ins_fim(f->fim,matriz, pai_do_no);
    if (f->inicio==NULL)
    {
        f->inicio = f->fim;
    }

}

No* retira_ini (No* inicio)
{
    No* p = inicio->prox;
    free(inicio);
    return p;
}

No* RetiraFila (Fila* f)
{
    if (VaziaFila(f))
    {
        printf("Fila vazia\n");
        exit(0);
    }
    No* aux = f->inicio;
    f->inicio = aux->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    aux->prox = NULL;
    return aux;
}

void imprimir_puzzle(int puzzle[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("------------\n");
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[i][j] == 0)
            {
                printf("   |");
            }
            else
            {
                printf(" %d |", puzzle[i][j]);
            }
        }
        printf("\n");
    }
    printf("------------\n");
}

void imprime_caminho(No* no_final)
{
    if (no_final != NULL)
    {
        Pilha* pilha_aux = CriaPilha();
        No* atual = no_final;
        while (atual != NULL)
        {
        push(pilha_aux, atual->info, NULL);
        atual = atual->pai;
        }
        printf("\t\nPasso a passo da solu��o:\n");
        No* passos;
        while (vaziaPilha(pilha_aux) == 0)
        {
            passos = pop(pilha_aux);

            imprimir_puzzle(passos->info);

            if (vaziaPilha(pilha_aux) == 0)
            {
                printf("\n\n");
            }
        }
    }
}

void acha_posicao_zero(int puzzle_antigo[3][3], int puzzle_novo[3][3], int *linha_do_zero, int *coluna_do_zero)
{
    copia_matriz(puzzle_antigo, puzzle_novo);
    *linha_do_zero = -1, *coluna_do_zero = -1;
    int achou = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle_novo[i][j] == 0)
            {
                *linha_do_zero = i;
                *coluna_do_zero = j;
                achou = 1;
                break;
            }
        }
        if(achou == 1)
        {
            break;
        }
    }
}

void funcao_suc(int puzzle_antigo[3][3], int puzzle_novo[3][3], int numero_movido)
{
    int linha_do_zero, coluna_do_zero;
    acha_posicao_zero(puzzle_antigo, puzzle_novo, &linha_do_zero, &coluna_do_zero);

    if (linha_do_zero > 0 && puzzle_novo[linha_do_zero - 1][coluna_do_zero] == numero_movido)
    {
        puzzle_novo[linha_do_zero][coluna_do_zero] = numero_movido;
        puzzle_novo[linha_do_zero - 1][coluna_do_zero] = 0;
    }
    else
    {
        if (linha_do_zero < 2 && puzzle_novo[linha_do_zero + 1][coluna_do_zero] == numero_movido)
        {
            puzzle_novo[linha_do_zero][coluna_do_zero] = numero_movido;
            puzzle_novo[linha_do_zero + 1][coluna_do_zero] = 0;
        }
        else
        {
            if (coluna_do_zero > 0 && puzzle_novo[linha_do_zero][coluna_do_zero - 1] == numero_movido)
            {
                puzzle_novo[linha_do_zero][coluna_do_zero] = numero_movido;
                puzzle_novo[linha_do_zero][coluna_do_zero - 1] = 0;
            }
            else
            {
                if (coluna_do_zero < 2 && puzzle_novo[linha_do_zero][coluna_do_zero + 1] == numero_movido)
                {
                    puzzle_novo[linha_do_zero][coluna_do_zero] = numero_movido;
                    puzzle_novo[linha_do_zero][coluna_do_zero + 1] = 0;
                }
            }
        }
    }
}

int completo(int puzzle[3][3])
{
    int i,j;
    int objetivo[3][3] = {{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 0}};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (puzzle[i][j] != objetivo[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void gerar_puzzle_inicial(int puzzle[3][3])
{
    int linha_zero, coluna_zero, achou, i, j, x;
    int resolvido[3][3] = {{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 0}};
    copia_matriz(resolvido, puzzle);

    for (x = 0; x < 40; x++)
    {
        achou = 0;
        for(i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(puzzle[i][j] == 0)
                {
                    linha_zero = i;
                    coluna_zero = j;
                    achou = 1;
                    break;
                }
            }
            if(achou == 1)
            {
                break;
            }
        }

        int movs_possiveis[4][2];
        int num_movs = 0;

        if (linha_zero > 0)
        {
            movs_possiveis[num_movs][0] = linha_zero - 1;
            movs_possiveis[num_movs][1] = coluna_zero;
            num_movs++;
        }
        if (linha_zero < 2)
        {
            movs_possiveis[num_movs][0] = linha_zero + 1;
            movs_possiveis[num_movs][1] = coluna_zero;
            num_movs++;
        }
        if (coluna_zero > 0)
        {
            movs_possiveis[num_movs][0] = linha_zero;
            movs_possiveis[num_movs][1] = coluna_zero - 1;
            num_movs++;
        }
        if (coluna_zero < 2)
        {
            movs_possiveis[num_movs][0] = linha_zero;
            movs_possiveis[num_movs][1] = coluna_zero + 1;
            num_movs++;
        }

        int mov_idx = rand() % num_movs;
        int i_troca = movs_possiveis[mov_idx][0];
        int j_troca = movs_possiveis[mov_idx][1];

        puzzle[linha_zero][coluna_zero] = puzzle[i_troca][j_troca];
        puzzle[i_troca][j_troca] = 0;
    }
}

void busca_em_largura(int puzzle_novo[3][3])
{
    Fila* fila_busca_largura = CriaFila();
    InsereFila(fila_busca_largura, puzzle_novo, NULL);
    int qtd_estados = 0, achou = 0, linha_do_zero, coluna_do_zero, filho_temp[3][3], igual_pai, k, m;

    No* atual;
    while (VaziaFila(fila_busca_largura) == 0 && achou == 0)
    {
        atual = RetiraFila(fila_busca_largura);
        qtd_estados++;

        if (completo(atual->info) == 1)
        {
            printf("%d estados visitados\n", qtd_estados);
            imprime_caminho(atual);
            achou = 1;
            break;
        }

        acha_posicao_zero(atual->info, filho_temp, &linha_do_zero, &coluna_do_zero);

        if (linha_do_zero > 0)
        {
            int peca = atual->info[linha_do_zero-1][coluna_do_zero];
            copia_matriz(atual->info, filho_temp);
            funcao_suc(atual->info, filho_temp, peca);

            igual_pai = 0;

            if (atual->pai != NULL)
            {
                igual_pai = 1;
                for (k = 0; k < 3; k++)
                {
                    for (m = 0; m < 3; m++)
                    {
                        if (filho_temp[k][m] != atual->pai->info[k][m])
                        {
                            igual_pai = 0;
                        }
                    }
                }
            }
            if (atual->pai == NULL || igual_pai == 0)
            {
                InsereFila(fila_busca_largura, filho_temp, atual);
            }
        }

        if (linha_do_zero < 2)
        {
            int peca = atual->info[linha_do_zero+1][coluna_do_zero];
            copia_matriz(atual->info, filho_temp);
            funcao_suc(atual->info, filho_temp, peca);

            igual_pai = 0;

            if (atual->pai != NULL)
            {
                igual_pai = 1;
                for (k = 0; k < 3; k++)
                {
                    for (m = 0; m < 3; m++)
                    {
                        if (filho_temp[k][m] != atual->pai->info[k][m])
                        {
                            igual_pai = 0;
                        }
                    }
                }
            }
            if (atual->pai == NULL || igual_pai == 0)
            {
                InsereFila(fila_busca_largura, filho_temp, atual);
            }
        }

        if (coluna_do_zero > 0)
        {
            int peca = atual->info[linha_do_zero][coluna_do_zero-1];
            copia_matriz(atual->info, filho_temp);
            funcao_suc(atual->info, filho_temp, peca);

            igual_pai = 0;

            if (atual->pai != NULL)
            {
                igual_pai = 1;
                for (k = 0; k < 3; k++)
                {
                    for (m = 0; m < 3; m++)
                    {
                        if (filho_temp[k][m] != atual->pai->info[k][m])
                        {
                            igual_pai = 0;
                        }
                    }
                }
            }
            if (atual->pai == NULL || igual_pai == 0)
            {
                InsereFila(fila_busca_largura, filho_temp, atual);
            }
        }

        if (coluna_do_zero < 2)
        {
            int peca = atual->info[linha_do_zero][coluna_do_zero+1];
            copia_matriz(atual->info, filho_temp);
            funcao_suc(atual->info, filho_temp, peca);

            igual_pai = 0;

            if (atual->pai != NULL)
            {
                igual_pai = 1;
                for (k = 0; k < 3; k++)
                {
                    for (m = 0; m < 3; m++)
                    {
                        if (filho_temp[k][m] != atual->pai->info[k][m])
                        {
                            igual_pai = 0;
                        }
                    }
                }
            }
            if (atual->pai == NULL || igual_pai == 0)
            {
                InsereFila(fila_busca_largura, filho_temp, atual);
            }
        }
    }
    if (achou == 0)
    {
        printf("\nNenhuma solu��o foi encontrada\n");
    }
}

int busca_profundidade_limitada(int puzzle_inicial[3][3], int limite_maximo)
{
    Pilha* pilha_busca_profundidade = CriaPilha();
    push(pilha_busca_profundidade, puzzle_inicial, NULL);
    int qtd_estados = 0, linha_do_zero, coluna_do_zero, filho_temp[3][3];

    No* atual;
    while(vaziaPilha(pilha_busca_profundidade) == 0)
    {
        atual = pop(pilha_busca_profundidade);
        qtd_estados++;
        if(completo(atual->info) == 1)
        {
            printf("%d estados visitados\n", qtd_estados);
            imprime_caminho(atual);
            return 1;
        }

        if (atual->profundidade < limite_maximo)
        {
            acha_posicao_zero(atual->info, filho_temp, &linha_do_zero, &coluna_do_zero);

            if (linha_do_zero > 0)
            {
                int peca = atual->info[linha_do_zero-1][coluna_do_zero];
                funcao_suc(atual->info, filho_temp, peca);
                push(pilha_busca_profundidade, filho_temp, atual);
            }
            if (linha_do_zero < 2)
            {
                int peca = atual->info[linha_do_zero+1][coluna_do_zero];
                funcao_suc(atual->info, filho_temp, peca);
                push(pilha_busca_profundidade, filho_temp, atual);
            }
            if (coluna_do_zero > 0)
            {
                int peca = atual->info[linha_do_zero][coluna_do_zero-1];
                funcao_suc(atual->info, filho_temp, peca);
                push(pilha_busca_profundidade, filho_temp, atual);
            }
            if (coluna_do_zero < 2)
            {
                int peca = atual->info[linha_do_zero][coluna_do_zero+1];
                funcao_suc(atual->info, filho_temp, peca);
                push(pilha_busca_profundidade, filho_temp, atual);
            }
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int puzzle[3][3], puzzle_novo[3][3], numero_movimento, opcao;

    srand(time(NULL));
    gerar_puzzle_inicial(puzzle);

    do {
        printf("=== 8-Puzzle ===\n\n");
        printf("1 - Jogar\n");
        printf("2 - Busca em Largura (IA)\n");
        printf("3 - Busca em Profundidade Limitada (IA)\n");
        printf("0 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        system("cls");
        printf("=== 8-Puzzle ===\n");

        switch(opcao)
        {
            case 1:
                copia_matriz(puzzle, puzzle_novo);
                while (completo(puzzle_novo) == 0)
                {
                    printf("  --- Jogue ---\n\n");
                    imprimir_puzzle(puzzle_novo);
                    printf("\nDigite a pe�a para mover: ");
                    scanf("%d", &numero_movimento);
                    system("cls");
                    if(numero_movimento == -1)
                    {
                        break;
                    }

                    int temp[3][3];
                    funcao_suc(puzzle_novo, temp, numero_movimento);
                    copia_matriz(temp, puzzle_novo);
                }
                if(completo(puzzle_novo) == 1)
                {
                    printf("Parab�ns, voc� completou o puzzle!\n\n");
                }
                break;
            case 2:
                printf("--- Busca em Largura ---\n\n");
                busca_em_largura(puzzle);
                break;
            case 3:
                printf("--- Busca em Profundidade Limitada ---\n\n");
                int i, achou = 0, limite;
                printf("\nDigite um limite para a busca: ");
                scanf("%d", &limite);
                for(i=1; i<=limite; i++)
                {
                    achou = busca_profundidade_limitada(puzzle, i);
                    if(achou == 1)
                    {
                        break;
                    }
                }
                if(achou == 0)
                {
                    printf("\nNenhuma solu��o encontrada at� o limite %d\n", limite);
                }
                break;
            case 0:
                printf("\nEncerrando\n");
                break;
            default:
                printf("\nOp��o inv�lida\n");
        }
    }while(opcao != 0);
    return 0;
}
