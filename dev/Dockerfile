FROM ubuntu:focal

RUN apt-get update && apt-get install -y cmake libgtest-dev git && rm -rf /var/lib/apt/lists/*

CMD ["cmake"]