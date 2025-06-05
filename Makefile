FPC = fpc

.PHONY: all clean

all: bin/gload

bin/gload: src/*.pas
	$(FPC) -Mobjfpc -Sh -Fusrc -FUobj -FEbin src/gload.pas

clean:
	rm -f obj/* bin/*
