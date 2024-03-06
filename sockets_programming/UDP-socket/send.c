#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "msg.h"

/* 
DEVE SER PASSADO  PELA LINHA  DE COMANDO O NOME/IP DO HOSPEDEIRO DESTINO E O NUMERO DA PORTA DA APLICACAO 
*/                  

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in servidor; /* Para onde enviar o datagrama */
    struct sockaddr_in endereco; /* Endereco local */
    int tam_endereco;
    struct hostent *hp;  /* Armazena informacoes do hospedeiro consultado */
    struct s_msg msg; /* Mensagem a ser trocada pela rede */

    if (argc != 3) {
        fprintf(stderr, "\nSINTAX: envia <nome servidor> <numero porta>\n\n");
    exit(1);
    }
  
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("Abertura de socket");
        exit(1);
    }

    /* Local: Atribuindo um endereço de Socket: IP + PORTA*/
    endereco.sin_family = AF_INET; 
    endereco.sin_addr.s_addr = INADDR_ANY; 
    endereco.sin_port = 0; 

    if (bind(sock, (struct sockaddr *) &endereco, sizeof endereco) < 0) {
        perror("Bind no socket: ");
        exit(1);
    }

    /* gethostbyname -> obtem informacoes do servidor */
    if ((hp = gethostbyname(argv[1])) == 0) {
        fprintf(stderr, "%s: hospedeiro desconhecido", argv[1]);
        exit(2);
    }
    /* Copia endereco IP do destino para a estrutura de envio do datagrama */
    memcpy(&servidor.sin_addr, hp->h_addr, hp->h_length);
    servidor.sin_family = AF_INET;
    /* Configura a porta de destino do datagrama */
    servidor.sin_port = htons(atoi(argv[2]));
    
    printf("Idade: ");
    fgets(&(msg.c[0]), 50, stdin);
    msg.a = atoi(msg.c);
    printf("Salário: ");
    fgets(&(msg.c[0]), 50, stdin);
    msg.b = atof(msg.c);
    printf("Nome: ");
    fgets(&(msg.c[0]), 50, stdin);
    
    /* Envia mensagem ao servidor */
    if (sendto(sock, (char *) &msg, sizeof(msg), 0, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
        perror("Envio de mensagem.");
        exit(1);
    }

    /* Le a resposta do servidor */
    tam_endereco = sizeof(struct sockaddr);
    if (recvfrom(sock, (char *) &msg, sizeof(msg), 0, (struct sockaddr *) &servidor, &tam_endereco) < 0) {
        perror("Recepcao de datagrama");
        close(sock);
        exit(1);
    }
    printf("Esta foi a interacao numero %d do servidor.\n", msg.a);

    close(sock);
    return 0;
}

