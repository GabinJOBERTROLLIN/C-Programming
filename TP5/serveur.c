/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"

//signature de fonction ( on peut le mettre dans serveur.h)
int renvoie_message(int , char* );

//Exercice 5
int add(int num1,int num2){
  return num1 + num2;
}

int sous(int num1,int num2){
  return num1 - num2;
}

int mul(int num1,int num2){
  return num1 * num2;
}

int divi(int num1,int num2){
  return num1 / num2;
}

int recois_numeros_calcule(int socketfd){

  struct sockaddr_in client_addr;
  char data[1024];

  unsigned int client_addr_len = sizeof(client_addr);

  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket_fd < 0)
  {
    perror("accept");
    return (EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lecture de données envoyées par un client
  int data_size = read(client_socket_fd, (void *)data, sizeof(data));
  printf("Calcul recu: <%s>\n", data);

  int resultat = 0;
  char operation;
  int num1;
  int num2;
  char tableau[1024];
  sscanf(data, "%s %c %d %d", tableau, &operation, &num1, &num2);
  
  printf("tab : <%s> \n",tableau);
  printf("num1  : %d \n", num1);
  printf("num2 : %d \n",num2);


  switch(operation){
    case '+' : {resultat = add(num1,num2);break;}
  
    case '-' : {resultat = sous(num1,num2);break;}

    case '*' : {resultat = mul(num1,num2);break;}

    case '/' : {resultat = divi(num1,num2);break;}
  }

  
  printf("le résultat : %d \n", resultat);

  char message[1024];
  sprintf(message,"%d",resultat);
  strcpy(data, "résultat = ");
  strcat(data, message);

  printf("Message:: %s\n", message);


  if (data_size < 0)
  {
    perror("erreur lecture");
    return (EXIT_FAILURE);
  }
 

  /*
   * extraire le code des données envoyées par le client.
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  

  renvoie_message(client_socket_fd, data);
  

  // fermer le socket
  close(socketfd);
  return (EXIT_SUCCESS);

  

 
}
//fin Exercice 5 


/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data)
{
  int data_size = write(client_socket_fd, (void *)data, strlen(data));

  if (data_size < 0)
  {
    perror("erreur ecriture");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd)
{
  struct sockaddr_in client_addr;
  char data[1024];

  unsigned int client_addr_len = sizeof(client_addr);

  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket_fd < 0)
  {
    perror("accept");
    return (EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lecture de données envoyées par un client
  int data_size = read(client_socket_fd, (void *)data, sizeof(data));
  
  

  //Exercice 4 

  printf("Message recu: %s\n", data);

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, sizeof(message), stdin);
  strcpy(data, "message: ");
  strcat(data, message);

  //Fin exercice 4


  if (data_size < 0)
  {
    perror("erreur lecture");
    return (EXIT_FAILURE);
  }
 

  /*
   * extraire le code des données envoyées par le client.
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */

  printf("Message recu: %s\n", message); //modifié pour l'exercice 5 on a remplacer data par message 
  char code[10];
  sscanf(data, "%s:", code);

  // Si le message commence par le mot: 'message:'
  if (strcmp(code, "message:") == 0)
  {
    renvoie_message(client_socket_fd, data);
  }

  // fermer le socket
  close(socketfd);
  return (EXIT_SUCCESS);
}

int main()
{

  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (bind_status < 0)
  {
    perror("bind");
    return (EXIT_FAILURE);
  }

  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  // Lire et répondre au client
  /*recois_envoie_message(socketfd);*/

  //Exercice 5
  recois_numeros_calcule(socketfd);
  //fin Exercice 5 

  return 0;
}
