sudo mkdir -p /home/parallels/LabsOS/week11/lofsdisk/usr/bin/
sudo mkdir -p /home/parallels/LabsOS/week11/lofsdisk/bin/
sudo mkdir -p /home/parallels/LabsOS/week11/lofsdisk/lib64/

sudo cp -v /bin/bash /home/parallels/LabsOS/week11/lofsdisk/bin/bash
sudo cp -v /bin/ls /home/parallels/LabsOS/week11/lofsdisk/bin/ls
sudo cp -v /bin/cat /home/parallels/LabsOS/week11/lofsdisk/bin/cat
sudo cp -v /bin/echo /home/parallels/LabsOS/week11/lofsdisk/bin/echo

for cmd in /bin/bash /bin/ls /bin/cat /bin/echo
do
	list=$(ldd $cmd | egrep -o "/lib.*\.[0-9]")
	IFS=$`\n`
	echo $list | while read -r i; do sudo cp -v --parents "$i" "/home/parallels/LabsOS/week11/lofsdisk"; done
done

gcc ex2.c -o ex2.out

sudo bash -c "echo 'Anna' > /home/parallels/LabsOS/week11/lofsdisk/file1"
sudo bash -c "echo 'Dluzhinskaya' > /home/parallels/LabsOS/week11/lofsdisk/file2"

sudo cp ex2.out /home/parallels/LabsOS/week11/lofsdisk/ex2.out

echo "From chroot" > ex2.txt
sudo chroot /home/parallels/LabsOS/week11/lofsdisk/ ./ex2.out >> ex2.txt 
echo "From actual root" >> ex2.txt
./ex2.out >> ex2.txt
