#include <stdio.h>
#include "funcoes.h"

// Função que recebe os dados dos estudantes e armazena no vetor recebido
void recebeDados(Estudante v[], int tam){
  int i;
  // Laço para receber dados dos estudantes
  for(i = 0; i < tam; i++){
    do{
      printf("Entre com a idade do estudante %d: ", i + 1);
      scanf("%d", &v[i].idade);
      if (v[i].idade<0) printf("\nIdade inválida\n\n");
    }while(v[i].idade<0);// Faz a verificação da entrada do usuário, caso esteja incorreta pede para inserir o dado de novo
    do{
      printf("\nEntre com a média 1 do estudante %d: ", i + 1);
      scanf("%f", &v[i].nota[0]);
      printf("\nEntre com a média 2 do estudante %d: ", i + 1);
      scanf("%f", &v[i].nota[1]);
      if ((v[i].nota[0]<0.0 || v[i].nota[0]>10.0) ||(v[i].nota[1]<0.0 || v[i].nota[1]>10.0)) printf("\nInsira um número >= 0 ou <= 10\n\n");
    }while((v[i].nota[0]<0.0 || v[i].nota[0]>10.0) || (v[i].nota[1]<0.0 || v[i].nota[1]>10.0));
    do{
      printf("\nEntre com a frequência do estudante %d: \n", i + 1);
      scanf("%f", &v[i].frequencia);
      if (v[i].frequencia<0 || v[i].frequencia>100) printf("\nFrequência inválida\n\n");
    }while(v[i].frequencia<0 || v[i].frequencia>100);
    printf("\n\n");
  }
}

// Função que apresenta o menu na tela
void apresentaMenu(void){
   // Opções do menu
    printf("\nOpção 1: Média de idade da turma;\n");
    printf("\nOpção 2: Média de frequência da turma;\n");
    printf("\nOpção 3: Quantidade de reprovados por frequência;\n");
    printf("\nOpção 4: Quantidade de aprovados por média final;\n");
    printf("\nOpção 5: Média da Média Final da turma;\n");
    printf("\nOpção 6: Maior Média Final da turma;\n");
    printf("\nOpção 7: Menor Média Final da turma;\n");
    printf("\nOpção 8: Finaliza o programa.\n");
    printf("\nEntre com o opção desejada: ");
}

// Função que calcula a média de idade entre os estudantes
float mediaIdade(Estudante v[], int tam){
  int somaIdade = 0;
  float mediaIdade;
  int i;
  for(i=0;i<tam;i++){
    somaIdade = somaIdade + v[i].idade;
  }
  mediaIdade = somaIdade / tam;
 

  return mediaIdade;
}

// Função que retorna a média de frequência dos estudantes
float mediaFrequencia(Estudante v[], int tam){
  int somaFrequencia = 0;
  float mediaFrequencia;
  int i;
    for(i=0;i<tam;i++){
    somaFrequencia = somaFrequencia + v[i].frequencia;
    }
  mediaFrequencia = somaFrequencia / tam;
  return mediaFrequencia;
}

// Função que retorna a quantidade de estudantes com frequência menor de 75%
int quantidadeReprovadosFreq(Estudante v[], int tam){
  
  int i, contRep = 0;
  for(i=0;i<tam;i++){
    if(v[i].frequencia < 75.0){
      contRep++;
    }
  }
return contRep;
}

// Função que retorna a quantidade de estudantes com média final >= 6,0
int quantidadeAprovados(Estudante v[], int tam){
    int aprovados = 0, i;
    float notasEstud[tam];
    for(i=0;i<tam;i++){
      notasEstud[i]=calculaMediaFinal(v[i]);
      if (notasEstud[i] >= 6.0) aprovados++;
    }
  return aprovados;
}

// Função que retorna a média das médias finais da turma
float mediaDaTurma(Estudante v[], int tam){
  float mediaMedia, somaMedia=0.0, notaEstud[tam];
    int i;
    for(i=0;i<tam;i++){
      notaEstud[i]=calculaMediaFinal(v[i]);
      somaMedia = somaMedia + notaEstud[i];
      mediaMedia = somaMedia / tam; 
    }
  return mediaMedia;
}

// Função que retorna a maior média final entre os estudantes
float maiorMediaFinal(Estudante v[], int tam){
  float MaiorNota, mediaFin[tam];
  int i;
    for(i=0;i<tam;i++){
      mediaFin[i]=calculaMediaFinal(v[i]);
      if(mediaFin[i] > MaiorNota)
      MaiorNota=mediaFin[i];
    }
  return MaiorNota;
}

// Função que retorna a menor média final entre os estudantes
float menorMediaFinal(Estudante v[], int tam){
  float MenorNota, mediaFin[tam];
  int i;
  for(i=0;i<tam;i++){
    mediaFin[i]=calculaMediaFinal(v[i]);
    if (i==0) MenorNota = mediaFin[i];
    if(mediaFin[i] < MenorNota)  MenorNota = mediaFin[i];
  }
  return MenorNota;
}

// Função que calcula a média das médias finais dos estudantes
float calculaMediaFinal(Estudante v){
  float media;
  media=(v.nota[0]*0.4)+(v.nota[1]*0.6); 
  return media;
}
