## for Ubuntu 22.22
for other releases, see: https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/download/


### step 1: 

```
wget -nv https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/Ubuntu_22.04/Release.key -O - | sudo apt-key add -
```
### step 2: 

```
"/etc/apt/trusted.gpg.d/isv:ownCloud:desktop.gpg" to "/etc/apt/trusted.gpg.d/isv-ownCloud-desktop.gpg"
```

### step 3:
```
wget -nv https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/Ubuntu_22.04/Release.key -O - | sudo apt-key add -
```

### step 4:
```
echo 'deb https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/Ubuntu_22.04/ /' | sudo tee -a /etc/apt/sources.list.d/owncloud.list
sudo apt update
sudo apt install owncloud-client
```

### Um Konfigurations- und/oder Datendateien von owncloud und seinen Abhängigkeiten von Ubuntu zu löschen, führen Sie dann Folgendes aus:
```
sudo apt-get autoremove --purge owncloud
```
