all:
	git submodule update --init --recursive
	cmake -S . -B build
	cmake --build build
	@echo "\n\nRunning application.." && ./build/bin/vscit


clean:
	rm -rf build
	git submodule deinit -f lib/hwinfo
