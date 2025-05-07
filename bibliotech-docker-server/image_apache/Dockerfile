FROM httpd:2.4

RUN apt update && apt install -y mc git g++ libcgicc-dev libcgicc-doc libcgicc3

COPY ./isft-httpd.conf /usr/local/apache2/conf/httpd.conf
COPY ./build-bibliotech.sh /usr/local/apache2/
RUN chmod +x build-bibliotech.sh
