Skip to content
Search & run commands
Search and command bar
Ctrl
.

LibanoriJS
@LibanoriJS

Online
Trabalho LP I 26-06


Copy Link
Cover page

Fork Repl

1

Hide files


Like

Run
/* Fabricio
  Henrique 
  1 semestre LPI */
#include <stdio.h>
#include "funcoes.h"

// TAM define a quantidade de pessoas
#define TAM 5

int main(void) {

  int opcao, i;
  float mediaFin[TAM];
  Estudante turma[TAM];

  recebeDados(turma, TAM);
do{
    
    apresentaMenu();
    scanf("%d", &opcao);

    // Switch-case para cada opção, sendo que cada opção chama funções
    switch (opcao){
      case 1:
        printf("\nMédia de idade da turma: %1.f\n\n", mediaIdade(turma, TAM));
        break;
      case 2:
        printf("\nMédia de frequência da turma: %.1f\n\n", mediaFrequencia(turma, TAM));
        break;
      case 3:
        printf("\nQuantidade de reprovados por frequência: %d\n\n", quantidadeReprovadosFreq(turma, TAM));
        break;
      case 4:
        printf("Quantidade de aprovados por média: %d\n\n", quantidadeAprovados(turma, TAM));
        break;
      case 5:
        printf("Média das Médias da Turma: %.1f\n\n", mediaDaTurma(turma, TAM));
        break;
      case 6:
        printf("Maior Média Final: %.1f\n\n", maiorMediaFinal(turma, TAM));
        break;
      case 7:
        printf("Menor Média Final: %.1f\n\n", menorMediaFinal(turma, TAM));
        break;
      case 8:
        printf("Finalizando...\n");
        break;
      default:
        printf("\nOpção inválida, entre novamente.\n\n");
    }

  } while(opcao != 8); // A opção 8 finaliza o programa
  
  return 0;
}
Files

Made with C
Recent comments (0)

Leave a comment

Edit pinned Repls
Repls
Community
Status
All /

Publish a Repl

New folder
Boosted Repls
Always On Repls
Shared with me
Replit
