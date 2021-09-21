if !(test -f ex2_1.txt); then
    echo 0 >> ex2_1.txt
fi

while true
do
    echo "$(($(tail -n 1 ex2_1.txt)+1))" >> ex2_1.txt
done
