.PHONY: build run all format clean
build:
	cmake -G Ninja -S . -B build/ \
	-DCMAKE_C_COMPILER=clang \
  	-DCMAKE_CXX_COMPILER=clang++ \
  	-DCMAKE_BUILD_TYPE=Release \
  	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	ln -sfn build/compile_commands.json compile_commands.json
	cmake --build build/ --config Release
run:
	./build/bin/chess
all: build run
format:
	clang-format -i src/*.cpp
	clang-format -i assets/*.hpp
	clang-format -i src/*.hpp	
clean:
	rm -rf build/
