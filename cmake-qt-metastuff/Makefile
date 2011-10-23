default: bake run

clean:
	[[ -d build ]] && rm -r build || true;

bake:
	mkdir -p build && cd build; cmake .. && make

run:
	build/test.bin
