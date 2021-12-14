FROM gcc

ENV DEBIAN_FRONTEND=nonintercative
ARG EXTRA_INCLUDE_PATHS
ENV EXTRA_INCLUDE_PATHS ${EXTRA_INCLUDE_PATHS}

RUN apt-get update && apt-get install -y cmake libgtest-dev git && rm -rf /var/lib/apt/lists/*

RUN mkdir /home/root && mkdir /home/root/bin /home/root/lib /home/root/include \
        /home/root/repos
WORKDIR /home/root/repos

RUN cmake -version

RUN git clone https://github.com/danielaparker/jsoncons.git
RUN cp -r jsoncons/include/jsoncons/ /home/root/include

RUN git clone https://github.com/gunjanjavaria/playground.git
RUN mkdir -p /home/root/repos/playground/build

WORKDIR /home/root/repos/playground/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release \
 && make

CMD ["cmake"]