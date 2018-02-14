gcc -c SeqList.c -o SeqList.o
gcc -c SeqListUses.c -o SeqListUses.o
gcc -c SeqListTest.c -o SeqListTest.o
gcc SeqList.o SeqListTest.o SeqListUses.o -o myprogram
./myprogram

