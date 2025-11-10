FROM ubuntu:latest

RUN apt-get update -y
RUN apt-get upgrade -y

# is it necessary to install all of them?
RUN apt-get install -y g++ gcc cmake make git gdb pkg-config

RUN git clone --depth 1 https://github.com/microsoft/vcpkg
RUN apt-get install -y curl zip

RUN ./vcpkg/bootstrap-vcpkg.sh

RUN /vcpkg/vcpkg install crow

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . .
# Specify the working directory
WORKDIR .
# Create build dir, configure CMake and run build
RUN mkdir build
RUN cmake -B/build -S/
RUN cmake --build /build

EXPOSE 18080 
# Run the built application
CMD ./build/exe_name