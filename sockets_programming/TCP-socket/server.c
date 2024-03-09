#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "comum.h"

int main(void) {
  int sock; /* Socket ("pai") de comunicacao para receber conexao */
  int msgsock; /* Socket ("filho") de comunicacao para tratar conexao */
  int cli_len, tamanho;
  struct sockaddr_in servidor; /* endereço do servidor -> informacoes */
  struct sockaddr_in cli_addr; /* endereço do cliente -> informacoes */
  struct s_msg msg; 
  unsigned char ip[4]; 
  int iteracoes = 0; 

  /* CONSTROI O SOCKET PARA AGUARDAR POR CONEXOES */
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Abertura de socket: ");
    exit(1);
  }

  servidor.sin_family = AF_INET; 
  servidor.sin_addr.s_addr = INADDR_ANY; 
  servidor.sin_port = htons(PORTA_SERV); /* valor em "comum.h" */

  if (bind(sock, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
    perror("Bind no socket: ");
    exit(1);
  }

  listen(sock, 5); /* pode enfileirar até 5 conexões */
  while (1) {
    /* bloqueia aguardando por conexoes */
    cli_len = sizeof(struct sockaddr_in);
      if ((msgsock = accept(sock, (struct sockaddr *) &cli_addr, &cli_len)) < 0)
        perror("Accept");
      else /* conexao estabelecida: recebe mensagem. */
        if (recv(msgsock, (char *) &msg, sizeof(msg), 0)<0)
          perror("Erro ao ler mensagem: ");
        else { /* processa a requisicao */
          memcpy(&ip, &cli_addr.sin_addr, 4);
          printf("Mensagem de \"%d.%d.%d.%d\":\n", ip[0],ip[1],ip[2],ip[3]);
          printf("    Inteiro -> %d\n", msg.a);
          printf("    Real ----> %f\n", msg.b);
          printf("    String --> %s\n\n", msg.c);
        }
		
      /* envia resposta */
      msg.a = ++iteracoes;
      if (send(msgsock, (char *) &msg, sizeof(msg), 0) < 0)
        perror("Envio da resposta: ");
      close(msgsock);
    }
    
  close(sock);
  return 0;
}
