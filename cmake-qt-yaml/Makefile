default: go

go: bake run

bake:
	[[ -d build ]] && rm -r build || true;
	mkdir build && cd build; cmake .. && make

run:
	cd build && ./test.bin
