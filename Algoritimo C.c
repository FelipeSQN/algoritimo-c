#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node{
int codigo; // campo 1
float custo, venda, impostos, margem; // campos 2, 3, 4 e 5 respectivamente

} produto;

void limpa_dados(produto *p){
    for (int i =0 ; i < MAX; i++){
        p[i].codigo=0;
        p[i].custo=p[i].venda=p[i].margem=0;
        p[i].impostos=i%2==0?.18:.15;
    }
}

float gera_custo (){ // gera custos de até 3000.00
    int d1=rand()%3001;
    int d2 = rand()%701;
    return (float) d1/d2;
}
float gera_margem (){// gera margem de até 25%
     int val = rand()%26;
    return (float)val/100.0;
}

void gera_dados(produto *p){
    for (int i =0 ; i < MAX; i++){
        p[i].codigo=i + 1000;
        p[i].margem=gera_margem();
        p[i].impostos=i%2==0?.18:.15;
        p[i].custo=gera_custo();
        p[i].venda= p[i].custo +  p[i].impostos*p[i].custo + p[i].margem*p[i].custo;
    }
}

void imprime (produto *p){
printf ("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");
printf ("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for (int i =0 ; i < MAX; i++)
        printf ("%d \t\t%4.2f \t\t%4.2f \t\t%.2f \t\t%.2f\n",
               p[i].codigo, p[i].custo, p[i].venda, p[i].impostos, p[i].margem );
printf ("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");

}

void ordena(produto *p, int campo){
    struct node t;
    if(campo == 3){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(p[j].venda < p[i].venda){
                    t = p[i];
                    p[i] = p[j];
                    p[j] = t;
            }
        }
    }
}
    if(campo == 2){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(p[j].custo > p[i].custo){
                    t = p[i];
                    p[i] = p[j];
                    p[j] = t;
            }
        }
    }
}

    if(campo == 1){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(p[j].codigo > p[i].codigo){
                    t = p[i];
                    p[i] = p[j];
                    p[j] = t;
            }
        }
    }
}
}

int busca(int x, produto *p, int inicio, int final){
    int meio, cima, baixo;
    baixo = inicio;
    cima = final-1;
    meio = (cima+baixo)/2;

    while(baixo <= cima){
        if(p[meio].codigo==x){
            return meio;
        }else if(x > p[meio].codigo){
            baixo = meio + 1;
        }else{
            cima = meio -1;
        }
            meio = (cima + baixo)/2;
    }

        if( baixo > cima){
            meio = -1;
            return meio;
        }
}

int main (){
srand(time(NULL));
produto produtos[MAX];
limpa_dados(produtos);
gera_dados(produtos);
imprime(produtos);

ordena (produtos, 3); // aplique bubble sort neste campo 3 ascedente
imprime(produtos);
ordena (produtos, 2); // aplique bubble sort neste campo 2 descedente
ordena (produtos, 1);
int b = busca(1623,produtos,0,MAX); // implementar
if (b!=-1)
    printf ("\nProduto %d encontrado:\nCusto: %.2f\nVenda: %.2f\nTaxas + Imp: %.2f%%\n",
        produtos[b].codigo, produtos[b].custo, produtos[b].venda, (produtos[b].impostos + produtos[b].margem)*100 );
    else
        printf ("\nPRoduto nao encontrado\n");
}