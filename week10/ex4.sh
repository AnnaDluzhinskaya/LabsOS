rm -r tmp

mkdir tmp

> ./tmp/file1
> ./tmp/file2

link ./tmp/file1 ./tmp/link1

gcc ex4.c -o ex4

./ex4 > ex4.txt
