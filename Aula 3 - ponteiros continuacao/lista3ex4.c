/* 4. Crie uma struct chamada ponto2d que tenha como atributos os pontos x e y.
Crie duas estruturas do tipo ponto2d chamadas ponto_inicial e ponto_final. A seguir, o programa
deve solicitar ao usuario a entrada dos dois pontos (ponto_inicial e ponto_final) e exibir o
resultado do calculo da distancia entre os dois pontos.
Lembre: a distancia entre dois pontos eh a raiz quadrada de ((x1-x2)² + (y1-y2)²) */

#include <stdio.h>
#include <math.h>

typedef struct ponto2d
{
    int x, y;

}tponto;


void main()
{
    tponto ponto_inicial;
    tponto ponto_final;
    float raiz;
    printf ("\n digite o ponto inicial x > ");
    scanf ("%d", &ponto_inicial.x);
    printf ("\n digite o ponto final x > ");
    scanf ("%d", &ponto_final.x);
    printf ("\n digite o ponto inicial y > ");
    scanf ("%d", &ponto_inicial.y);
    printf ("\n digite o ponto final y > ");
    scanf ("%d", &ponto_final.y);
    raiz = sqrt((ponto_final.x-ponto_inicial.x)*(ponto_final.x-ponto_inicial.x) + (ponto_final.y-ponto_inicial.y)*(ponto_final.y-ponto_inicial.y));
    printf ("\n raiz: >%.2f", raiz);
}
