SOURCE	= main.cpp
OUT	= start
CC	 = g++
FLAGS	 = -Wall

all: 
	 $(CC) $(FLAGS) $(SOURCE)  glad/glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -ldl -o $(OUT)

clean:
	rm -f $(OUT)
