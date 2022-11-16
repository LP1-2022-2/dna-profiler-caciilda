FLAGS  = -Iinclude -Wall -pedantic
PROGRAMA = dna_profiler
all: print
print: bin
	g++ -o bin/$(PROGRAMA) $(FLAGS) src/*.cpp
clean:
	rm *.exe bin/*.exe
alice: 
	bin/$(PROGRAMA).exe -d data/data.csv -s data/sequence_alice.txt
bob: 
	bin/$(PROGRAMA).exe -d data/data.csv -s data/sequence_bob.txt
charlie: 
	bin/$(PROGRAMA).exe -d data/data.csv -s data/sequence_charlie.txt
no_match:
	bin/$(PROGRAMA).exe -d data/data.csv -s data/sequence_no_match.txt
error:
	bin/$(PROGRAMA).exe -d data/data.csv -s d
bin: 
	mkdir -p bin