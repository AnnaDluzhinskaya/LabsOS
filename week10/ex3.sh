rm _ex3.txt ex3.txt

echo "Anna Dluzhinskaya B20-03" > _ex3.txt 

chmod u=rw-  _ex3.txt 
chmod o=rw-  _ex3.txt 
chmod g=rw-  _ex3.txt 

ls -l _ex3.txt > ex3.txt

echo " " >> ex3.txt

chmod u=rwx  _ex3.txt 
chmod o=rwx  _ex3.txt

ls -l _ex3.txt >> ex3.txt

echo " " >> ex3.txt

chmod g=u  _ex3.txt 

ls -l _ex3.txt >> ex3.txt

echo " " >> ex3.txt

echo "660 - u=rw-,g=rw-,o=---" >> ex3.txt
echo "775 - u=rwx,g=rwx,o=r-x" >> ex3.txt
echo "777 - u=rwx,g=rwx,o=rwx" >> ex3.txt
