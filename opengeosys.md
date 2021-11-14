
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
step 3 mit Mfront und MKL : 
```bat
cmake -DMKL_DIR=/usr/include/mkl -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release ../ogs

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
