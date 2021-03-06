## How to install and use apps on user systems

These instructions utilize the tarball created in [how_to_build_it.md](./how_to_build_it.md), copied to the home directory of a user system.

1. Install run-time dependencies:

  * Ubuntu 14.04
  ```
  sudo apt-get install libqt5xmlpatterns5
  sudo apt-get install libsecret-1-0
  ```

  * OpenSUSE 13.2
  ```
  sudo zypper install libQt5WebKitWidgets5
  sudo zypper install libQt5Xml5
  ```

  * CentOS 7
  ```
  wget http://dl.fedoraproject.org/pub/epel/7/x86_64/e/epel-release-7-5.noarch.rpm
  sudo rpm -ivh epel-release-7-5.noarch.rpm
  sudo yum --enablerepo=epel install qt5-qtwebkit
  ```

2. Unpack the tarball:
  ```
  cd ~
  mkdir ~/sample_apps
  tar -xzf ~/sample_apps.tar.gz -C ~/sample_apps
  ```

3. Run the apps:
  ```
  cd ~/sample_apps
  export LD_LIBRARY_PATH=`pwd`
  ./rms_sample	    # RMS sample
  ./rmsauth_sample	# auth sample
  ```
