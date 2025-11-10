FROM gcc:latest
#just in case,  you can install gcc and cmake
#RUN apt-get update && apt-get -y install build-essentials gcc cmake
ADD . /usr/src 
# add (copy) all from local folder to /usr/src
WORKDIR /usr/src
EXPOSE 5555
RUN g++ medium_client.cpp -o medium_client
# comment this and un - comment other if you would like to run your # program manually from shell
CMD ["./medium_client"] 
#CMD ["/bin/bash"]