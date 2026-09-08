
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

int main(void)
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];

    /*
     * 1. Criar o socket UDP
     */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    /*
     * 2. Configurar o endereço do servidor
     */
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    /*
     * 3. Associar o socket ao IP/porta
     */
    if (bind(sockfd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("UDP server listening on port %d...\n", PORT);

    /*
     * 4. Esperar mensagens
     */
    while (1)
    {
        client_len = sizeof(client_addr);

        int bytes_received = recvfrom(
            sockfd,
            buffer,
            BUFFER_SIZE - 1,
            0,
            (struct sockaddr *)&client_addr,
            &client_len
        );

        if (bytes_received < 0)
        {
            perror("recvfrom");
            break;
        }

        /*
         * Adicionar '\0' para tratar o buffer como string.
         */
        buffer[bytes_received] = '\0';

        printf("Received: %s\n", buffer);
    }

    /*
     * 5. Fechar o socket
     */
    close(sockfd);

    return EXIT_SUCCESS;
}

