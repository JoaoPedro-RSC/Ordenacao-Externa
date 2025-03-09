# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Arquivos-fonte
SRC = main.c heap.c substituicao.c intercalacaof1.c

# Arquivos-objeto
OBJ = $(SRC:.c=.o)

# Nome do executável
TARGET = programa

# Regra padrão: compilar o executável
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar arquivos .c em .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para remover arquivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

# Regra para recompilar do zero
rebuild: clean all
