# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src/include
LDFLAGS = 

# Имена файлов
TARGET = program
SRCDIR = src
INCDIR = src/include
OBJDIR = obj

# Автоматический поиск исходных файлов
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Цель по умолчанию
all: $(TARGET)

# Линковка объектных файлов
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "✅ Сборка завершена: $(TARGET)"

# Компиляция исходных файлов в объектные
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Скомпилирован: $<"

# Создание папки для объектных файлов
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Запуск программы
run: $(TARGET)
	@echo "🚀 Запуск программы:"
	./$(TARGET)

# Очистка
clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "🧹 Очистка завершена"

# Удаление всего, включая зависимости
distclean: clean
	rm -f *~

# Справка
help:
	@echo "Доступные команды:"
	@echo "  make all     - полная сборка проекта"
	@echo "  make run     - запуск программы"
	@echo "  make clean   - удаление объектных файлов и бинарника"
	@echo "  make help    - показать эту справку"

# Объявление целей не файлами
.PHONY: all run clean distclean help