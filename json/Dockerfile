# Imagen base ligera
FROM alpine:latest

# Instalamos g++ y make
RUN apk add --no-cache g++

# Copiamos el código al contenedor
WORKDIR /app
COPY main.cpp .
COPY json.hpp .

# Compilamos el programa
RUN g++ main.cpp -o main -std=c++17

# Comando por defecto
CMD ["./main"]
