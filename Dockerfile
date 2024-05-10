FROM alpine:latest
LABEL authors="admarkin"

RUN apk update
RUN apk add git
RUN apk add cmake
RUN apk add make
RUN apk add g++

COPY . .

WORKDIR /seabattle

RUN mkdir -p build
RUN cd build
RUN cmake ..
RUN make seabattle
#RUN ./seabattle

ENTRYPOINT ["./seabattle"]
#RUN apt-get -y update
#RUN apt-get -y install git
#RUN apt-get -y install cmake
#RUN apt-get -y install make
#RUN apt-get -y install g++