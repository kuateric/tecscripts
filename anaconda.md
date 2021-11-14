

## Installing Anaconda
step 1: 
download anaconda: https://www.anaconda.com/products/individual 
step 2: 
install prerequisites for linux: https://docs.anaconda.com/anaconda/install/linux/
for Debian (Ubuntu) do: 
```bat
sudo apt-get install libgl1-mesa-glx libegl1-mesa libxrandr2 libxrandr2 libxss1 libxcursor1 libxcomposite1 libasound2 libxi6 libxtst6
```
step 3:
- create an installation folder where you will install all your software if you don't have one already
```bat
cd /home 
mkdir programs
```
- create inside the programs folder a subfolder with name 'anaconda3' where anaconda3 will be installed 
step 4:
do int the downloads folder and unzip the anaconda installation files: 
- open a terminal from the downloads folder 
- do bash name_of_the_anaconda_file_you_downloaded in a terminal
```bat
cd /Downloads 
bash Anaconda3-2021.05-Linux-x86_64.sh
```
- you will see some legal notices, then scroll down until you see 
```bat
please answer 'yes' or 'no'
```
- write 'yes'

- next anaconda will now be installed into this location /home/tux/anaconda3
specify a new location be entering the location of your programs folder you created 
```bat
/home/tux/programs
```
- say yest some couples of time an let the installation preparation occurs
- Do you really wish the installer to initiliaze Anaconda3 ? say yes 

step 5: 
open a new terminal, an do this 
```bat
source '/home/tux/programs/anaconda3/bin/activate'
```
