all: vk_platformer

VULKAN= -lvulkan
FILE = plat

vk_platformer: Makefile vk_platformer.c
	gcc vk_platformer.c vk/main.c -lglfw -lvulkan -o $(FILE)

clean:
	rm -f $(FILE)

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./$(FILE)

