
rm -rf lofsdisk/
rm lofs.img
ls
clear
ls

dd if=/dev/zero of=lofs.img bs=1M count=50
ls -lh

losetup -a
sudo losetup -fP lofs.img
losetup -a
ls


mkfs.ext4 ./lofs.img

mkdir lofsdisk
ls

sudo mount --rw -o loop /dev/loop9 ./lofsdisk/
ls
