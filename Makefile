	CXX = g++
CXXFLAGS = -Wall -g -std=c++17
TARGET = escola
SOURCES = main.cpp Aluno.cpp Encarregado.cpp GestorEscola.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) lista_alunos.txt

run: $(TARGET)
	./$(TARGET)