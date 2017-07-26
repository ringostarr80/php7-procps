# php7-procps extension

## installation (Ubuntu 16.04)

### prerequisites
```shell
# install packages
sudo apt install make bc g++ php-dev procps libprocps4 libprocps4-dev

# isntall PHP-CPP
git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git
cd PHP-CPP
make
sudo make install
cd ..
rm -rf PHP-CPP
```

### download, install and test this extension.
```shell
git clone https://github.com/ringostarr80/php7-procps.git
cd php7-procps
make
sudo make install

sudo ln -s /etc/php/7.0/mods-available/procps.ini /etc/php/7.0/cli/conf.d/20-procps.ini
sudo ln -s /etc/php/7.0/mods-available/procps.ini /etc/php/7.0/cgi/conf.d/20-procps.ini # if you have cgi installed
sudo ln -s /etc/php/7.0/mods-available/procps.ini /etc/php/7.0/fpm/conf.d/20-procps.ini # if you have fpm installed

# if you use php7.0-fpm, run:
sudo service php7.0-fpm restart
# else for apache, lighttpd, nginx, run:
sudo service <apache, lighttpd or nginx> restart

# to test if the extension was installed successful, run:
php test.php
```
