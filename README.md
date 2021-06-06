# tecscripts
## Installing OpenGeoSys
Summary, 
to install OGS with MKL:
 
step 1:
```bat
git clone https://gitlab.opengeosys.org/ogs/ogs.git
```
step 2: 
```bat
mkdir build
cd build
```
step 3: 
```bat
cmake -DMKL_DIR=/usr/include/mkl -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DCMAKE_BUILD_TYPE=Release ../ogs

```
step 4:
```bat
make -j 2
```

step 5: 
```bat
cd /home
gedit .bashrc
```
add in `.bashrc` at the end of the file:

```bat
# OpenGeoSys
export LD_LIBRARY_PATH="/home/tux/programs/ogs_releases/ogs-6.4.0/build/lib:$LD_LIBRARY_PATH"
export PATH="/home/tux/programs/ogs_releases/ogs-6.4.0/build/bin:$PATH"
```

## Installing Mfront 
step 1:
- Download Latest Version:
https://sourceforge.net/projects/tfel/files/ 

step 2:
- Create an mfront folder and open it
```bat
mkdir mfront
cd mfront
```
- Create an sources folder in the mfront folder and open it
```bat
mkdir sources
cd sources
```
- copy and unzip the mfront source file in the mfront folder 

- Create a build repository in the mfront folder 
```bat
cd ..
mkdir build
cd build
```

step 3: 
```bat
sudo apt install libboost-python-dev
```
step 4: 
```bat
cmake /home/tux/programs/mfront/sources/tfel-3.4.0 -DCMAKE_BUILD_TYPE=Release -Denable-fortran=ON -Denable-python-bindings=ON -DCMAKE_INSTALL_PREFIX=/home/tux/programs/mfront/build

```
step 5:
```bat
make -j 2
```
step 6:
```bat
make install
```
step 7: 
```bat
cd /home
gedit .bashrc
```
add in `.bashrc` at the end of the file:

```bat
export PATH="/home/tux/programs/mfront/build/bin:$PATH" # mfront bin
export LD_LIBRARY_PATH="/home/tux/programs/mfront/build/lib:$LD_LIBRARY_PATH" # mfront lib
export PYTHONPATH="/home/tux/programs/mfront/build/lib/python3.8/site-packages:$PATH" # mfront python bindings
```

## Installing Owncloud 
step 1: read the installation guide and check for updates

https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/download/

step 2: for ubuntu 20.04, for other os and version, check installation guide
```bat
wget -nv https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/Ubuntu_20.04/Release.key -O - | sudo apt-key add -
```

step 3: for ubuntu 20.04, for other os and version, check installation guide
```bat
echo 'deb https://download.owncloud.com/desktop/ownCloud/stable/latest/linux/Ubuntu_20.04/ /' | sudo tee -a /etc/apt/sources.list.d/owncloud.list
sudo apt update
sudo apt install owncloud-client
```

