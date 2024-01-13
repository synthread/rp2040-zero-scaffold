default:
	cd build && make

cmake:
	mkdir -p build
	cmake -S . -B build/
