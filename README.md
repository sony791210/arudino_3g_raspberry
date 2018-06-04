# arudino_3g_raspberry
## Introduce 
1.Use ardino to collect data ,then send data by SIM360(3g) http.</br>
2.raspberry to get data ,input it to database or send it to ur phone by Line.</br>

簡單說明利用ardino收集資，透過3g模組將資料傳回中心，利用raspberry接收資料，傳入DB中或用line傳入</br>

## machine
A-1. Arudino</br>
A-2. SIM5360</br>
A-3. battery</br>

![image](https://github.com/sony791210/arudino_3g_raspberry/raw/master/picture/SIM.jpg)

B-1. Raspberry pi</br>
B-2. Router</br>

# First Arduino
準備 SIM5360模組板</br>
將Aruino 程式放入，一共有4組code (A1_Setup,A2_Loop,SIM5360_Lib,X56360_test)，其資料夾名稱為X5360_test</br>
If arduino can't sent data ,use the battery for SIM module</br> 
And u need the antenna to sent</br>
If all fail , to check the delay time use slowly </br>
如果跑不動記得用電池驅動SIM模組</br>
記得要裝天線</br>
如果真的還跑不動,檢查延遲時間增加多一點,看看是否能跑</br>
### x5630_test
//arduino RXpin 2 compare SIM TX</br>
//arduino Txpin 3 compare SIM RX</br>


//IP is ur IP or DDNS ;</br>
String uploadServer = "IP" ;</br>

//test.php?aid=</br>
//在raspberry裡面有test.php的在接收資料，用aid=??在接收 </br>
String uploadPage = "/dbtest.php?aid=" ;</br>


### A2_Loop
//read data from Serial </br>
u can input any data to test send</br>

### SIM5360_Lib
use 80 port to send information</br>




# raspberry 
follow</br>
https://howtoraspberrypi.com/how-to-install-web-server-raspberry-pi-lamp/</br>
u need to install lamp</br>
linux </br>
apache</br>
mysql</br>
php</br>

## star with raspberry pi 
### apache2
//install apache2</br>
sudo apt install apache2</br>
//to change user ,pi is user name u can change</br>
sudo chown -R pi:www-data /var/www/html/</br>
sudo chmod -R 770 /var/www/html</br>
###  php
//install php</br>
sudo apt install php php-mbstring</br>

### Mysql
//install mysql</br>
sudo apt install mysql-server php-mysql</br>
// into mysql </br>
sudo mysql --user=root</br>
//then  very imporant</br>
DROP USER 'root'@'localhost';</br>
CREATE USER 'root'@'localhost' IDENTIFIED BY 'password';</br>
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost';</br>

### phpmyadmin
//install phpmyadmin to look data</br>
sudo apt install phpmyadmin</br>
//link the file to www</br>
sudo ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin</br>


## how to get data
//in raspberry  /var/www/html/ </br>
create file name</br>







# Router 路由器
To check ur router ,tcp 80 port is open for ur raspberry</br>
or ur can use DMZ ,but it is't a good idea</br>
確認你的80port對應你的raspberry</br>
如果不會用的話,可以用DMZ去raspberry,但是不建議使用</br>



