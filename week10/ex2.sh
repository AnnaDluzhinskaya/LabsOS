mkdir week01
mkdir week10

rm ./week01/file.txt

echo "Anna Dluzhinskaya B20-03" > ./week01/file.txt 

link ./week01/file.txt ./week10/_ex2.txt 

i_node=($(ls -i ./week10/_ex2.txt))

find ./week10  -inum  $i_node > ex2.txt

find ./week10  -inum  $i_node -exec rm {} \; >> ex2.txt

