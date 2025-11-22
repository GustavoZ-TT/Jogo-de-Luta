#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personagem
{
    char nome[20];
    int life;
    int atk;
    int def;
};

void status(struct personagem *p)
{
    printf("Digite o nome do lutador: ");
    scanf("%s", p->nome);
    do
    {
        printf("Digite a vida(Numero terminado em 0): ");
        scanf("%d", &p->life);
    } while (p->life % 10 != 0);
    printf("Digite o ataque: ");
    scanf("%d", &p->atk);
    printf("Digite a defesa: ");
    scanf("%d", &p->def);
}

int dano(struct personagem *p1, struct personagem *p2)
{
    int dano = p1->atk - p2->def;
    if (dano < 0)
    {
        dano = 0;
    }
    return dano;
}

void restaura(int atual, int vidaOriginal)
{
    if (atual != vidaOriginal)
    {
        atual += 10;

        printf("Curando... Vida atual: %d\n", atual);
        restaura(atual, vidaOriginal);
    }
    else
    {
        printf("Vida restaurada: %d!\n", atual);
    }
}

int busca(struct personagem lista[], int tamanho, int escolha, struct personagem *destino)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (i == (escolha - 1))
        {
            strcpy(destino->nome, lista[i].nome);
            destino->life = lista[i].life;
            destino->atk = lista[i].atk;
            destino->def = lista[i].def;
            return 0;
        }
    }
    return 1;
}

int main()
{

    // QUANTIDADE DE PERSONAGENS//
    int q = 2;

    // AÇÕES //
    int acao = 0, e = 0, c1 = 0, c2 = 0, ecp = 0, ep = 0;

    // GUARDA VIDA //
    int gv1 = 0, gv2 = 0;

    printf("\n===== WIGEVO =====\n");
    printf("Digite 1 para comecar!\n");
    printf("Digite 2 para sair!\n");
    printf("\nPress: ");
    scanf("%d", &e);
    printf("\n");

    // ENTRAR OU SAIR DO JOGO //

    switch (e)
    {
    case 1:
        break;
    case 2:
        return 0;
    }

    struct personagem *lista = (struct personagem *)malloc(2 * sizeof(struct personagem));

    struct personagem prontos[3];
    strcpy(prontos[0].nome, "Ragnar");
    prontos[0].life = 120;
    prontos[0].atk = 50;
    prontos[0].def = 30;

    strcpy(prontos[1].nome, "Darius");
    prontos[1].life = 100;
    prontos[1].atk = 60;
    prontos[1].def = 20;

    strcpy(prontos[2].nome, "Kade");
    prontos[2].life = 110;
    prontos[2].atk = 70;
    prontos[2].def = 10;


    printf("\n===== Escolha de personagens =====\n");
    printf("Digite 1 selecionar lutadores prontos!\n");
    printf("Digite 2 para criar lutador!\n");
    printf("\nPress: ");
    scanf("%d", &ecp);

    if (ecp == 1)
    {
        printf("\nEscolha: \n\n");
        printf("1)Ragnar - Vida: 120 Atk: 50 Def: 30\n");
        printf("2)Darius - Vida: 100 Atk: 60 Def: 20\n");
        printf("3)Kade - Vida: 110 Atk: 70 Def: 10\n");
        printf("\nPress: ");
        scanf("%d", &ep);

        if (busca(prontos, 3, ep, &lista[0]))
        {
            printf("Lutador nao encontrado!\n");
            return 0;
        }

        printf("\nJogador 2, escolha seu lutador:\n");
        scanf("%d", &ep);

        if (busca(prontos, 3, ep, &lista[1]))
        {
            printf("Lutador nao encontrado!\n");
            return 0;
        }

        printf("\nJogador 1 escolheu: %s\n", lista[0].nome);
        printf("Jogador 2 escolheu: %s\n", lista[1].nome);
    }
    else
    {
        for (int i = 0; i < q; i++)
        {

            printf("\nDigite os status do lutador jogador %d: \n", i + 1);
            status(&lista[i]);
        }
    }

    gv1 = lista[0].life;
    gv2 = lista[1].life;

    do
    {
        printf("\n===== STATUS ATUAL =====\n");
        printf("%s -> Vida: %d\n", lista[0].nome, lista[0].life);
        printf("%s -> Vida: %d\n", lista[1].nome, lista[1].life);

        printf("\nJogador 1: \n");
        printf("Digite 1 para atacar!\n");
        printf("Digite 2 para curar!\n");
        printf("Digite 3 para aumentar o ataque!\n");
        if (lista[0].life <= 20 && c1 == 0)
        {
            printf("Digite 4 para recarga de vida especial!\n");
        }
        scanf("%d", &acao);
        switch (acao)
        {
        case 1:
            lista[1].life -= dano(&lista[0], &lista[1]);
            break;
        case 2:
            lista[0].life += 10;
            if (lista[0].life > gv1)
            {
                lista[0].life = gv1;
                printf("Limite de vida atingido!\n");
            }
            break;
        case 3:
            lista[0].atk += 10;
            break;
        case 4:
            if (lista[0].life <= 20 && c1 == 0)
            {
                restaura(lista[0].life, gv1);
                lista[0].life = gv1;
                c1++;
            }
            else
            {
                printf("Recarga especial não disponivel!\n");
            }
            break;
        }

        printf("\n===== STATUS ATUAL =====\n");
        printf("%s -> Vida: %d\n", lista[0].nome, lista[0].life);
        printf("%s -> Vida: %d\n", lista[1].nome, lista[1].life);

        printf("\nJogador 2: \n");
        printf("Digite 1 para atacar!\n");
        printf("Digite 2 para curar!\n");
        printf("Digite 3 para aumentar o ataque!\n");
        if (lista[1].life <= 20 && c2 == 0)
        {
            printf("Digite 4 para recarga de vida especial!\n");
        }
        scanf("%d", &acao);
        switch (acao)
        {
        case 1:
            lista[0].life -= dano(&lista[1], &lista[0]);
            break;
        case 2:
            lista[1].life += 10;
            if (lista[1].life > gv2)
            {
                lista[1].life = gv2;
                printf("Limite de vida atingido!\n");
            }
            break;
        case 3:
            lista[1].atk += 10;
            break;
        case 4:
            if (lista[1].life <= 20 && c2 == 0)
            {
                restaura(lista[1].life, gv2);
                lista[1].life = gv2;
                c2++;
            }
            else
            {
                printf("Recarga especial nao disponivel!\n");
            }
            break;
        }
    } while (lista[0].life > 0 && lista[1].life > 0);
    if (lista[0].life <= 0)
    {
        printf("\n%s ganhou!", lista[1].nome);
    }
    else
    {
        printf("\n%s ganhou!", lista[0].nome);
    }

    free(lista);

    return 0;
}