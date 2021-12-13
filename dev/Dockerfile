FROM ubuntu:focal

RUN apt-get update && apt-get install -y cmake libgtest-dev git && rm -rf /var/lib/apt/lists/* \
    cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}} \
    cmake --build ${{github.workspace}}/build --config ${{env.BUILD_TYPE}}

CMD ["cmake"]