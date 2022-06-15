
## Installing Mfront 
step 1:
- Download Latest Version:
https://sourceforge.net/projects/tfel/files/ 

setp 1.1: update python
```bat
sudo env "PATH=$PATH" conda update --all
```

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
for me:
```bat
cmake /home/eric/sources/mfront/tfel-3.4.2/source -DCMAKE_BUILD_TYPE=Release -Denable-fortran=ON -Denable-python-bindings=ON -DCMAKE_INSTALL_PREFIX=/home/eric/sources/mfront/tfel-3.4.2/build
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
export PATH="/opt/programme/mfront/mfront-4.1.0/build/bin:$PATH" # mfront bin
export LD_LIBRARY_PATH="/opt/programme/mfront/mfront-4.1.0/build/lib:$LD_LIBRARY_PATH" # mfront lib
export PYTHONPATH="/opt/programme/mfront/mfront-4.1.0/tfel/mfront/build/lib/python3.8/site-packages:$PATH" # mfront python bindings
export PYTHONPATH=$(pwd):$PYTHONPATH

```


## Preparing OGS-Workstations 

### Installing MKL
Update the package index:
```bat
sudo apt-get update
```
Install intel-mkl-full deb package:
```bat
sudo apt-get install intel-mkl-full
```

### Installing OGS 

#### Step: Install a compiler

On Debian-based (e.g. Ubuntu) you need to install the `build-essential`-package (which contains the `gcc`-compiler and the `make`-tool):

```bat
sudo apt install build-essential
```

Check you gcc version, You need to have at least gcc 9.0:

```bat
$ gcc --version
gcc (GCC) 9.0.0
```

#### Step: Install Git

Please check if Git is already installed:

```bat
$ git --version
git version 2.14
```

Otherwise please install Git with your favorite package manager:

```bat
sudo apt-get install git
```

#### Step: Install Python 3 and pip:
```bat
sudo apt-get install python3 python3-pip
```

#### step: Install Ninja

We recommend ninja as a cross-platform build tool (make-replacement).
```bat
sudo apt-get install ninja-build
```

#### Step: Install Conan package manager

Install Conan (>= 1.34.0) with Python’s pip:

```bat
pip3 install --user conan
```
Check on a newly opened command line if Conan was installed successfully:

```bat
$ conan --version
Conan version 1.34.0
```
#### Step: Install Cmake and Ccmake
```bat
sudo apt-get install cmake
```

```bat 
sudo apt install cmake-curses-gui
```

#### to install OGS:
##### step: create Opengeosys folder in /opt 
```bat
cd /opt/programme
sudo mkdir opengeosys
cd opengeosys
```
##### step: create a folder for the installation 
to be replicate each time a new installation, in this case we install the version 6.4.1
```bat
cd opengeosys
sudo mkdir ogs-6.4.1
cd ogs-6.4.1
```

##### step: clone ogs
```bat
git clone https://gitlab.opengeosys.org/ogs/ogs.git
```
##### step: create the build folder 
```bat
mkdir build
cd build
```

##### step: configure and generate OGS with Mfront and MKL : 
```bat
cmake -DMKL_DIR=/usr/include/mkl -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release ../ogs
```
##### step: compiling OGS 
```bat
make -j 2
```

##### step: register ogs in the bashrc file or somewhere else 
```bat
cd /home/tux
gedit .bashrc
```
add in `.bashrc` at the end of the file:

```bat
# OpenGeoSys
export LD_LIBRARY_PATH="/home/tux/programs/ogs_releases/ogs-6.4.0/build/lib:$LD_LIBRARY_PATH"
export PATH="/home/tux/programs/ogs_releases/ogs-6.4.0/build/bin:$PATH"
```



