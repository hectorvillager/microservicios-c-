FROM debian:bookworm-slim AS build

RUN apt-get update && apt-get install -y \
    g++ cmake git libboost-system-dev libboost-thread-dev libssl-dev openssl && \
    rm -rf /var/lib/apt/lists/*
RUN apt-get update 
RUN apt-get install -y libasio-dev
WORKDIR /app
COPY . .
RUN mkdir -p /app/certs
# Generar certificado autofirmado
RUN openssl req -new -x509 -nodes -days 365 \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=Example/CN=localhost" \
    -out /app/certs/server.crt -keyout /app/certs/server.key
RUN cmake -B build -S . && cmake --build build --config Release

FROM debian:bookworm-slim
RUN apt-get update && apt-get install -y \
    libssl3 libboost-system1.74.0 libboost-thread1.74.0 && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY --from=build /app/build/server .
COPY --from=build /app/certs /app/certs

EXPOSE 8443
VOLUME ["/app/certs"]
CMD ["./server"]
