## Linux routines and tricks 

### How to Use the apt Command to Manage Ubuntu Packages
https://hostadvice.com/how-to/how-to-use-the-apt-command-to-manage-ubuntu-packages/ 
#### uninstall packages 
You can uninstall or removes an installed paraview package itself from Ubuntu 17.04 (Zesty Zapus) through the terminal,
```bat
sudo apt-get remove paraview
```
 
Uninstall paraview including dependent package
If you would like to remove paraview and it's dependent packages which are no longer needed from Ubuntu,
```bat
sudo apt-get remove --auto-remove paraview 
```
 
Use Purging paraview
If you use with purge options to paraview package all the configuration and dependent packages will be removed.
```bat
sudo apt-get purge paraview 
```
 
If you use purge options along with auto remove, will be removed everything regarding the package, It's really useful when you want to reinstall again.
```bat
sudo apt-get purge --auto-remove paraview 
```
 
#### meshio
meshio is to be installed locally.
```bat
pip install meshio 
```
Don't use the SUDO command 

then install: 
```bat
pip install npx 
```
then add the  local/bin path in your baschrc file or do it globally 

![image](https://user-images.githubusercontent.com/22998049/142422914-d66e2546-8d36-4de5-b1fd-161b348ac1a2.png)

install branches of meshio:
```
pip install git+https://github.com/nschloe/meshio@flac-fix2 --force
```

#### ssh github settings 
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIGLDbIjyIiW0zEKrdVrF4JmqxPU8C9rXy7nGuW8Ob2pC eric@X1-Linux-Simo

#### Ordner freigeben in linux  
```
chmod -R 0777 *
```
```
chmod -R 0777 ./Non_equil_neue_Geom_Eric
```



