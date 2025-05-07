# bibliotech-docker-server
An Apache docker file with cgi script support

To start the image and setting up Bibliotech to run: 

    1. docker-compose up -d --remove-orphans
    2. docker exec -it isft-apache /bin/bash
    3. Run the following shell script: ./build-bibliotech.sh

To access the server via browser: 

    localhost:9010

If any configuration must be changed, you have to take down the docker image with

"docker-compose down --remove-orphans" ,  edit the `isft-httpd.conf` and start again the image.

To additionally remove stopped containers and all unused images (not just pending ones), add the -a flag to the command:

    docker system prune -a
