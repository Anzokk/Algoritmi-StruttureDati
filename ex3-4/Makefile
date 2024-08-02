# Makefile for compiling Java classes and running tests

# Comando per compilare le classi Java
JAVAC = javac

# Opzioni per il compilatore Java
JAVACFLAGS = -g

# Classpath per JUnit (aggiungi qui il percorso a junit.jar)
CLASSPATH = lib/junit-4.13.2.jar:lib/hamcrest-core-1.3.jar:.

# Directory contenente i file sorgenti Java
SRCDIR = src/

# Directory di output per i file compilati
BINDIR = classes

# Elenco delle classi da compilare
CLASSES = \
	$(SRCDIR)priorityqueue/AbstractQueue.java \
	$(SRCDIR)priorityqueue/PriorityQueue.java \
	$(SRCDIR)priorityqueue/PriorityQueue_test.java \
	$(SRCDIR)priorityqueue/PriorityQueue_test_runner.java \
	$(SRCDIR)graph/AbstractEdge.java \
    $(SRCDIR)graph/AbstractGraph.java \
    $(SRCDIR)graph/Edge.java \
    $(SRCDIR)graph/Graph.java \
	$(SRCDIR)graph/Graph_test.java \
    $(SRCDIR)graph/Prim.java

# Target predefinito: esegue tutti i target

# Target per la compilazione delle classi
classes:
	@mkdir -p $(BINDIR)
	$(JAVAC) $(JAVACFLAGS) -d $(BINDIR) -cp $(CLASSPATH) $(CLASSES)

# Target per l'esecuzione dei test
all: classes

# Pulizia dei file generati
clean:
	rm -rf $(BINDIR)
