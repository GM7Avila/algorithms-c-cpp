#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "comum.h"

int main(int argc, char *argv[]) {
  int sock; 
  struct sockaddr_in servidor; 
  struct hostent *hp; /* informacoes do hospedeiro consultado */
  struct s_msg msg; 

  if (argc != 2) {
    fprintf(stderr, "\nSINTAX: cliente <nome servidor>\n\n");
    exit(1);
  }

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Abertura de socket: ");
    exit(1);
  }
  
  /* gethostbyname obtem informacoes do servidor */
  if ((hp = gethostbyname(argv[1])) == 0) {
    fprintf(stderr, "%s: host desconhecido", argv[1]);
    exit(2);
  }

  /* copia endereco IP do servidor para a estrutura de conexao */
  memcpy(&servidor.sin_addr, hp->h_addr, hp->h_length);
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(PORTA_SERV); /* comum.h */

  /* Conecta com o servidor */
  if (connect(sock, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
    perror("Conexao.");
    exit(1);
  }
	
  printf("Entre com um numero inteiro: ");
  fgets(&(msg.c[0]), 50, stdin);
  msg.a = atoi(msg.c);
  printf("Entre com um numero real: ");
  fgets(&(msg.c[0]), 50, stdin);
  msg.b = atof(msg.c);
  printf("Entre com uma string: ");
  fgets(&(msg.c[0]), 50, stdin);
  
  /* Envia mensagem ao servidor */  
  if (send(sock, (char *) &msg, sizeof(msg), 0) < 0) {
    perror("Envio de mensagem.");
    close(sock);
    exit(1);
  }

  /* Le a resposta do servidor */
  if (recv(sock, (char *) &msg, sizeof(msg), 0) < 0) {
    perror("Recepcao da resposta");
    close(sock);
    exit(1);
  }
  
  printf("Esta foi a interacao numero %d do servidor.\n", msg.a);

  close(sock);
  return 0;
}
