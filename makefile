project1: project1.c
	gcc project1.c -o cipher

test: test1 test2

test1: 
	./project1 1 HELLO data1.txt dataEncrypt1.txt
	./project1 2 HELLO dataEncrypted1.txt dataDecrypted.txt
	diff -s data1.txt dataDecrypted1.txt

test2:
	./project1 1 ARAGORNDUNEDAIN data2.txt dataEncrypted2.txt
	./project1 2 HELLO dataEncrypted2.txt dataDecrypted.txt
	diff -s data2.txt dataDecrypted2.txt
