```
eric@X1-Linux-Simo:~/.../AWS$ ssh -i '/.../tecawskey2.pem' ubuntu@ec2-3-xx-xx-xx.eu-central-1.compute.amazonaws.com
```

```
eric@X1-Linux-Simo:~/.../AWS$ scp -i ./tecawskey2.pem ./test.pdf ubuntu@ec2-3-xx-xx-xx.eu-central-1.compute.amazonaws.com:~
```

```
https://ubuntu.com/tutorials/ubuntu-desktop-aws#3-configuring-the-vnc-server
```



![image](https://user-images.githubusercontent.com/22998049/195991836-6df1fbbd-b055-4ea0-906d-20858d5806ef.png)



Install and set up Display Manager
A display manager is an application that starts the display server, launches the desktop, and manages user authentication. The default GDM3 is a resource-intensive display manager. To conserve system resources, consider a lighter tool, such as SLiM or LightDM.

This guide uses SLiM to illustrate the rest of the GUI installation process.

1. To install SLiM, type:

```
sudo apt install slim
```

Ubuntu Desktop
The default Ubuntu Desktop is a modified version of the GNOME desktop environment.

1. Install Ubuntu Desktop by running the following command:

```
sudo apt install ubuntu-desktop
```

2. Reboot the system when the installation finishes by typing:
```
sudo reboot
```



Note: If you do not wish to reboot immediately, type the following command to start SLiM:
```
sudo service slim start
```

https://phoenixnap.com/kb/how-to-install-a-gui-on-ubuntu 

