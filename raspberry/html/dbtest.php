<?php


$servername="localhost";
$user="urID";
$password="urpassword";
$dbname="dbname";



$conn = mysqli_connect($servername, $user, $password,$dbname);


if(mysqli_connect_errno($conn))
{
     echo "GG fail";
}








$sqlword ="INSERT INTO test (test) VALUES (".$_GET['aid'].");";
mysqli_query($conn,$sqlword);
mysqli_close($conn);

	
		
?>
