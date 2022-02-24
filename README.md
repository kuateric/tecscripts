# tecscripts


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


### Installing VSCode 
step 1: download .deb file https://code.visualstudio.com/ and install 

step 2: jupyter: Packages Jupyter, Jupyter Keymap, Jupyter Notebook Renderers  

step 3: XML Tools Package

step 4: Python, C/C++, Fortran package inside VSCode


### Installing Owncloud 
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

### Installing VTUInterface

```bat
pip3 install -U git+https://github.com/joergbuchwald/VTUinterface
```

### Installing OGS6Py

```bat
pip3 install -U git+https://github.com/joergbuchwald/ogs6py
```

### Installing MeshIO
meshio is to be installed locally.
```bat
pip install meshio 
```
Don't use the SUDO command 

if already installed do: 
```bat
pip install meshio --upgrade
```


then install: 
```bat
pip install npx 
```
then add the  local/bin path in your baschrc file or do it globally 

![image](https://user-images.githubusercontent.com/22998049/142422914-d66e2546-8d36-4de5-b1fd-161b348ac1a2.png)

