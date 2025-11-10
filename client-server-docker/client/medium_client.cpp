// Client inspired by GeeksforGeeks

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <netdb.h>

#define PORT 5555

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    srand(time(NULL));

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {

        std::cout << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) //LOCAL
    //if(inet_pton(AF_INET, "172.17.0.2", &serv_addr.sin_addr)<=0)  //CLIENT DOES NOT RUN IS CONTAINER
    //if(inet_pton(AF_INET, "172.21.0.1", &serv_addr.sin_addr)<=0) //CONTAINER
    //if(inet_pton(AF_INET, "10.0.9.1", &serv_addr.sin_addr)<=0) //OVERLAY
    //{
      //  std::cout << "Address is invalid ... " << std::endl;
        //return -1;
    //}

    // Lanzarlo con docker run -it --network=home_net --name server_container server:1
    const char* server_name = "server_container"; // Cambia por el nombre real del contenedor servidor

    struct hostent* server = gethostbyname(server_name);
    if (server == NULL) {
        std::cout << "No se pudo resolver el nombre del servidor" << std::endl;
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cout << "Connection Failed. Try again! ..." << std::endl;
        return -1;
    }

    int number = rand() % 100;

    std::cout << "check : " << number << std::endl;
    std::string str = std::to_string(number);

    char *cstr = &str[0];

    send(sock, cstr, strlen(cstr), 0);
    std::cout << "Message sent " << std::endl;
    valread = read(sock, buffer, 1024);
    std::cout << buffer << std::endl;

    return 0;
}