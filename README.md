# tecscripts



## Preparing OGS-Workstations NEU
### step 1
```bat
sudo apt-get update
```
### step 2 if not already installed 
```bat
sudo apt install build-essential git python3 python3-pip cmake cmake-curses-gui -y
```

### step 2 if already installed (for PATCH DAY)
```bat
sudo apt upgrade build-essential git python3 python3-pip cmake cmake-curses-gui -y
```

### step 2 mkl 
```bat
cd /opt/programme
sudo mkdir mkl
cd mkl
```
install oneapi of intel: 
```bat
wget https://registrationcenter-download.intel.com/akdlm/irc_nas/18483/l_onemkl_p_2022.0.2.136_offline.sh

sudo sh ./l_onemkl_p_2022.0.2.136_offline.sh
```
add to the bashrc-file 
```bat
source /opt/intel/oneapi/setvars.sh intel64
```

### to install OGS:
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
sudo mkdir ogs-6.4.2
cd ogs-6.4.2
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
##### write in the root-terminal  
```bat
source /opt/intel/oneapi/setvars.sh intel64
```

##### step: configure and generate OGS with Mfront and MKL : 
```bat
cmake -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release ../ogs
```
##### step: configure and generate OGS with Mfront and MKL with Ninja : 
```bat
cmake -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -G Ninja ../ogs
```
##### step: configure and generate OGS with Mfront : 
```bat
cmake -DOGS_USE_MFRONT=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release ../ogs
```
##### step: compiling OGS 
```bat
make -j 2
```
##### step: compiling OGS with Ninja
download : https://github.com/joergbuchwald/mini-projects/blob/master/tools/fix_iomp5_linking.py 
```bat
python3 fix_iomp5_linking.py
```

```bat
ninja -j 2
```


##### step: register ogs in the bashrc file or somewhere else 
```bat
cd /home/tux
gedit .bashrc
```
add in `.bashrc` at the end of the file:

```bat
### OpenGeoSys
export LD_LIBRARY_PATH="/opt/programme/opengeosys/ogs-6.4.2/build/lib:$LD_LIBRARY_PATH"
export PATH="/opt/programme/opengeosys/ogs-6.4.2/build/bin:$PATH"
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

### Installing VTUInterface. fix for vtk dependency issue
```bat
pip3 install -U git+https://github.com/joergbuchwald/VTUinterface --no-deps
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



delete folder and files quickly:
![grafik](https://user-images.githubusercontent.com/22998049/167633203-c7c0f4b7-d2f9-42f4-a15c-71731a711784.png)

