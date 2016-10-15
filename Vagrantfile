# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "bento/ubuntu-16.04"
  config.vm.provision:shell, path:"bootstrap.sh"	
  config.vm.network "public_network"
  config.vm.network "forwarded_port", guest: 80, host: 8080

end
