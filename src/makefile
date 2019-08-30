CC = gcc
COMPILER_FLAGS = -std=c99
LINKER_FLAGS = -lm
EXEC_NAME = siguel
OBJECTS = siguel.o leitura.o leituraQRY.o leituraGEO.o svgprint.o consultas.o arquivos.o utils.o Elementos/forma.o Elementos/quadra.o Elementos/semaforo.o Elementos/hidrante.o Elementos/radioBase.o Elementos/predio.o Elementos/muro.o lista.o heapsort.o 

siguel: $(OBJECTS)
		$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)

clean: 
		rm -rf ./*.o
		rm -rf Elementos/*.o