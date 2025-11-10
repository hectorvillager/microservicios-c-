FROM ubuntu:bionic
FROM gcc:latest
ADD . /usr/src
WORKDIR /usr/src
EXPOSE 5555
RUN g++ medium_server.cpp -o medium_server
# comment this and un - comment other if you would like to run your # program manually from shell
CMD ["./medium_server"] 
#CMD ["/bin/bash"]