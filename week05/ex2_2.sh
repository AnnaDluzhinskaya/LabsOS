if !(test -f ex2_2.txt); then
    echo 0 >> ex2_2.txt
fi

if ln ex2_2.txt ex2_2.txt.lock; then	
     while true
     do
         echo "$(($(tail -n 1 ex2_2.txt)+1))" >> ex2_2.txt
     done
     rm ex2_2.txt.lock
fi
