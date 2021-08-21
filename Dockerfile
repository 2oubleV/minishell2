FROM ubuntu:20.04
WORKDIR /app
COPY . /app
RUN apt-get update && \
    apt-get -y install gcc make &&\
    make