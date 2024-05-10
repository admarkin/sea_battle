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

ENTRYPOINT ["./seabattle"]