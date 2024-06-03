# Дмитриев Антон Александрович, ИП-213

make
make r

cd simplebasic
./sbt pow.sb pow.sa test.o

cd simpleassembler
./sat pow.sa test.o

make clean
