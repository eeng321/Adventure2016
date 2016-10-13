SETUP:
1. To get vagrant up and running use the command: vagrant up 

2. From there you will see the vagrant machine booting up and installing all libraries (takes some time).

3. Once complete you should see the restServer is running. You can now use postman to get/post to your restServer (localhost:8080)

NOTE: Need VM provider


FILE STRUCTURE:
Files are saved under /vagrant for the box.

Vagrant is sharing your local adventure2016 folder. So if you delete anything in /vagrant it will delete it from your local folder.  

DESTROY:
1. If you wish to suspend the box use vagrant suspend 

2. To completely destroy the box and all its content use vagrant destroy 

3. Delete the build directory in adventure2016

NOTE 1 :If the restServer is still running you will not be able to use vagrant destroy. 
	  
        Use vagrant ssh to ssh and stop the process and then use vagrant destroy.
	  
		If you cannot ssh using vagrant ssh, use any ssh client: 127.0.0.1:2222 
	  
	    Username:vagrant password:vagrant 
	  
	  




 