#define CROW_ENABLE_SSL
#include <crow.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "¡Hola desde Crow HTTPS con certificado generado en Docker!";
    });

    app.port(8443)
        .ssl_file("certs/server.crt", "certs/server.key")
        .multithreaded()
        .run();

    return 0;
}