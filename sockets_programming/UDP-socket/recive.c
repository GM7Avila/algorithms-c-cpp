#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "msg.h"

int main(void) {
  int sock; /* Socket de comunicacao */
  int cli_len, tamanho;
  struct sockaddr_in endereco; /* Informacoes do servidor */
  struct sockaddr_in cli_addr; /* Informacoes do cliente */
  struct s_msg msg; /* Mensagem a ser trocada pela rede */
  unsigned char ip[4]; /* Separar octetos do endereco IP */
  int contagem = 0; /* Contador de interacoes */

  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("Abertura de socket.");
    exit(1);
  }

  // ANEXANDO UM ENDEREÇO DE SOCKET
  /* Associa socket com interface IP local */
  endereco.sin_family = AF_INET; 
  endereco.sin_addr.s_addr = INADDR_ANY; 
  endereco.sin_port = 0; 

  if (bind(sock, (struct sockaddr *) &endereco, sizeof endereco) < 0) {
    perror("Bind no socket: ");
    exit(1);
  }

  /* Obtem e mostra o valor da porta do socket */
  tamanho = sizeof(endereco);
  if (getsockname(sock, (struct sockaddr *) &endereco, &tamanho) < 0) {
    perror("Obtencao do endereco do socket\n");
    exit(1);
  }
  printf("Porta de socket #%d\n", ntohs(endereco.sin_port));

  /* Lendo a msg */
  cli_len = sizeof(struct sockaddr);
  while(1) {
    if (recvfrom(sock, (char *) &msg, sizeof(msg), 0, (struct sockaddr *) &cli_addr, &cli_len) < 0) {
      perror("Recepcao de datagrama");
      close(sock);
      exit(1);
    }
    memcpy(&ip, &cli_addr.sin_addr, 4); /* Separa endereco IP do cliente */
    printf("Mensagem de \"%d.%d.%d.%d\":\n", ip[0],ip[1],ip[2],ip[3]);
    
    printf("- Nome: %s\n", msg.c);
    printf("- Idade: %d\n " , msg.a);
    printf("- Salário: %f\n\n ", msg.b);

    /* Envia resposta */
    msg.a = ++contagem;
    if (sendto(sock, (char *) &msg, sizeof(msg), 0, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) < 0) {
      perror("Envio de mensagem.");
      exit(1);
    }
  }

  close(sock);
  return 0;
}

