#FILE PROVIDED BY UNIVERSITY

NAME=principal

#
OBJECTS = $(NAME).o \
		funcionesAuxiliares.o \
		operadoresExternosMonomios.o \
		Monomio.o

#
CPPFLAGS = -c -g -Wall -ansi -O2

INCLUDES = funcionesAuxiliares.hpp \
			macros.hpp  \
			operadoresExternosMonomios.hpp \
			Monomio.hpp

# Macros predefinidas
#
# $@: nombre del objetivo
# $^: todas las dependencias
# $<: primera dependencia
#

all: $(NAME).exe

#Opciones para NO depurar los asertos
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: all

# Primer objetivo 
$(NAME).exe: $(OBJECTS)
			@echo "Generando " $@
			@g++ $^ -o $@
#
$(NAME).o: $(NAME).cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
funcionesAuxiliares.o: funcionesAuxiliares.cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
Monomio.o: Monomio.cpp Monomio.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
operadoresExternosMonomios.o: operadoresExternosMonomios.cpp operadoresExternosMonomios.hpp Monomio.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<


# Generación de la documentación
doc: Doxyfile 
	@echo "Generando la documentación con doxygen"
	@doxygen
  
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ 

