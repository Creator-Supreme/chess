.PHONY: build run all format
build:
    cmake -S . -B target/
    cmake --build target/
run:
    ./target/bin
