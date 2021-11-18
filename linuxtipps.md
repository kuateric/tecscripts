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

![image](https://user-images.githubusercontent.com/22998049/142422914-d66e2546-8d36-4de5-b1fd-161b348ac1a2.png)


