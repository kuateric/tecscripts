# tecscripts

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
## Installing OpenGeoSys
Summary, 

First, set up the prerequisites: 

Step: Install a compiler

On Debian-based (e.g. Ubuntu) you need to install the `build-essential`-package (which contains the `gcc`-compiler and the `make`-tool):

```bat
sudo apt install build-essential
```

Check you gcc version, You need to have at least gcc 9.0:

```bat
$ gcc --version
gcc (GCC) 9.0.0
```

Step: Install Git

Please check if Git is already installed:

```bat
$ git --version
git version 2.14
```

Otherwise please install Git with your favorite package manager:

```bat
sudo apt-get install git
```

step: Install Ninja

We recommend ninja as a cross-platform build tool (make-replacement).

Step: Install Conan package manager

Install Conan (>= 1.34.0) with Python’s pip:

```bat
pip3 install --user conan
```

Check on a newly opened command line if Conan was installed successfully:

```bat
$ conan --version
Conan version 1.34.0
```

```bat
sudo apt-get install ninja-build
```

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

step 3 ohne Mfront: 
```bat
cmake -DMKL_DIR=/usr/include/mkl -DOGS_USE_MKL=ON -DCMAKE_BUILD_TYPE=Release ../ogs

```
step 3 mit Mfront: 
```bat
cmake -DMKL_DIR=/usr/include/mkl -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DCMAKE_BUILD_TYPE=Release ../ogs

```
step 4:
```bat
make -j 2
```

step 5: 
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

## Installing VTUInterface

```bat
pip3 install -U git+https://github.com/joergbuchwald/VTUinterface
```

## Installing OGS6Py

```bat
pip3 install -U git+https://github.com/joergbuchwald/ogs6py
```

## Installing MeshIO

```bat
pip3 install -U git+https://github.com/nschloe/meshio
```

## Meshing procedure for OGS simulations
This was tested for 2D-meshes. No warranty for 3D-meshes. 

1. mesh your model with linear element
2. convert if necessary with meshio: 
```bat 
meshio-convert youmesh.msh yourmesh.vtu 
```
3. extract boundaries in paraview:
 
![image](https://user-images.githubusercontent.com/22998049/122689155-f2400380-d220-11eb-91c7-e6c8266274bc.png)

4. convert bulk and boundary mesh into quadratic mesh ( do it for each mesh):
```bat
createQuadraticMesh -i tunnel_inner_linear.vtu -o tunnel_inner.vtu
[2021-06-18 19:24:27.041] [ogs] [info] Create a quadratic order mesh
[2021-06-18 19:24:27.048] [ogs] [info] Save the new mesh into a file

```

5. use identifysubdomain to connect bulk and boundary meshes ( do it for each boundary mesh):
```bat
identifySubdomains -m bulkmesh.vtu  -s 1e-6 -- boundarymesh.vtu
identifySubdomains -m tunnel.vtu  -s 1e-6 -- tunnel_left.vtu

```
if it does not work, increae the s-number for example: `1e-4`

summary: 

```bat
(base) path/to/working/directory$ gmsh tunnel_eric.geo 
(base) path/to/working/directory$ meshio-convert tunnel_eric.msh tunnel_linear.vtu
(base) path/to/working/directory$ paraview tunnel_linear.vtu 
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_linear.vtu -o tunnel.vtu
[2021-06-20 13:41:58.539] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:01.511] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_top_linear.vtu -o tunnel_top.vtu
[2021-06-20 13:42:14.466] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:14.468] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_bottom_linear.vtu -o tunnel_bottom.vtu
[2021-06-20 13:42:28.727] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:28.729] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_left_linear.vtu -o tunnel_left.vtu
[2021-06-20 13:42:40.694] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:40.696] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_right_linear.vtu -o tunnel_right.vtu
[2021-06-20 13:43:09.612] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:43:09.614] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_inner_linear.vtu -o tunnel_inner.vtu
[2021-06-20 13:43:20.486] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:43:20.493] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-6 -- tunnel_inner.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_top.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_bottom.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_left.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_right.vtu 


```

## Compiling fortran-90 codes on Linux using gfortran
```bat
gfortran fortrancode.f90 -ffixed-form
```

## Linux – Swap erweitern
kopiert von: https://technik.blogbasis.net/linux-swap-erweitern-19-11-2013 
- Swap erstellen
Zunächst erstellen wir mit Hilfe des „dd“-Kommandos eine neue Datei (/swap) mit der gewünschten Größe (hier: 1G * 4 = 4G):
```bat
sudo dd if=/dev/zero of=/swap bs=1G count=4
```
Die Größe lässt sich einfach über den „count“ Parameter im Gigabyte-Bereich verändern. Mit dem Parameter „bs“ lässt sich die Blöckgröße ändern. (z.B. 1M ; 1K …).

- Als nächsten müssen wir die Datei mit dem Swap-Dateisystem formatieren. Das klappt mit:
```bat
sudo mkswap /swap
```

- Danach noch kurz die Rechte anpassen:
```bat
sudo chmod 0600 /swap && sudo chown root:root /swap
```
- Swap aktivieren
Um den Swap an das System „anzuschließen“ genügt der folgende Befehl:
```bat
sudo swapon /swap
```
- Das Ergebnis lässt sich leicht durch einen Aufruf von
```bat
free -h
```
nachprüfen (Swap-Zeile).

- Möchte man den Swap auch nach einem Neustart wieder automatisch eingebunden bekommen, dann muss man eine Zeile an die /etc/fstab anhängen:
```bat
sudo cp /etc/fstab /etc/fstab.bak
echo '/swap none swap sw 0 0' | sudo tee -a /etc/fstab
```

