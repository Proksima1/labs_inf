```
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ who
proksima :0           2023-09-17 22:49 (:0)
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ pwd
/home/proksima/labs_inf/labs_inf/labs_inf/lab-2
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ls
listing.md  report.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ cd ../
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf$ cd lab-2
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ cp listing.md cp-test/listing.md 
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ls cp-test/
listing.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ mv cp-test/listing.md cp-test/listing2.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ls cp-test/
listing2.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ rm -r cp-test/
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ls
listing.md  report.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ cat 1.txt 
123
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ps
    PID TTY          TIME CMD
   5689 pts/0    00:00:00 bash
   6645 pts/0    00:00:00 ps
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ tail 1.txt 
123
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ head 1.txt 2.tx 
==> 1.txt <==
123

==> 2.tx <==
565778
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ history | grep proksima
  822  cat /home/proksima/.dirsearch/logs/errors-23-07-16_16-23-12.log
  835  cd proksima/
 1028  cd "/home/proksima/Documents/cpp/" && g++ hello.cpp -o hello && "/home/proksima/Documents/cpp/"hello
 1030  cd "/home/proksima/Documents/cpp/" && g++ hello.cpp -o hello && "/home/proksima/Documents/cpp/"hello
 1033  cd "/home/proksima/Documents/cpp/" && g++ hello.cpp -o hello && "/home/proksima/Documents/cpp/"hello
 1035  cd "/home/proksima/Documents/cpp/" && g++ hello.cpp -o hello && "/home/proksima/Documents/cpp/"hello
 1036  cd "/home/proksima/Documents/cpp/" && g++ tempCodeRunnerFile.cpp -o tempCodeRunnerFile && "/home/proksima/Documents/cpp/"tempCodeRunnerFile
 1037  cd "/home/proksima/Documents/cpp/" && g++ hello.cpp -o hello && "/home/proksima/Documents/cpp/"hello
 1080  sudo adduser proksima audio
 1141  cd proksima/
 1247  cd proksima/
 1424  cd proksima/
 1742  grep proksima 123.txt 
 1753  history | grep proksima
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ mkdir 123
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ls
123  listing.md  report.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ rmdir 123
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ls
listing.md  report.md
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ sudo cat 123
124214rtgaf
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ echo "Hello world"
Hello world
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ssh 185.5.249.140 -l k_nikolskiy
k_nikolskiy@185.5.249.140's password: 
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 11 09:36:31 2023 from 85.143.224.50
k_nikolskiy@vds2476450:~$ 
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/proksima/.ssh/id_rsa): id_rsa
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in id_rsa
Your public key has been saved in id_rsa.pub

proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ ssh-copy-id -i id_rsa.pub k_nikolskiy@185.5.249.140
/usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "id_rsa.pub"
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
k_nikolskiy@185.5.249.140's password: 

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'k_nikolskiy@185.5.249.140'"
and check to make sure that only the key(s) you wanted were added.
proksima@proksima-dude:~/labs_inf/labs_inf/labs_inf/lab-2$ scp -i id_rsa test.txt k_nikolskiy@185.5.249.140:/home/k_nikolskiy
test.txt                                                                               100%   13     0.8KB/s   00:00  
 
```
