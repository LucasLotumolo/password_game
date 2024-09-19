/*
Implementar em Linguagem C o seguinte Jogo:
• São sorteados cinco números de 0 a 9 distintos
• O jogador deve acertar os números na ordem correta
• A cada jogada, o programa imprime
a) Um * para cada número certo no lugar certo
b) Um # para cada número certo no lugar errado
• O jogo termina quando o jogador acertar o número ou o
número máximo de tentativas for esgotado
• Observações
• O programa deve imprimir primeiro todos os asteriscos
e depois os hashtags
• O programa não deve deixar o usuário digitar números
repetidos
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    const int False = 0, True = 1;
    int comp[5], usu[5];
    int i, j, repetido, acertos = 0, erros = 0;

    for (i=0;i<5;i++)
    {   do{
            repetido = False;
            comp[i] = rand()%10;
            for(j = 0;j<i;j++){  
                if (comp[i]==comp[j]){
                    repetido = True;
                }
            }
        }while(repetido);
    }

    for(i=0;i<5;i++){
        printf("%d", comp[i]);
    }
    
    for (i = 0; i < 5; i++)
    {
        do{
            repetido = False;
            printf("\nDigite o numero %d (0-9): \n", i + 1); scanf("%d", &usu[i]);
            for (j=0;j<i;j++){
                if (usu[i] == usu[j]){
                    printf("Numero repetido. Tente novamente.\n");
                    repetido = True;
                }
            }
        }while (repetido);
    }

    for(i=0;i<5;i++){
        printf("%d", usu[i]);
    }

    for (i=0;i<5;i++) {
        if (usu[i] == comp[i]) {
            acertos++;
        }
    }
    
    for (i=0;i<5;i++) {
        for (j=0;j<5;j++) {
            if (usu[i] == comp[j] && i != j){
                erros++;
            }
        }
    }
    
    if (acertos == 5) {
        printf("\nParabens: Voce acertou todos!\n");
    }else{
        printf("\nNao foi dessa vez...Voce acertou apenas %d!\n", acertos);
    }
    return 0;
}